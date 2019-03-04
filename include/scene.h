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

/** Creates a scene to be processed in the screen
 *
 * A scene has a method to be drawn and expects the user to implement the
 * behavior of the scene by some means. Whenever the scene is completed by the
 * user, the variable `finished` should be set to `true`.
 */
class Scene {
protected:
	bool finished; // <* Indicates if the scene is finished.

	std::list<Viewport *> viewports; // <* The viewports to be separately
					 //     processed.
	SDL_Renderer * renderer; // The renderer used to process the scene.
public:
	EventController * evController; // <* The event controller used for the
					//    events occurring on the screen.
	std::list<BasicNode *> nodes; // <* The list of nodes belonging to the
				      //    scene.

	/** Initializes the scene.
	 */
	Scene();

	/** Indicates if the scene is finished.
	 * \return Whether the scene is done.
	 */
	bool isFinished(void);

	/** Draws the scene on the screen.
	 */
	void draw();

	/** Adds a Viewport to the scene to process different nodes.
	 * \param viewport The viewport used to process different nodes
	 *                 on the screen.
	 */
	void addViewport(Viewport *viewport);

	/** Sets the renderer for the scene for processing.
	 * \param renderer The renderer used to render the scene.
	 */
	void setRenderer(SDL_Renderer*);
};

#endif
