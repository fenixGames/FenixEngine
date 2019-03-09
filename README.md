# FenixEngine
A C++ Engine based on SLD2 for Open Source Operating Systems

## Requirements
The library `libSDL2` must be installed on the system.

### Windows

#### libSDL2, libSDL2-Image and libSDL2-TTF
Please, download libSDL2 using the following links:
https://www.libsdl.org/release/SDL2-devel-2.0.9-VC.zip

Use the following link to download the image support for libSDL
`https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.4-VC.zip`

Use the following link to download the TTF support for libSDL
`https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-devel-2.0.15-VC.zip`

Extract the include folder into C:\devel\include\SDL2 and the
lib folder into C:\devel\lib.

The structure of the devel folder should look like
```
C:\devel\include\SDL2
C:\devel\lib\x86
C:\devel\lib\x64
```

### FreeBSD
#### libSDL2 and libSDL2-Image

Run `pkg install -y sdl2 sdl2_image sdl2_ttf`, done.

### Linux
Use you favorite package manager to install them.


## Building the project
### Linux / Unix
To build the project, run `CMake` on the current directory with the desired
Generator.

On FreeBSD, a Makefile to be used with bmake(1) is going to be generated.
On Linux, a GNUMakefile is going to be generated to be used with gmake(1).

### Windows
Open the solution (`FenixEngine.sln`) and build it for the desired architecture
and either Debug or Release.


