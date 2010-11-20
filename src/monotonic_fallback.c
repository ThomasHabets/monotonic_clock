/** monotonic_clock/src/monotonic_generic.c
 *
 *  By Thomas Habets <thomas@habets.pp.se> 2010
 *
 * get clock from gettimeofday() as if it were monotonic
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<sys/time.h>

#include"monotonic_clock.h"

/**
 *
 */
double
clock_get_dbl_fallback()
{
#if HAVE_GETTIMEOFDAY
	{
		struct timeval tv;
		if (0 == gettimeofday(&tv, NULL)) {
			return tv.tv_sec + tv.tv_usec / 1000000.0;
		}
		if (/* DEBUG */ 0) {
			fprintf(stderr,
				"gettimeofday(): %s\n",
				strerror(errno));
		}
	}
#endif
			
	return (double)time(0);
}

/* ---- Emacs Variables ----
 * Local Variables:
 * c-basic-offset: 8
 * indent-tabs-mode: nil
 * End:
 */
