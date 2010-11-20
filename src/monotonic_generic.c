/** monotonic_clock/src/monotonic_generic.c
 *
 *  By Thomas Habets <thomas@habets.pp.se> 2010
 *
 * No native method, just call the fallback
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include"monotonic_clock.h"

const char* monotonic_clock_name      = "generic";

/**
 * return 1 if clock is actually monotonic, otherwise return 0
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

/* ---- Emacs Variables ----
 * Local Variables:
 * c-basic-offset: 8
 * indent-tabs-mode: nil
 * End:
 */
