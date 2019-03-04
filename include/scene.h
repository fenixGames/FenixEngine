/**
 * Scene management.
 */

#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>

#ifndef FENIX_ENGINE_H
#include <node.h>
#include <event_handler.h>
#include <viewport.h>
#include <os.h>
#endif

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
