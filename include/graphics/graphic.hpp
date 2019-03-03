/**
 * Class defining abstract graphical interfaces.
 */

#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include <os.hpp>

/** API of a graphic resource, which should return a texture to render.
*/
class Graphic {
public:
	/** Retrieves the texture from the resource.
	 *
	 * \return The texture of the object.
	 *\note It MUST be overriden by classes extending this one.
	 */
	virtual SDL_Texture * getTexture() = 0;
};

/** Representation of a RGB color.
 */
class Color {
public:
	uint8_t red; // <* The red component of the color.
	uint8_t blue; // <* The blue component of the color.
	uint8_t green; // <* The green component of the color.

	/** Creates a Color using the 3 components separately.
	 *
	 * \param red The component red of the color.
	 * \param green The component green of the color.
	 * \param blue The component blue of the color.
	 */
	Color(uint8_t red, uint8_t green, uint8_t blue);

	/** Creates a color using the components combined in one int.
	 * \param color The RGB representation of the color.
	 */
	Color(uint32_t rgb);
};
#endif
