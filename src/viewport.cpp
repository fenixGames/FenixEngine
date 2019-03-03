#include <viewport.hpp>
#include <string.h>

Viewport::Viewport(const Viewport& viewPort) :
	Viewport(viewPort.viewport, viewPort.renderer) {
}

Viewport::Viewport(
	const Point& viewportPosition,
	const Size& viewportSize,
	SDL_Renderer * renderer) {
	SDL_Rect viewport;

	viewport.x = (int)viewportPosition.x;
	viewport.y = (int)viewportPosition.y;
	viewport.w = viewportSize.width;
	viewport.h = viewportSize.height;

	this->setViewport(viewport);
	this->setRenderer(renderer);
}

Viewport::Viewport(
	const SDL_Rect viewport,
	SDL_Renderer * renderer) {
	
	this->setViewport(viewport);
	this->setRenderer(renderer);
}

void
Viewport::setViewport(const SDL_Rect rect) {
	memcpy(&this->viewport, &rect, sizeof(SDL_Rect));
}

void
Viewport::setRenderer(SDL_Renderer * renderer) {
	this->renderer = renderer;
}

void
Viewport::renderNodes(std::list<BasicNode *> *listNodes) {
	std::list<BasicNode *>::iterator itNodes;
	SDL_Rect stretchRect;

	SDL_RenderSetViewport(this->renderer, &this->viewport);
	
	for (itNodes = listNodes->begin(); itNodes != listNodes->end(); itNodes++) {
		(*itNodes)->fillDimentions(&stretchRect);

		stretchRect.x -= this->viewport.x;
		stretchRect.y -= this->viewport.y;

		if (this->isNodePrintable(*itNodes)) {
			SDL_Texture * texture = (*itNodes)->getTexture();
			
			if (texture != NULL)
				SDL_RenderCopy(renderer, texture, NULL, &stretchRect);
			this->renderNodes((*itNodes)->getChildren());
			(*itNodes)->act();
		}
	}
	
}

bool
Viewport::isNodePrintable(BasicNode * node) {
	SDL_Rect rect;
	SDL_Point nodePosition;

	node->fillDimentions(&rect);
	nodePosition.x = rect.x;
	nodePosition.y = rect.y;

	memcpy(&rect, &this->viewport, sizeof(SDL_Rect));
	rect.x = (int)this->viewport.x;
	rect.y = (int)this->viewport.y;

	return SDL_PointInRect(&nodePosition, &rect);
}
