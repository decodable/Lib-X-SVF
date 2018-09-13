#ifndef CODIBLE_XSVF_PLAYER_H_
#define CODIBLE_XSVF_PLAYER_H_

#include "xsvf_player_base.h"

namespace codible
{
  class XSVF_Player : public XSVF_Player_Base
  {
  public:
    XSVF_Player(XSVF_Host &h);
    virtual int do_play();
  };

  class SVF_Player : public XSVF_Player_Base
  {
  public:
    SVF_Player(XSVF_Host &h);
    virtual int do_play();
  };

} // namespace codible

#endif // CODIBLE_XSVF_PLAYER_H_
