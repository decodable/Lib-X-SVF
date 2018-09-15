#ifndef CODIBLE_XSVF_PLAYER_BASE_H_
#define CODIBLE_XSVF_PLAYER_BASE_H_

#include "xsvf_host.h"
extern "C" {
#include "libxsvf.h"
}

#include <string>

namespace codible
{
  class XSVF_Player_Base
  {
  public:
    XSVF_Player_Base(XSVF_Host &h);

    virtual int play() = 0;

    virtual ~XSVF_Player_Base() {}

  protected:
    libxsvf_host host_;
  };
} // codible

#endif // CODIBLE_XSVF_PLAYER_BASE_H_
