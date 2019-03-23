/**
 * Defines the viewport class needed to print on the screen.
 */

#ifndef VIEWPORT_HPP
#define VIEWPORT_HPP
#include <list>

#ifndef FENIX_ENGINE_H
#include <geometry.h>
#include <node.h>
#include <os.h>
#endif

/**
 * The viewport class is a representation of a "camera", it can be moved as
 * it were a node on the scene, but it contains no surface to print.
 * 
 * It prints on the given viewport everything that it is contained in the
 * rectangle defined as the printable viewport.
 */
class Viewport {
private:
	/** Checks whether a Node is visible inside the viewport.
	 * \param node The node to check if it is printable.
	 *
	 * \return If the node is inside the viewport's limits.
	 */
	bool isNodePrintable(BasicNode *);

	/** Sets the limits of the viewport.
	 * \param limits The limits of the viewport.
	 */
	void setViewport(const SDL_Rect);

	/** Sets the renderer to process the viewport.
	 * \param renderer The renderer used to print the viewport.
	 */
	void setRenderer(SDL_Renderer *);
protected:
	SDL_Rect viewport; // <* The viewport's limits
	SDL_Renderer * renderer; // <* The renderer to draw the viewport on screen.

	/** Starts rendering nodes that are visible.
	 * \param nodeList The list of nodes that belongs to the scene.
	 */
	void renderNodes(std::list<BasicNode *> *nodeList);

public:
	std::list<BasicNode *> nodes; // <* The list of nodes belonging to the
				      //    scene.
	/** Initializes the viewport using its limits and the renderer.
	 * \param limits The limits of the viewport.
	 * \param renderer The renderer to draw the viewport.
	 */
	Viewport(const SDL_Rect limits, SDL_Renderer *renderer);
	
	/** Initializes the viewport using its limits and the renderer.
	 * \param upperLeft The upper left starting point of the viewport.
	 * \param size The width and height of the viewport.
	 * \param renderer The renderer to draw the viewport.
	 */
	Viewport(const Point& upperLeft, const Size& size, SDL_Renderer *renderer);

	/** Copies a viewport.
	 * \param viewport The viewport to copy.
	 */
	Viewport(const Viewport& viewport);

	/** Renders all nodes on the viewport.
	 */
	void render();
};
#endif
