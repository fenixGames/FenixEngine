#ifndef TEXT_HPP
#define TEXT_HPP
#include <string>

#include <os.hpp>
#include <graphics/graphic.hpp>

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
