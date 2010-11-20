/** monotonic_clock/src/test_monotonic_clock.c
 *
 *  By Thomas Habets <thomas@habets.pp.se> 2010
 *
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
int
main()
{
	printf("%f\n", clock_get_dbl());
	sleep(1);
	printf("%f\n", clock_get_dbl());

	return 0;
}
