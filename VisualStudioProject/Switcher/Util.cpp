#include "SDL_image.h"
#include "Util.h"
#include <iostream>

SDL_Surface * Util::LoadImage( const char * pFilename )
{
  SDL_Surface * surface;
  if((surface= IMG_Load(pFilename)) == NULL)
	{
	  std::cout << "IMG ERROR:" << IMG_GetError() << std::endl;
	  return NULL;
	}
  return surface;
}
