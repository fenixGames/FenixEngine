#include <fstream>

#include <SDL_image.h>

#include <graphics/sprite.hpp>
#include <exceptions.hpp>

Sprite::Sprite(std::string path_to_file, const Color& alpha, SDL_Renderer * renderer) :
	Sprite(path_to_file.c_str(), alpha, renderer) {
}

Sprite::Sprite(const char * path_to_file, const Color& alpha, SDL_Renderer * renderer) {
	std::ifstream file(path_to_file);
	SDL_Surface * image;

	if (!file.good())
		throw FileSystemError("Sprite do not found", path_to_file);

	image = IMG_Load(path_to_file);
	if (image == NULL) {
		std::string msg = "Could not load sprite ";
		msg += path_to_file;
		msg += " ";
		msg += IMG_GetError();
		throw SDLException(msg.c_str());
	}

	SDL_SetColorKey(image, SDL_TRUE, 
		SDL_MapRGB(image->format, alpha.red, alpha.green, alpha.blue));
	texture = SDL_CreateTextureFromSurface(renderer, image);
	if (texture == NULL) {
		std::string msg = "Could not optimize sprite ";
		msg += path_to_file;
		throw SDLException(msg.c_str());
	}
	SDL_FreeSurface(image);
}

Sprite::~Sprite()
{
	if (texture != NULL)
		SDL_DestroyTexture(texture);
}

SDL_Texture *
Sprite::getTexture() {
	return texture;
}

void
Sprite::setAlpha(uint8_t alpha) {
	SDL_SetTextureAlphaMod(this->texture, alpha);
}

void
Sprite::setColorMod(const Color& colorMod) {
	SDL_SetTextureColorMod(this->texture, colorMod.red, colorMod.green, colorMod.blue);
}

void
Sprite::setBlendingMode(SDL_BlendMode mode) {
	SDL_SetTextureBlendMode(this->texture, mode);
}
