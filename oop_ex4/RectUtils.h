#pragma once
//---- include section ------
#include <SFML/Graphics.hpp>

//---- using section --------
using sf::Vector2f;
using sf::FloatRect;
using sf::IntRect;

/*
 * RectUtils namespace
 */
namespace RectUtils {
	// create float rectangle
	FloatRect createFloatRect(const Vector2f &position, int width, int height);
	// create integer rectangle
	IntRect createIntRect(const FloatRect &floatRect);
	// check if rect1 in rect2
	bool rectInAnother(const FloatRect &rect1, const FloatRect &rect2);
}
