# monotonic_clock/Makefile.am

include $(top_srcdir)/Makefile.am.common

ACLOCAL_AMFLAGS=-I m4
AM_CFLAGS=-I$(top_srcdir)/include @AM_CFLAGS@

# library
lib_LTLIBRARIES=libmonotonic_clock.la
libmonotonic_clock_la_SOURCES=src/monotonic_common.c
libmonotonic_clock_la_LDFLAGS = -version-info 0:0:0 -release 0.01

library_includedir=$(includedir)
library_include_HEADERS = include/monotonic_clock.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libmonotonic_clock.pc

if SRC_MONOTONIC_CLOCK
libmonotonic_clock_la_SOURCES += src/monotonic_clock.c
endif

if SRC_MONOTONIC_MACH
libmonotonic_clock_la_SOURCES += src/monotonic_mach.c
endif

if SRC_MONOTONIC_GENERIC
libmonotonic_clock_la_SOURCES += src/monotonic_generic.c
endif

# test program
noinst_PROGRAMS=test_monotonic_clock

test_monotonic_clock_SOURCES=src/test_monotonic_clock.c
test_monotonic_clock_LDADD=libmonotonic_clock.la

mrproper: maintainer-clean
	rm -f aclocal.m4 configure.scan depcomp missing install-sh config.h.in
	rm -fr config.guess config.sub build-stamp autom4te.cache/
	rm -f Makefile.in configure autoscan*.log debian/debhelper.log
	rm -f debian/substvars debian/files
	rm -fr debian/tmp
	rm -f config/install-sh config/missing config/depcomp
	rm -fr config m4 libltdl
