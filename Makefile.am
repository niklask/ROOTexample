## Process this file with automake to produce Makefile.in
#
# Author: Niklas Karlsson <nkarlsson@adlerplanetarium.org>
#

ACLOCAL_AMFLAGS = -I m4

SUBDIRS = root src

EXTRA_DIST = test/macro.C test/rootlogon.C

# extra clean target for Sun CC compiler and generated distribution tarball
clean-local:
	-rm -rf SunWS_cache
	-rm -rf *.tar.gz
