/** Defines a graphical resource which is a colored rectangle.
 */

#ifndef FILLED_RECT_H

#ifndef FENIX_ENGINE_H
#include <graphic.h>
#endif

class FilledRect : Graphic
{
	SDL_Texture * texture; // <* The texture loaded from the image.

public:
	/** Creates a filled rectangle.
	 * \param color The color to fill the rectangle with.
	 * \param size The size of the surface to create.
	 * \param alpha The alpha channel to set.
	 */
	FilledRect(const Color& color, const Size& size, int alpha, SDL_Renderer *renderer);

	/** Frees the resources.
	 */
	~FilledRect();

	/** Retrieves the texture from the object.
	 * \return Returns the texture loaded and renderized.
	 */
	virtual SDL_Texture * getTexture();

	/** Retrieves the size of the graphical resource used to paint it.
	 *
	 * \return The size of the graphical resource.
	 */
	virtual Size& getSize();

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

#endif // FILLED_RECT_H