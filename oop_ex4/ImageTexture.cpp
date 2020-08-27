//---- include section ------
#include "ImageTexture.h"
#include "RectUtils.h"

//---- using section --------
using sf::RectangleShape;

ImageTexture::ImageTexture()
			: m_texture(nullptr)
{ 
	setColor(Color::Transparent);
}

ImageTexture::ImageTexture(const Color &color)
	: m_texture(nullptr)
{
	setColor(color);
}

ImageTexture::ImageTexture(Texture &texture)
	:	m_color(Color::Transparent)
{
	setTexture(texture);
}

ImageTexture::LoadMode ImageTexture::getLoadMode() const
{
	return m_loadMode;
}

Texture &ImageTexture::getTexture() const
{
	// check load mode
	if (m_loadMode != TEXTURE)
		throw string("Image not contains texture");
	return *m_texture;
}

void ImageTexture::setTexture(Texture &texture)
{
	// change load mode
	m_loadMode = TEXTURE;
	// set texture
	m_texture = &texture;
}

Color ImageTexture::getColor() const
{
	// check load mode
	if (m_loadMode != COLOR)
		throw string("Image not contains color");
	return m_color;
}

void ImageTexture::setColor(const Color &color)
{
	// change load mode
	m_loadMode = COLOR;
	// set color
	m_color = color;
}

void ImageTexture::draw(RenderWindow &window, const FloatRect &bound)
{
	if ((bound.width == 0) || (bound.height == 0))
		return;

	switch (m_loadMode)
	{
		case ImageTexture::TEXTURE: {
			Sprite sprint(*m_texture);
			sprint.setPosition(Vector2f(bound.left, bound.top));
			sprint.setScale(bound.width/m_texture->getSize().x, bound.height/m_texture->getSize().y);
			window.draw(sprint);
		} break;
		case ImageTexture::COLOR: {
			if (m_color != Color::Transparent) {
				RectangleShape rectShape;
				rectShape.setPosition(Vector2f(bound.left, bound.top));
				rectShape.setSize(Vector2f(bound.width, bound.height));
				rectShape.setFillColor(m_color);
				window.draw(rectShape);
			}			
		} break;
	}
}

string ImageTexture::toString() const
{
	string loadModeStr = (m_loadMode == COLOR) ? "Color" : "Texture";
	return "ImageTexture: loadMode=" + loadModeStr;
}
