#include "Sprite.h"
#include "SDL_image.h"
#include <iostream>


/*********************************************************/
/*********************************************************/
Sprite::Sprite(HTEXTURE tex, int x, int y, int w, int h):
  iAnchorX(0),
  iAnchorY(0),
  iX(x),
  iY(y),
  iWidth(w),
  iHeight(h),
  texture(tex)
{
  std::cout << "Creating new sprite ! " << x << ", " << y << "\n";
}
/*********************************************************/
// Anchor point is 0,0 by default. Anchor point used for positioning sprite.
void Sprite::SetAnchorPoint(int x, int y)
{
  iAnchorX = x;
  iAnchorY = y;
}
/*********************************************************/
// Blit the sprite to the specified surface at the coords x, y
bool Sprite::Blit(SDL_Surface* dest, int x, int y)
{
  if(dest == NULL)
  {
    return false;
  }

  // Calculate what x,y coord on dest, given Anchor point of sprite.
  int iDestX = x-iAnchorX;
  int iDestY = y-iAnchorY;

  SDL_Rect rDest;
  rDest.x = iDestX;
  rDest.y = iDestY;

  SDL_Rect rSrc;
  rSrc.x = iX;
  rSrc.y = iY;
  rSrc.w = iWidth;
  rSrc.h = iHeight;

  SDL_BlitSurface(texture, &rSrc, dest, &rDest);

  return true;
};


void Sprite::SetTexture(HTEXTURE t, int x, int y, int w, int h)
{
  texture = t;
  iX = x;
  iY = y;
  iWidth = w;
  iHeight = h;
}