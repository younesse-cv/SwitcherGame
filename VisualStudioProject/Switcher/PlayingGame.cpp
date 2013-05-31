#include <iostream>

#include "SDL.h"
#include "Game.h"
#include "PlayingGame.h"

void PlayingGame::Enter(Engine* pEngine)
{
  std::cout << "Creating New Game!" << std::endl;
  m_pGame = new Game(pEngine->GetScreen());  
  std::cout << "PlayingGame Init successful\n";
}

void PlayingGame::Exit(Engine* pEngine)
{
  std::cout << "PlayingGame Exit Successful\n";
}

void PlayingGame::Pause()
{
  std::cout << "PlayingGame Paused\n";
}

void PlayingGame::Resume()
{
  std::cout << "PlayingGame::Resume\n";
}

void PlayingGame::HandleEvents(Engine * pEngine)
{
  // Depending on Game state, input/events might modify the global engine state
  // so pass in the engine
  m_pGame->HandleEvents(pEngine);
}

void PlayingGame::Update(Engine * pEngine)
{
  //std::cout << "PlayingGame::Update\n";

  // The Game updating itself may update the global Game's state
  // so pass in the game ptr.
  m_pGame->Update(pEngine);
}

void PlayingGame::Draw(Engine * pEngine)
{
  // drawing the Game won't modify the engine state,
  // and the game will draw to one of it's own screens.
  m_pGame->Draw();
}

PlayingGame PlayingGame::m_PlayingGame;