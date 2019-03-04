/**
 * Configuration and prototypes regarding the window.
 */

#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <list>

#include <scene.h>
#include <os.h>

class Window {
private:
	SDL_Surface * windowSurface;
	SDL_Renderer * renderer;
	SDL_Window * window;
	std::list<Scene *>::iterator itScenes;

	Scene * getCurrentScene();
	
public:
	std::list<Scene *> sceneList;

	Window(int, int, std::string);
	~Window();

	void draw(void);
	void start();

	const SDL_Surface * getSurface() const;
	SDL_Renderer * getRenderer();
};
#endif
