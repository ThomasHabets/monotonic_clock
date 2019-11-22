/** monotonic_clock/src/monotonic_common.c
 *
 *  By Thomas Habets <thomas@habets.se> 2010
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<sys/time.h>

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

/**
 *
 */
uint64_t
clock_get_uint64_fallback(int flags)
{
#if HAVE_GETTIMEOFDAY
        struct timeval tv;
        if (0 == gettimeofday(&tv, NULL)) {
                return (uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;
        }
        if (/* DEBUG */ 0) {
                fprintf(stderr, "gettimeofday(): %s\n", strerror(errno));
        }
#endif
        return (uint64_t)time(0);
}

/**
 * get clock from gettimeofday() or even time() as if it were monotonic
 */
double
clock_get_dbl_fallback()
{
#if HAVE_GETTIMEOFDAY
        struct timeval tv;
        if (0 == gettimeofday(&tv, NULL)) {
                return tv.tv_sec + tv.tv_usec / 1000000.0;
        }
        if (/* DEBUG */ 0) {
                fprintf(stderr, "gettimeofday(): %s\n", strerror(errno));
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
