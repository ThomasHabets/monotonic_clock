# -*- Autoconf -*-
# monotonic_clock/configure.ac
#

AC_PREREQ(2.61)
AC_INIT([monotonic_clock], [0.01], [thomas@habets.pp.se])
AC_CONFIG_AUX_DIR([config])
AM_INIT_AUTOMAKE
AM_MAINTAINER_MODE
AC_CONFIG_SRCDIR([src/monotonic_clock.c])
AC_CONFIG_HEADER(config.h)

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_RANLIB

# Checks for libraries.


AC_SUBST([AM_CFLAGS])
AC_SUBST([AM_LDFLAGS])

# Checks for header files.
AC_HEADER_STDC
#AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
#AC_HEADER_TIME
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T

EL_CLOCK_MONOTONIC

# Output
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT

echo "
  $PACKAGE_NAME version $PACKAGE_VERSION
  Prefix.........: $prefix
  Debug Build....: $debug
  C Compiler.....: $CC $CFLAGS $CPPFLAGS
  Linker.........: $LD $LDFLAGS $LIBS
"
