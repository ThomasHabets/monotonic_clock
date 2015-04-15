/** monotonic_clock/src/monotonic_generic.c
 *
 *  By Thomas Habets <thomas@habets.se> 2010
 *
 * No native method, just call the fallback.
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

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

const char* monotonic_clock_name      = "generic";

/**
 * return 1 if clock is actually monotonic, otherwise return 0.
 */
int
monotonic_clock_is_monotonic()
{
        return 0;
}

/**
 *
 */
double
clock_get_dbl()
{
        return clock_get_dbl_fallback();
}

/**
 *
 */
uint64_t
clock_get_uint64(int flags)
{
        return clock_get_uint64_fallback(flags);
}

/* ---- Emacs Variables ----
 * Local Variables:
 * c-basic-offset: 8
 * indent-tabs-mode: nil
 * End:
 */
