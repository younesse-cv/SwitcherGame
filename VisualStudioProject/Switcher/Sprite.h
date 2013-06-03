#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SDL.h>
#include "TextureMgr.h"

class Sprite
{
public:
  // Create a Sprite which is a rect extracted from the texture passed in, at the coordinates x, y and of width w and height h
  Sprite(HTEXTURE texture, int x, int y, int width, int height);
  
  ~Sprite(){}; // don't need to call SDL_FreeSurface because we reference Surfaces stored elsewhere.

  // Anchor point is 0,0 by default. Anchor point used for positioning sprite.
  void SetAnchorPoint(int x, int y);

  // Blit the sprite to the specified surface at the coords x, y
  bool Blit(SDL_Surface* dest, int x, int y);

  // Update the sprite's texture ( and texture rect )
  void SetTexture(HTEXTURE texture, int x, int y, int w, int h);

  int GetX();
  int GetY();

  int GetW();
  int GetH();

private:
  int iAnchorX;
  int iAnchorY;
  int iX;
  int iY;
  int iWidth;
  int iHeight;

  
  HTEXTURE texture;
};

#endif