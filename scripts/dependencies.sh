#!/bin/sh

# Get the type of system and download dependencies as source code.
MACHINE_TYPE=$(uname -o)

fetch_build_and_install()
{
	url=${1}
	package=${2}

	cd /tmp
	wget "${url}/${package}"
	cd -
	tar -xvf "/tmp/${package}"
	cd "${package%%.tar.gz}"
	./configure && make all install
}

get_sdl_lib()
{
	fetch_build_and_install \
		https://www.libsdl.org/release \
		SDL2-2.0.9.tar.gz
}

get_sdl_ttf_lib()
{
	fetch_build_and_install \
		https://www.libsdl.org/projects/SDL_ttf/release \
		SDL2_ttf-2.0.15.tar.gz
}

get_sdl_image_lib()
{
	fetch_build_and_install \
		https://www.libsdl.org/projects/SDL_image/release \
		SDL2_image-2.0.4.tar.gz
}

if [ "${MACHINE_TYPE}" = "GNU/Linux" ] ;then
	if ! command -v wget ; then
		echo "++ Please install wget and retry!" >&2
	fi
	set -e
	case "$(lsb_release -is)" in
		Ubuntu)
			apt-get install libts-dev pkg-config 
		;;
	esac
	if [ "$(pkg-config --modversion sdl2)" != "2.0.9" ]; then
		get_sdl_lib
	fi
	if [ "$(pkg-config --modversion SDL2_ttf)" != "2.0.15" ]; then
		get_sdl_ttf_lib
	fi
	if [ "$(pkg-config --modversion SDL2_image)" != "2.0.4" ]; then
		get_sdl_image_lib
	fi
fi
