#pragma once
//---- include section ------
#include <SFML/Graphics.hpp>
#include <string>

//---- using section --------
using std::string;
using sf::Color;
using sf::RenderWindow;
using sf::FloatRect;

/*
 * Border class
 */
class Border
{
public:
	// constructor (0 - no border)
	Border(const Color &color = Color(), int size = 0);
	// set color
	void setColor(const Color &color);
	// get color
	Color getColor() const;
	// set size
	void setSize(int size);
	// get size
	int getSize() const;
	// draw
	void draw(RenderWindow &window, const FloatRect &bound);
	// convert to string
	virtual string toString() const;
private:
	// color
	Color m_color;
	// size (thickness of border)
	int m_size;
};

