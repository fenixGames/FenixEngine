/**
 * Scene management.
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>

#include <nodes/node.h>
#include <events/event_handler.h>
#include <viewport.h>
#include <os.h>

class Scene {
protected:
	bool finished;

	std::list<Viewport *> viewports;
	SDL_Renderer * renderer;
public:
	EventController * evController;
	std::list<BasicNode *> nodes;

	Scene();
	bool isFinished(void);
	void draw();

	void addViewport(Viewport *);
	void setRenderer(SDL_Renderer*);
};

#endif
