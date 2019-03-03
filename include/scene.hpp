/**
 * Scene management.
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>

#include <nodes/node.hpp>
#include <events/event_handler.hpp>
#include <viewport.hpp>
#include <os.hpp>

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
