/** monotonic_clock/src/monotonic_mach.c
 *
 *  By Thomas Habets <thomas@habets.se> 2010
 *
 * Adapted from:
 * http://code-factor.blogspot.com/2009/11/monotonic-timers.html
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif


#include<stdio.h>
#include<mach/mach_time.h>

#ifdef HAVE_STDINT_H
#include<stdint.h>
#endif

#ifdef HAVE_INTTYPES_H
#include<inttypes.h>
#endif

#ifdef HAVE_SYS_STDINT_H
#include<sys/int_types.h>
#endif

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
 *
 */
double
clock_get_dbl()
{
        return (double)clock_get_uint64(0) / 1000000000.0;
}


/**
 * FIXME: Make thread safe on initial call.
 */
uint64_t
clock_get_uint64(int flags)
{
        uint64_t t = mach_absolute_time();
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
        return t * scaling_factor;
}

/* ---- Emacs Variables ----
 * Local Variables:
 * c-basic-offset: 8
 * indent-tabs-mode: nil
 * End:
 */
