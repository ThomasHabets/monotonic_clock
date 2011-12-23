# -*- Autoconf -*-
# monotonic_clock/configure.ac
#

AC_PREREQ(2.61)
AC_INIT([monotonic_clock], [0.01], [thomas@habets.se])
AC_CONFIG_AUX_DIR([config])

AM_INIT_AUTOMAKE([foreign subdir-objects])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES])
AM_MAINTAINER_MODE

LT_INIT([dlopen])
#LT_CONFIG_LTDL_DIR([libltdl])
AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_SRCDIR([src/monotonic_clock.c])
AC_CONFIG_HEADER(config.h)

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for library functions.
AC_CHECK_FUNCS([gettimeofday mach_absolute_time])

# enable subst
AC_SUBST([AM_CFLAGS])
AC_SUBST([AM_LDFLAGS])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([time.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
#AC_HEADER_TIME
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T

EL_CLOCK_MONOTONIC

AS_IF(
      [test x$ac_cv_have_clock_monotonic = xyes],
      [portability=getclock],

      [test x$ac_cv_func_mach_absolute_time = xyes],
      [portability=mach],

      [portability=generic]
)

# AS_CASE([$portability],
AM_CONDITIONAL([SRC_MONOTONIC_CLOCK],   [test x$portability = xgetclock])
AM_CONDITIONAL([SRC_MONOTONIC_MACH],    [test x$portability = xmach])
AM_CONDITIONAL([SRC_MONOTONIC_GENERIC], [test x$portability = xgeneric])

AC_SUBST([SRC_MONOTONIC_CLOCK])
AC_SUBST([SRC_MONOTONIC_MACH])
AC_SUBST([SRC_MONOTONIC_GENERIC])

# Output
AC_CONFIG_FILES([Makefile libmonotonic_clock.pc])
AC_OUTPUT

echo "
  $PACKAGE_NAME version $PACKAGE_VERSION
  Prefix.........: $prefix
  Debug Build....: $debug
  C Compiler.....: $CC $CFLAGS $CPPFLAGS
  Linker.........: $LD $LDFLAGS $LIBS
"
