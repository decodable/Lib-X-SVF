#include "xsvf_player.h"

namespace codible
{
  XSVF_Player::XSVF_Player(XSVF_Host &h) : XSVF_Player_Base(h) {
  }

  int XSVF_Player::do_play() {
    return libxsvf_play(&host, LIBXSVF_MODE_XSVF);
  }

  SVF_Player::SVF_Player(XSVF_Host &h) : XSVF_Player_Base(h) {
  }

  int SVF_Player::do_play() {
    return libxsvf_play(&host, LIBXSVF_MODE_SVF);
  }
} // namespace codible

