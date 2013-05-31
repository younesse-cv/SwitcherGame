#include <iostream>

#include "SDL.h"
#include "Game.h"
#include "StartGrid.h"


void StartGrid::Enter()
{
  std::cout << "StartGrid Init successful\n";
}

void StartGrid::Exit()
{
  std::cout << "StartGrid Exit Successful\n";
}

void StartGrid::HandleEvents(Grid* game)
{
  
}

void StartGrid::Update(Grid* game)
{
  
}

void StartGrid::Draw(Grid* game)
{
  //std::cout << "StartGrid::Draw\n";
}

StartGrid StartGrid::m_StartGrid;

