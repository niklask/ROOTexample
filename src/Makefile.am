INCLUDES = -I$(top_srcdir)
SOURCES = rootExample.cpp

EXT_INCLUDES = $(ROOT_INCLUDE)

bin_includedir=$(includedir)/root
bin_PROGRAMS = rootExample

rootExample_SOURCES = $(SOURCES)
rootExample_LDADD = ../root/libROOTobject.la $(ROOT_LIBS)
rootExample_CXXFLAGS = $(EXT_INCLUDES)

