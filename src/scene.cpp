#include <scene.hpp>

Scene::Scene()
{
	finished = false;
	evController = NULL;
}

bool
Scene::isFinished()
{
	return finished;
}

void
Scene::draw()
{
	std::list<Viewport *>::iterator itViews;
	SDL_Rect stretchRect;

	SDL_RenderClear(this->renderer);
	for (itViews = this->viewports.begin(); itViews != this->viewports.end(); itViews++) {
		(*itViews)->renderNodes(&this->nodes);
	}
	SDL_RenderPresent(this->renderer);
}

void
Scene::addViewport(Viewport *viewport) {
	this->viewports.push_back(viewport);
}

void
Scene::setRenderer(SDL_Renderer * renderer) {
	this->renderer = renderer;
}