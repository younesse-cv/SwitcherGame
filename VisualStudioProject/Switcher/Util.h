#ifndef _UTIL_H_
#define _UTIL_H_

#include "SDL.h"

class Util
{
public:
  static SDL_Surface * LoadImage( const char * pFilename );
};

#endif