/** Defines Operating System specific variables and macros
 */

#ifndef OS_HPP
#ifdef WIN32
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#endif
#endif
