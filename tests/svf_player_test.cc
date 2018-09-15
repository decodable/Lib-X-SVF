#include "xsvf_file_host.h"
#include "xsvf_player.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sstream>

using codible::SVF_Player;
using ::testing::_;

class SVF_Host_Mock : public codible::XSVF_File_Host
{
public:
  SVF_Host_Mock(std::istream &stream) : XSVF_File_Host(stream) {
  }

  MOCK_METHOD3(udelay, void(long usecs, int tms, long num_tck));
  MOCK_METHOD5(pulse_tck, int(int tms, int tdi, int tdo, int rmask, int sync));
  MOCK_METHOD0(pulse_sck, void());
  MOCK_METHOD1(set_trst, void(int v));
  MOCK_METHOD1(set_frequency, int(int v));
  MOCK_METHOD1(report_device, void(unsigned long idcode));
  MOCK_METHOD3(report_error, void(const char *file, int line, const char *message));
};

TEST(SVF, NOPE) {
  std::istringstream str("// NOPE");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  // just like a RESET case
  // at the end, player will walk to state RESET
  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(6);
  player.play();
}

TEST(SVF, RESET) {
  std::istringstream str("STATE RESET;");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  // just like a NOPE case
  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(6);
  player.play();
}

TEST(SVF, IDLE) {
  std::istringstream str("STATE IDLE;");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(9);
  EXPECT_CALL(host, pulse_tck(0, -1, -1, 0, 0)).Times(1);
  player.play();
}

TEST(SVF, FREQUENCY_1000) {
  std::istringstream str("FREQUENCY 1.00E+03 HZ;");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  EXPECT_CALL(host, set_frequency(1000));
  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(6);
  player.play();
}

TEST(DISABLED_SVF, FREQUENCY_Quarter) {
  std::istringstream str("FREQUENCY 0.25 HZ;");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  EXPECT_CALL(host, set_frequency(25));
  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(6);
  player.play();
}

TEST(SVF, FREQUENCY_1_100) {
  std::istringstream str("FREQUENCY 1.0E-2 HZ;");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  // one - "SVF Syntax Error:"
  // one - "FREQUENCY 1.0E-2 HZ"
  EXPECT_CALL(host, report_error(_, _, _)).Times(2);
  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(6);
  player.play();
}

TEST(SVF, FREQUENCY_100) {
  std::istringstream str("FREQUENCY 0.100E+03 HZ;");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  EXPECT_CALL(host, set_frequency(100));
  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(6);
  player.play();
}

TEST(SVF, RUNTEST_1000_TCK) {
  std::istringstream str("RUNTEST 1E03 TCK;");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  EXPECT_CALL(host, udelay(0, 0, 1000));

  // just like case of IDLE
  // RUNTEST will walk to state IDLE before delay
  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(9);
  EXPECT_CALL(host, pulse_tck(0, -1, -1, 0, 0)).Times(1);
  player.play();
}

TEST(SVF, RUNTEST_1_SEC) {
  std::istringstream str("RUNTEST 1 SEC;");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  EXPECT_CALL(host, udelay(1000000, 0, 0));
  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(9);
  EXPECT_CALL(host, pulse_tck(0, -1, -1, 0, 0)).Times(1);
  player.play();
}

TEST(SVF, RUNTEST_1_MS) {
  std::istringstream str("RUNTEST 0.100000 SEC;");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  EXPECT_CALL(host, udelay(100000, 0, 0));
  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(9);
  EXPECT_CALL(host, pulse_tck(0, -1, -1, 0, 0)).Times(1);
  player.play();
}
