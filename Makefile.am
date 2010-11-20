# monotonic_clock/Makefile.am

include $(top_srcdir)/Makefile.am.common

SUBDIRS=src #doc

mrproper: maintainer-clean
	rm -f aclocal.m4 configure.scan depcomp missing install-sh config.h.in
	rm -fr config.guess config.sub build-stamp autom4te.cache/
	rm -f Makefile.in configure autoscan*.log debian/debhelper.log
	rm -f debian/substvars debian/files
	rm -fr debian/tmp
	rm -f config/install-sh config/missing config/depcomp
