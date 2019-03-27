#ifndef TEXT_HPP
#define TEXT_HPP
#include <string>

#ifndef FENIX_ENGINE_H
#include <os.h>
#include <graphic.h>
#include <game_component.h>
#endif

class Text : public Graphic {
protected:
	TTF_Font * font;
	std::string text;
	SDL_Color color;
	SDL_Renderer * renderer;
public:
	Text(const std::string, const Color&, int, SDL_Renderer *);

	void setText(std::string);
	virtual SDL_Texture * getTexture();

	
};
#endif
