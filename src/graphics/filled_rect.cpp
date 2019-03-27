#include <SDL2/SDL.h>

#include <filled_rect.h>
#include <exceptions.h>


FilledRect::FilledRect(
	const Color& color,
	const Size& size, 
	uint32_t alpha, 
	SDL_Renderer *renderer)
{
	SDL_Surface * surface = SDL_CreateRGBSurface(0, size.width, size.height, 
		32, 0, 0, 0, 0);
	if (surface == NULL)
		throw SDLException("Unable to create the RGB surface");

	uint32_t intColor = color.getColorAsInt();
	SDL_FillRect(surface, NULL, intColor);
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}


FilledRect::~FilledRect()
{
	if (this->texture != NULL)
		SDL_DestroyTexture(this->texture);
}

SDL_Texture *
FilledRect::getTexture() {
	return texture;
}

void
FilledRect::setAlpha(uint8_t alpha) {
	SDL_SetTextureAlphaMod(this->texture, alpha);
}

void
FilledRect::setColorMod(const Color& colorMod) {
	SDL_SetTextureColorMod(this->texture, colorMod.red, colorMod.green, colorMod.blue);
}

void
FilledRect::setBlendingMode(SDL_BlendMode mode) {
	SDL_SetTextureBlendMode(this->texture, mode);
}

const Size&
FilledRect::getSize() {
	Size size;

	if (SDL_QueryTexture(this->texture, NULL, NULL, &size.width, &size.height) < 0)
		throw SDLException("Could not query texture");
	return size;
}

