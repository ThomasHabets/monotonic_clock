/** monotonic_clock/src/monotonic_win32.c
 *
 *  By Thomas Habets <thomas@habets.se> 2010
 *
 * Copied from:
 * http://code-factor.blogspot.com/2009/11/monotonic-timers.html
 *
 * Untested
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <Windows.h>
#include <stdio.h>

#ifdef HAVE_STDINT_H
#include<stdint.h>
#endif

#ifdef HAVE_INTTYPES_H
#include<inttypes.h>
#endif

#ifdef HAVE_SYS_STDINT_H
#include<sys/int_types.h>
#endif

const char* monotonic_clock_name      = "QueryPerformanceCounter";

/**
 * return 1 if clock is actually monotonic, otherwise return 0
 */
int
monotonic_clock_is_monotonic()
{
        LARGE_INTEGER t;
        if (!QueryPerformanceCounter(&t)
            || !QueryPerformanceFrequency(&t)) {
                return 0;
        }
        return 1;
}

/**
 * FIXME: Make thread safe with inital call.
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
	static uint64_t scale_factor;

	LARGE_INTEGER count;
	BOOL ret = QueryPerformanceCounter(&count);

	if (ret == 0) {
                return clock_get_uint64_fallback(flags);
	}

	if (scale_factor == 0) {
		LARGE_INTEGER frequency;
		BOOL ret = QueryPerformanceFrequency(&frequency);
		if(ret == 0) {
			if (/* DEBUG */ 0) {
				fprintf(stderr, "QueryPerformanceFrequency");
			}
			return clock_get_uint64_fallback(flags);
		}
		scale_factor = frequency.QuadPart;
	}

	return count.QuadPart / scale_factor;
}

/* ---- Emacs Variables ----
 * Local Variables:
 * c-basic-offset: 8
 * indent-tabs-mode: nil
 * End:
 */
