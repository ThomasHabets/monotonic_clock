/** monotonic_clock/src/test_monotonic_clock.c
 *
 *  By Thomas Habets <thomas@habets.se> 2010
 *
 */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include<stdio.h>
#include<string.h>
#include<errno.h>
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
int
main()
{
        printf("Name: %s, is monotonic: %s\n",
               monotonic_clock_name,
               monotonic_clock_is_monotonic() ? "yes" : "no");
        printf("start: %f\n", clock_get_dbl());
        sleep(1);
        printf("stop:  %f\n", clock_get_dbl());

        return 0;
}

/* ---- Emacs Variables ----
 * Local Variables:
 * c-basic-offset: 8
 * indent-tabs-mode: nil
 * End:
 */
