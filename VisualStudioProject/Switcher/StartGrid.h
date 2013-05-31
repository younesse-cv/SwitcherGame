#ifndef _START_GRID_H_
#define _START_GRID_H_

#include "GridState.h"

class StartGrid : public GridState
{
public:
  void Enter();
	void Exit() ;
	
	void HandleEvents(Grid * grid);
	void Update(Grid* grid);
	void Draw(Grid* grid);



  // Singleton pattern
  static StartGrid* Instance()
  {
    return &m_StartGrid;
  }

protected:
  static StartGrid m_StartGrid;
	StartGrid() {}
};

#endif