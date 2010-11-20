# monotonic_clock/src/Makefile.am

include $(top_srcdir)/Makefile.am.common

#lib_LTLIBRARIES = libsomething-1.0.la
#libsomething_1_0_la_SOURCES = something.cc
#library_include_HEADERS = something/foo.h something/bar.h

AM_CFLAGS=-I$(top_srcdir)/include @AM_CFLAGS@


bin_PROGRAMS=test_monotonic_clock

test_monotonic_clock_SOURCES=test_monotonic_clock.c monotonic_common.c

if HAVE_CLOCK_MONOTONIC
test_monotonic_clock_SOURCES += monotonic_clock.c
else
test_monotonic_clock_SOURCES += monotonic_generic.c
endif
