#ifndef _GAME_H_
#define _GAME_H_

#include "State.h"
#include "SDL.h"
#include "Sprite.h"

#include <vector>

class Engine
{
public:
	
	Engine();
	void Start(const char* title, int width, int height, bool fullscreen);

	void ChangeState(State<Engine>* state); // new function
	void PushState(State<Engine>* state); // new function
	void PopState();

	void Update();
	
	void EngineLoop();
	void Draw();
	void CleanUp();
	bool Running();
	void HandleEvents();
	void Quit();
	
	SDL_Surface * GetScreen() {		return m_pCanvas; }
	
private:
	std::vector<State<Engine>*> states;
	SDL_Surface* m_pCanvas;
	bool m_bRunning;
	bool m_bFullscreen;
	
};

#endif