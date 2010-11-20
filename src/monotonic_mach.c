/** monotonic_clock/src/monotonic_win32.c
 *
 *  By Thomas Habets <thomas@habets.pp.se> 2010
 *
 * Copied from:
 * http://code-factor.blogspot.com/2009/11/monotonic-timers.html
 *
 * Untested
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include"monotonic_clock.h"

const char* monotonic_clock_name      = "mach_absolute_time";

/**
 * return 1 if clock is actually monotonic, otherwise return 0
 */
int
monotonic_clock_is_monotonic()
{
        mach_timebase_info_data_t info;
        if (mach_timebase_info(&info)) {
                return 0;
        }
        return 1;
}

/**
 * FIXME: thread safe?
 */
double
clock_get_dbl()
{
	u64 time = mach_absolute_time();
	static u64 scaling_factor = 0;

	if (!scaling_factor) {
		mach_timebase_info_data_t info;
		kern_return_t ret = mach_timebase_info(&info);
		if (ret != 0) {
			if (/* DEBUG */ 0) {
				fprintf(stderr,
					"mach_timebase_info() failed: %d",
					ret);
			}

			return clock_get_dbl_fallback();
		}
		scaling_factor = info.numer / info.denom;
	}
	return time * scaling_factor;
}

/* ---- Emacs Variables ----
 * Local Variables:
 * c-basic-offset: 8
 * indent-tabs-mode: nil
 * End:
 */
