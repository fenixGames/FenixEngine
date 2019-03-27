#include <graphic.h>

Color::Color(uint8_t red, uint8_t green, uint8_t blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Color::Color(uint32_t rgb) :
	Color((rgb & 0xFF0000) >> 16, (rgb & 0x00FF00) >> 8, rgb & 0x0000FF) {
}

const uint32_t
Color::getColorAsInt() const {
	uint32_t color;

	color = this->red;
	color <<= 8;

	color += this->green;
	color <<= 8;

	color += this->blue;
	return color;
}

DEFINE_GET_TYPE(Graphic)