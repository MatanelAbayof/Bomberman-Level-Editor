//---- include section ------
#include "Border.h"

//---- using section --------
using sf::RectangleShape;
using sf::Vector2f;

Border::Border(const Color &color, int size)
	: m_color(color)
{
	setSize(size);
}

void Border::setColor(const Color &color)
{
	m_color = color;
}

Color Border::getColor() const
{
	return m_color;
}

void Border::setSize(int size)
{
	if (size < 0)
		throw string("Size of border (=" + std::to_string(size) + ") must be a natural number");
	m_size = size;
}

int Border::getSize() const
{
	return m_size;
}

void Border::draw(RenderWindow &window, const FloatRect &bounds)
{
	if ((m_size > 0)&&(bounds.width > 0)&&(bounds.height > 0)&&(m_color != Color::Transparent)) {
		RectangleShape borderShape;
		borderShape.setPosition(Vector2f(bounds.left + m_size, bounds.top + m_size));
		borderShape.setSize(Vector2f(bounds.width - 2*m_size, bounds.height - 2*m_size));
		borderShape.setFillColor(Color::Transparent);
		borderShape.setOutlineThickness((float) m_size);
		borderShape.setOutlineColor(m_color);
		window.draw(borderShape);
	}	
}

string Border::toString() const
{
	return "Border: color=" + std::to_string(m_color.toInteger()) + ", size=" + std::to_string(m_size);
}
