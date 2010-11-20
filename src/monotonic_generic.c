/** monotonic_clock/src/monotonic_generic.c
 *
 *  By Thomas Habets <thomas@habets.pp.se> 2010
 *
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include"monotonic_clock.h"

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
