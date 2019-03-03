/**
 * Defines the viewport class needed to print on the screen.
 */

#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP
#include <mutex>
#include <list>

#include <physics/geometry.hpp>
#include <nodes/node.hpp>
#include <os.hpp>

/**
 * The viewport class is a representation of a "camera", it can be moved as
 * it were a node on the scene, but it contains no surface to print.
 * 
 * It prints on the given viewport everything that it is contained in the
 * rectangle defined as the printable viewport.
 */
class Viewport {
private:
	bool isNodePrintable(BasicNode *);
	void setViewport(const SDL_Rect);
	void setRenderer(SDL_Renderer *);
protected:
	SDL_Rect viewport;
	SDL_Renderer * renderer;

	std::mutex mtx;
public:
	Viewport(const SDL_Rect, SDL_Renderer *);
	Viewport(const Point&, const Size&, SDL_Renderer *);
	Viewport(const Viewport&);

	void renderNodes(std::list<BasicNode *> *);
};
#endif
