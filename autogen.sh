#!/bin/sh

rm -f config.cache acconfig.h

if [ ! -d config ]; then
		echo "mkdir config"
		mkdir config
fi
if [ ! -d m4 ]; then
		echo "mkdir m4"
		mkdir m4
fi
autoreconf --force --install -I config && exit 0

exit 1
