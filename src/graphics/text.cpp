#include <graphics/text.hpp>
#include <exceptions.hpp>

Text::Text(
	const std::string fontName, 
	const Color &color, 
	int size,
	SDL_Renderer * renderer) {
	this->font = TTF_OpenFont(fontName.c_str(), size);
	if (this->font == NULL)
		throw SDLTTFException("fontname not found");

	this->color.r = color.red;
	this->color.g = color.green;
	this->color.b = color.blue;

	this->renderer = renderer;
}

void Text::setText(std::string text) {
	this->text = text;
}

SDL_Texture * Text::getTexture()
{
	SDL_Surface * textSurface = TTF_RenderText_Solid(this->font, 
		this->text.c_str(), this->color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(this->renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return texture;
}
