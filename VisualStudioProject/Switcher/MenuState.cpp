#include <iostream>

#include "SDL.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "defines.h"
#include "Util.h"

MenuState MenuState::m_MenuState;

void MenuState::Enter()
{
  menuSprite = NULL;
  
  SDL_Surface * img = Util::LoadImage(image_filenames[STARTMENU]);
  if(img)
  {
    menuSprite = new Sprite(img, 0, 0, img.w, img.h);
  }

  std::cout << "MenuState Init successful\n";
}

void MenuState::Exit()
{
  std::cout << "MenuState Exit Successful\n";
}

void MenuState::Pause()
{
  std::cout << "MenuState Paused\n";
}

void MenuState::Resume()
{
  std::cout << "MenuState::Resume\n";
}

void MenuState::HandleEvents(Game* game)
{
  SDL_Event event;

  if(SDL_PollEvent(&event))
  {
    switch(event.type)
	  {
	    case SDL_QUIT:
		    game->Quit();
		    break;
      case SDL_MOUSEMOTION:
        std::cout << "Mouse moved by (" << event.motion.xrel << "," << event.motion.yrel << ") to (" << 
                        event.motion.x << "," << event.motion.y << ")\n";
        break;
      case SDL_MOUSEBUTTONDOWN:
        std::cout << "Mouse button pressed at (" << event.button.x << "," << event.button.y << ")\n";
        game->ChangeState(PlayState::Instance());
        break;
      default:
        break;
	  }
  }
}

void MenuState::Update(Game* game)
{

}

void MenuState::Draw(Game* game)
{
  //Sprite::Blit(game->GetScreen(), menuSprite, 0, 0); // we will write

  SDL_Flip(game->GetScreen());
}

