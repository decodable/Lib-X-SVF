#ifndef CODIBLE_XSVF_FILE_HOST_H_
#define CODIBLE_XSVF_FILE_HOST_H_

#include "xsvf_host.h"
#include <istream>
#include <string>

namespace codible
{
  class XSVF_File_Host : public XSVF_Host
  {
  public:
    XSVF_File_Host(const std::string &filename);
    XSVF_File_Host(std::istream &&stream);
    XSVF_File_Host(std::istream &stream);

    virtual int setup();
    virtual int shutdown();
    virtual int sync();
    virtual int getbyte();
    virtual void *realloc(void *ptr, int size, enum libxsvf_mem which);
    virtual void report_tapstate();
    virtual void report_status(const char *message);

  private:
    std::istream *p_stream;
  };
} // namespace codible

#endif // CODIBLE_XSVF_FILE_HOST_H_
