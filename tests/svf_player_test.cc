#include "xsvf_file_host.h"
#include "xsvf_player.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sstream>

using codible::SVF_Player;

class SVF_Host_Mock : public codible::XSVF_File_Host
{
public:
  SVF_Host_Mock(const std::string &filename) : XSVF_File_Host(filename) {
  }

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

TEST(SVF, FREQUENCY) {
  ASSERT_TRUE(true);

  std::istringstream str("FREQUENCY 1.00E+07 HZ;");
  SVF_Host_Mock host(str);
  SVF_Player player(host);

  EXPECT_CALL(host, set_frequency(10000000));
  EXPECT_CALL(host, pulse_tck(1, -1, -1, 0, 0)).Times(6);
  player.play();
}
