# check for clock_gettime(CLOCK_MONOTONIC, ...)
AC_DEFUN([EL_CLOCK_MONOTONIC],
[
    AC_SEARCH_LIBS([clock_gettime], [rt])
    AC_CACHE_CHECK([for CLOCK_MONOTONIC],
                   ac_cv_have_clock_monotonic,
                   [
                     AC_TRY_RUN(
                                [
#ifdef HAVE_TIME_H
#include <time.h>
#endif
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
int main() {
struct timespec ts;
return !!clock_gettime(CLOCK_MONOTONIC, &ts);
}
                                ],
                        [ ac_cv_have_clock_monotonic="yes"],
                        [ ac_cv_have_clock_monotonic="no" ]
                          )
])
AM_CONDITIONAL(HAVE_CLOCK_MONOTONIC, test x$ac_cv_have_clock_monotonic = xyes)
if test x$ac_cv_have_clock_monotonic = xyes; then
   AC_DEFINE([HAVE_CLOCK_MONOTONIC], 1, [Have symbol CLOCK_MONOTONIC])
fi
])
