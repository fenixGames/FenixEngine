#include <graphics/graphic.hpp>

Color::Color(uint8_t red, uint8_t green, uint8_t blue) {
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Color::Color(uint32_t rgb) :
	Color((rgb & 0xFF0000) >> 16, (rgb & 0x00FF00) >> 8, rgb & 0x0000FF) {
}