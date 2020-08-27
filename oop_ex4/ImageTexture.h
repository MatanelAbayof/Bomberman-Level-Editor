#pragma once
//---- include section ------
#include <SFML/Graphics.hpp>
#include <string>

//---- using section --------
using std::string;
using sf::Color;
using sf::Texture;
using sf::FloatRect;
using sf::RenderWindow;
using sf::Vector2f;
using sf::Sprite;

/*
 * ImageTexture class
 */
class ImageTexture
{
public:
	// constructors
	ImageTexture();
	ImageTexture(const Color &color);
	ImageTexture(Texture &texture);
	// load mode options
	enum LoadMode {
		TEXTURE, COLOR
	};
	// get load mode
	LoadMode getLoadMode() const;
	// get texture
	Texture &getTexture() const;
	// set texture
	void setTexture(Texture &texture);
	// get color
	Color getColor() const;
	// set color
	void setColor(const Color &color);
	// draw
	void draw(RenderWindow &window, const FloatRect &bound);
	// convert to string
	virtual string toString() const;
private:
	// load mode of image texture 
	LoadMode m_loadMode;
	// image texture
	Texture *m_texture;
	// color of image
	Color m_color;
};

