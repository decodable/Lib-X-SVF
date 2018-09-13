
#include "xsvf_file_host.h"
#include <fstream>

namespace codible
{
  XSVF_File_Host::XSVF_File_Host(const std::string &filename) 
    : XSVF_File_Host(std::ifstream(filename)) {
  }

  XSVF_File_Host::XSVF_File_Host(std::istream &&stream)
    : XSVF_File_Host(stream) {
  }

  XSVF_File_Host::XSVF_File_Host(std::istream &stream) 
    : p_stream(&stream) {
  }

  int XSVF_File_Host::setup() {
    return 0;
  }

  int XSVF_File_Host::shutdown() {
    return 0;
  }

  int XSVF_File_Host::sync() {
    return 0;
  }

  int XSVF_File_Host::getbyte() {
    return p_stream->get();
  }

  void *XSVF_File_Host::realloc(void *ptr, int size, enum libxsvf_mem which) {
    return std::realloc(ptr, size);
  }

  void XSVF_File_Host::report_tapstate() {
  }

  void XSVF_File_Host::report_status(const char *message) {
  }
}