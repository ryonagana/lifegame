#!/bin/env bash

args="$1"


help(){
	echo "build-linux.sh [build|clean]"
	echo "build  - compiles game"
	echo "clean  - delete all objects files and binaries" 
	exit 0

}

build(){
	if command -v make &> /dev/null; then
		echo "make: found"
	else
		echo "Error: make  not found. please install it:  apt install build-essentials"
		exit 1
	fi

	NCORES=$(nproc  --ignore=1)


	make -f Makefile.linux -j"$NCORES"

	if [ $? -eq 0 ]; then
		echo "Lifegame Build Sucess!"
	else
		echo "Build Failed" >&2
		exit 1
	fi
}


case "$args" in
	
	build)
		build
	;;
	help)
		help
	;;
	clean)
		make -f Makefile.linux clean
	;;
	*)
		build

esac



