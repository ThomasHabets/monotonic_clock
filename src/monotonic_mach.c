/** monotonic_clock/src/monotonic_mach.c
 *
 *  By Thomas Habets <thomas@habets.pp.se> 2010
 *
 * Adapted from:
 * http://code-factor.blogspot.com/2009/11/monotonic-timers.html
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include<stdio.h>
#include<mach/mach_time.h>

#include"monotonic_clock.h"

const char* monotonic_clock_name = "mach_absolute_time";

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
        uint64_t time = mach_absolute_time();
        static double scaling_factor = 0;

        if (scaling_factor == 0) {
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
                scaling_factor = (double)info.numer / (double)info.denom;
	}
        return (double)time * scaling_factor / 1000000000.0;
}

/* ---- Emacs Variables ----
 * Local Variables:
 * c-basic-offset: 8
 * indent-tabs-mode: nil
 * End:
 */
