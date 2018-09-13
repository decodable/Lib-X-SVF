#include "xsvf_player_base.h"

#include <fstream>

#define GET_XSVF_HOST(h) (static_cast<XSVF_Host *>((h)->user_data))

namespace codible
{
	static inline int h_setup(struct libxsvf_host *h) {
    return GET_XSVF_HOST(h)->setup();
  }

	static inline int h_shutdown(struct libxsvf_host *h) {
    return GET_XSVF_HOST(h)->shutdown();
  }

	static inline void h_udelay(struct libxsvf_host *h, long usecs, int tms, long num_tck) {
    return GET_XSVF_HOST(h)->udelay(usecs, tms, num_tck);
  }

	static inline int h_getbyte(struct libxsvf_host *h) {
    return GET_XSVF_HOST(h)->getbyte();
  }

	static inline int h_sync(struct libxsvf_host *h) {
    return GET_XSVF_HOST(h)->sync();
  }

	static inline int h_pulse_tck(struct libxsvf_host *h, int tms, int tdi, int tdo, int rmask, int sync) {
    return GET_XSVF_HOST(h)->pulse_tck(tms, tdi, tdo, rmask, sync);
  }

	static inline void h_pulse_sck(struct libxsvf_host *h) {
    return GET_XSVF_HOST(h)->pulse_sck();
  }

	static inline void h_set_trst(struct libxsvf_host *h, int v) {
    return GET_XSVF_HOST(h)->set_trst(v);
  }

	static inline int h_set_frequency(struct libxsvf_host *h, int v) {
    return GET_XSVF_HOST(h)->set_frequency(v);
  }

	static inline void h_report_tapstate(struct libxsvf_host *h) {
    return GET_XSVF_HOST(h)->report_tapstate();
  }

	static inline void h_report_device(struct libxsvf_host *h, unsigned long idcode) {
    return GET_XSVF_HOST(h)->report_device(idcode);
  }

	static inline void h_report_status(struct libxsvf_host *h, const char *message) {
    return GET_XSVF_HOST(h)->report_status(message);
  }

	static inline void h_report_error(struct libxsvf_host *h, const char *file, int line, const char *message) {
    return GET_XSVF_HOST(h)->report_error(file, line, message);
  }

	static inline void *h_realloc(struct libxsvf_host *h, void *ptr, int size, enum libxsvf_mem which) {
    return GET_XSVF_HOST(h)->realloc(ptr, size, which);
  }

  XSVF_Player_Base::XSVF_Player_Base(XSVF_Host &h) {
    host.udelay = h_udelay;
    host.setup = h_setup;
    host.shutdown = h_shutdown;
    host.sync = h_sync;
    host.getbyte = h_getbyte;
    host.pulse_tck = h_pulse_tck;
    host.pulse_sck = h_pulse_sck;
    host.set_trst = h_set_trst;
    host.set_frequency = h_set_frequency;
    host.report_tapstate = h_report_tapstate;
    host.report_device = h_report_device;
    host.report_status = h_report_status;
    host.report_error = h_report_error;
    host.realloc = h_realloc;
    host.user_data = &h;
  }

  int XSVF_Player_Base::play() {
    return do_play();
  }
}

