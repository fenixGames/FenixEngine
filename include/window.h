/**
 * Configuration and prototypes regarding the window.
 */

#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include <list>

#ifndef FENIX_ENGINE_H
#include <scene.h>
#include <os.h>
#endif

/** The main window of the application.
 *
 * Only a main window is thought to be displayed at the same time.
 */
class Window {
private:
	SDL_Surface * windowSurface; // <* The printable surface of the game.
	SDL_Renderer * renderer; // <* The renderer to print nodes.
	SDL_Window * window; // <* The main window of the application.
	std::list<Scene *>::iterator itScenes; // <* The iterator for the list
					       //    of scenes to be processed.

	Scene * getCurrentScene(); // <* Retrieves the first scene NOT finished.
	
public:
	std::list<Scene *> sceneList; // <* The list of scenes of the game.

	/** Initializes the main window of the game.
	 *  \param width The width of the window.
	 *  \param height The height of the window.
	 *  \param title The title to be shown on the title bar.
	 */
	Window(int, int, std::string);

	/** Frees memory.
	 *
	 * It should happen when the application is finished.
	 */
	~Window();

	/** Draws the game on the screen.
	 */
	void draw(void);

	/** Starts processing all the scenes.
	 */
	void start();

	/** Gets the printable surface of the screen.
	 * \return The surface returned by SDL2.
	 */
	const SDL_Surface * getSurface() const;

	/** Gets a generated renderer.
	 * \return The renderer used for the main screen.
	 */
	SDL_Renderer * getRenderer();
};
#endif
