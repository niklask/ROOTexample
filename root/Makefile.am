## Process this file with automake to produce Makefile.in
#
# Author: Niklas Karlsson <nkarlsson@physics.umn.edu>
#

BUILT_SOURCES = root_dict.cpp root_dict.h

rootcommondir = $(includedir)/root

rootcommon_HEADERS = \
	ROOTObject.h

rootcommon_SOURCE = \
	ROOTObject.cpp

rootcommon_CLASSDEFS = \
	ROOTObject.h

EXTRA_DIST = LinkDef.h

LIB_VERSION = 1:0:0

library_includedir = $(includedir)/root

EXT_INCLUDES = $(ROOT_INCLUDE)

ROOTCINT_FLAGS = -D__extension__="" -D__attribute__\\\(X\\\)="" -D__const=const -D__restrict="" -D__signed=signed -D__volatile=volatile -D__BEGIN_DECLS= -D__END_DECLS= -D__THROW=

MYCFLAGS = -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS

root_dict.cpp: $(rootcommon_CLASSDEFS)
	$(ROOTCINT_BIN) -v -f $@ -c -p -I$(top_srcdir)/root $^ LinkDef.h

lib_LTLIBRARIES = libROOTobject.la
libROOTobject_la_SOURCES = $(rootcommon_HEADERS) $(rootcommon_SOURCE)
nodist_libROOTobject_la_SOURCES = $(BUILT_SOURCES)
libROOTobject_la_CXXFLAGS = $(MYCFLAGS) $(EXT_INCLUDES)
libROOTobject_la_LDFLAGS = -version-info $(LIB_VERSION)

#
# The Mac OS 10.x libtool build .dylib files by default (the .so files built
# using -module cannot be linked to) and ROOT CINT requires the dynamic
# library to be a .so and not a .dylib file to load it using
# gSystem->Load(...). A work-around for this is to make a symbolic link
# from libROOTobject.dylib to libROOTobject.so. For that we use two hooks;
# one for install to create the link and one uninstall to delete it. 
#
if DARWIN
install-exec-hook:
	cd $(DESTDIR)$(libdir) && \
		rm -f libROOTobject.so && \
		$(LN_S) libROOTobject.dylib libROOTobject.so

uninstall-hook:
	cd $(DESTDIR)$(libdir) && \
		rm -f libROOTobject.so
endif

# make sure to delete generated code when with 'make clean'
clean-local:
	-rm -rf root_dict.h root_dict.cpp
