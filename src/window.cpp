#include <string>

#include <window.hpp>
#include <exceptions.hpp>
#include <SDL_image.h>
#include <SDL_ttf.h>

Window::Window(int width, int height, std::string title) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		throw SDLException("SDL Inititalization failed ");

	int imageFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
	if ((IMG_Init(imageFlags) & imageFlags) == 0) {
		std::string msg = "Image inititalization failed ";
		msg += IMG_GetError();
		throw SDLException(msg.c_str());
	}

	if (TTF_Init() < 0)
		throw SDLTTFException("TTF initialization failed");

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL)
		throw SDLException("Unable to create Window");

	windowSurface = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
		throw SDLImageException("Unable to create renderer");

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void
Window::draw() {
	SDL_FillRect(windowSurface, NULL,
		SDL_MapRGB(windowSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
}

void
Window::start() {
	Scene * currentScene;
	itScenes = sceneList.begin();

	while ((currentScene = getCurrentScene()) != NULL) {
		currentScene->draw();
		if (currentScene->evController != NULL)
			currentScene->evController->handleEvents();

		SDL_Delay(20);
	}
}

Scene *
Window::getCurrentScene()
{
	while (itScenes != sceneList.end() && (*itScenes)->isFinished())
		itScenes++;
	if (itScenes != sceneList.end())
		return *itScenes;
	return NULL;
}

const SDL_Surface *
Window::getSurface() const {
	return windowSurface;
}

SDL_Renderer *
Window::getRenderer() {
	return renderer;
}