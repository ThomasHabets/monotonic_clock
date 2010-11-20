
AC_CACHE_CHECK([for CLOCK_MONOTONIC],
                                  ac_cv_have_clock_monotonic, [
                                  AC_TRY_RUN(
                                        [
#include <time.h>
int main() {
struct timespec ts;
exit(!!clock_gettime(CLOCK_MONOTONIC, &ts));
}
                ],
                        [ ac_cv_have_clock_monotonic="yes" ],
                        [ ac_cv_have_clock_monotonic="no" ]
                          )
])
AM_CONDITIONAL(HAVE_CLOCK_MONOTONIC, test x$ac_cv_have_CLOCK_MONOTONIC = xyes)
