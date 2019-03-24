#include <geometry.h>

Vector::Vector(): Vector(0.0, 0.0) {
}

Vector::Vector(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector::Vector(const Vector& point): Vector(point.x, point.y) {
}

Vector
Vector::operator+(const Vector& point) {
	return Vector(x + point.x, y + point.y);
}

Vector
Vector::operator-(const Vector& point) {
	return Vector(x - point.x, y - point.y);
}

Size::Size(): Size(0, 0) {
}

Size::Size(const Size& size) : Size(size.width, size.height) {
}

bool Size::operator==(const Size & other) {
	return (this->width == other.width) && (this->height == other.height);
}

Size::Size(int width, int height) {
	this->width = width;
	this->height = height;
}
