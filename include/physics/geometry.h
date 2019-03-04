/**
 * Classes and functions related to geometry, such as Points, vectors
 * and operations between them.
 */

#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#include <atomic>

/**
 * Representation of a point on the world.
 */
class Point {
public:
	float x;
	float y;

	// Start point (0, 0)
	Point();

	/** Representation of the point on the coordinates (x, y)
	 * \param x The X coordinate on the Euclidian system.
	 * \param y The Y coordinate on the Euclidian system.
	 */
	Point(float x , float y);

	/**
	 * Creates a point representation from other point.
	 */
	Point(const Point& point);

	/** Addition of two point calculated as x1 + x2, y1 + y2
	 *\param point The point to add to the current one.
	 */
	Point operator + (const Point&);

	/** Substraction of two point calculated as x1 - x2, y1 - y2
	 * \param point The point to substract to the current one.
	 */
	Point operator - (const Point&);
};

/** Representation of a size in 2D width x height.
*/
class Size {
public:
	int width; // <* width of the object.
	int height; // <* heigth of the object.

	/** Initialization of an object of size 0 x 0
	 */
	Size();

	/** Initialization of an object of size width x height
	 * \param width The width of the object.
	 * \param height The height of the object.
	*/
	Size(int width, int height);

	/** Creates a size object from another one.
	 * \param size The size of the object.
	 */
	Size(const Size& size);

	/** Comparison of two size objects. 
	 * Only true if both width and height are the same.
	 *
	 * \param other The other size to compare.
	 */
	bool operator== (const Size& other);
};
#endif