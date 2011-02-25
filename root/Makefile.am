## Process this file with automake to produce Makefile.in
#
# Author: Niklas Karlsson <nkarlsson@physics.umn.edu>
#

rootcommondir = $(includedir)/root

rootcommon_HEADERS = \
	ROOTObject.h

rootcommon_SOURCE = \
	ROOTObject.cpp

rootcommon_CLASSDEFS = \
	ROOTObject.h

EXTRA_DIST = LinkDef.h

LIB_VERSION = 0:0:0

library_includedir = $(includedir)/root

EXT_INCLUDES = $(ROOT_INCLUDE)

ROOTCINT_FLAGS = -D__extension__="" -D__attribute__\\\(X\\\)="" -D__const=const -D__restrict="" -D__signed=signed -D__volatile=volatile -D__BEGIN_DECLS= -D__END_DECLS= -D__THROW=

MYCFLAGS = -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS

root_dict.cpp: $(rootcommon_CLASSDEFS)
	$(ROOTCINT_BIN) -v -f $@ -c -p -I$(top_srcdir)/root $^ LinkDef.h

lib_LTLIBRARIES = libROOTobject.la
libROOTobject_la_SOURCES = $(rootcommon_HEADERS) $(rootcommon_SOURCE) root_dict.cpp
nodist_libROOTobject_la_SOURCES = root_dict.cpp root_dict.h
libROOTobject_la_CXXFLAGS = $(MYCFLAGS) $(EXT_INCLUDES)
libROOTobject_la_LDFLAGS = -version-info $(LIB_VERSION)

# make sure to delete generated code when with 'make clean'
clean-local:
	-rm -rf root_dict.h root_dict.cpp
