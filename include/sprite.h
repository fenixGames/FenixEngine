/**
 * Class defining image loading for sprites
 */

#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <string>

#ifndef FENIX_ENGINE_H
#include <graphic.h>
#include <os.h>
#include <game_component.h>
#endif

/** Representation of a Sprite
 * A sprite is an image loaded on a game moving around.
 */
class Sprite : public Graphic {
protected:
	SDL_Texture * texture; // <* The texture loaded from the image.

public:
	/** Creates a sprite from an image.
	 * 
	 * \param path_to_sprite The path to the image to load.
	 * \param color The color to use as an alpha color.
	 * \param renderer The renderer used to generate the texture.
	 */
	Sprite(const char * path_to_sprite, const Color& color, SDL_Renderer *renderer);

	/** Creates a sprite from an image.
	 *
	 * \param path_to_sprite The path to the image to load.
	 * \param color The color to use as an alpha color.
	 * \param renderer The renderer used to generate the texture.
	 */
	Sprite(std::string path_to_sprite, const Color& color, SDL_Renderer * renderer);

	/** Frees resources from the sprite.
	 */
	~Sprite();

	/** Retrieves the texture from the object.
	 * \return Returns the texture loaded and renderized.
	 */
	virtual SDL_Texture * getTexture();

	/** Retrieves the size of the graphical resource used to paint it.
	 *
	 * \return The size of the graphical resource.
	 */
	virtual const Size& getSize();

	/** Sets the modification color to the texture.
	 * Alters a texture by setting a color to modify how it looks.
	 *
	 * \param color The color to modify the texture.
	 */
	void setColorMod(const Color& color);

	/** Sets the alpha channel for the texture.
	 * Applies transparency to the texture.
	 *
	 * \param alpha The value to set the alpha channel.
	 */
	void setAlpha(uint8_t);

	/** Sets the blending mode.
	 * \param blendMode The blending mode to set.
	 */
	void setBlendingMode(SDL_BlendMode blendMode);

};
#endif
