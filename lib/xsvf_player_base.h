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

    int play();

  protected:
    virtual int do_play() = 0;

    libxsvf_host host;
  };
} // codible

#endif // CODIBLE_XSVF_PLAYER_BASE_H_
