# monotonic_clock/src/Makefile.am

include $(top_srcdir)/Makefile.am.common

#lib_LTLIBRARIES = libsomething-1.0.la
#libsomething_1_0_la_SOURCES = something.cc
#library_include_HEADERS = something/foo.h something/bar.h

AM_CFLAGS=-I$(top_srcdir)/include @AM_CFLAGS@

# library
noinst_LIBRARIES=libmonotonic_clock.a
libmonotonic_clock_a_SOURCES=monotonic_common.c

if HAVE_CLOCK_MONOTONIC
libmonotonic_clock_a_SOURCES += monotonic_clock.c
else
libmonotonic_clock_a_SOURCES += monotonic_generic.c
endif

# test program
noinst_PROGRAMS=test_monotonic_clock

test_monotonic_clock_SOURCES=test_monotonic_clock.c
test_monotonic_clock_LDADD=libmonotonic_clock.a
