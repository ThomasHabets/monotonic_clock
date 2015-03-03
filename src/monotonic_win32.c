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

#include <Windows.h>
#include <stdio.h>

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
 * FIXME: thread safe
 */
double
clock_get_dbl()
{
	static double scale_factor;

	LARGE_INTEGER count;
	BOOL ret = QueryPerformanceCounter(&count);

	if (ret == 0) {
                return clock_get_dbl_fallback();
	}

	if (scale_factor == 0.0) {
		LARGE_INTEGER frequency;
		BOOL ret = QueryPerformanceFrequency(&frequency);
		if(ret == 0) {
			if (/* DEBUG */ 0) {
				fprintf(stderr, "QueryPerformanceFrequency");
			}
			return clock_get_dbl_fallback();
		}
		scale_factor = 1.0 / frequency.QuadPart;
	}

	return count.QuadPart * scale_factor;
}

/* ---- Emacs Variables ----
 * Local Variables:
 * c-basic-offset: 8
 * indent-tabs-mode: nil
 * End:
 */
