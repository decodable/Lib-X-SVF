#ifndef CODIBLE_XSVF_HOST_H_
#define CODIBLE_XSVF_HOST_H_

extern "C" {
#include "libxsvf.h"
}

namespace codible
{
  class XSVF_Host
  {
  public:
    virtual int setup() = 0;
    virtual int shutdown() = 0;
    virtual void udelay(long usecs, int tms, long num_tck) = 0;
    virtual int getbyte() = 0;
    virtual int sync() = 0;
    virtual int pulse_tck(int tms, int tdi, int tdo, int rmask, int sync) = 0;
    virtual void pulse_sck() = 0;
    virtual void set_trst(int v) = 0;
    virtual int set_frequency(int v) = 0;
    virtual void report_tapstate() = 0;
    virtual void report_device(unsigned long idcode) = 0;
    virtual void report_status(const char *message) = 0;
    virtual void report_error(const char *file, int line, const char *message) = 0;
    virtual void *realloc(void *ptr, int size, enum libxsvf_mem which) = 0;

    virtual ~XSVF_Host() {}
  };
} // namespace codible

#endif // CODIBLE_XSVF_HOST_H_
