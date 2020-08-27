#pragma once
//---- include section ------
#include <string>
#include "View.h"

//---- using section --------
using std::string;
using sf::Text;
using sf::Font;
using sf::Color;

/*
 * TextView class
 */
class TextView : public View
{
public:
	// constructor
	TextView(RenderWindow &window, const string &text = "");
	// get text
	string getText() const;
	// set text
	void setText(const string &text);
	// set text colot
	void setTextColor(const Color &textColor);
	// get text color
	Color getTextColor() const;
	// set font
	void setFont(const Font &font);
	// draw
	virtual void draw();
	// convert to string
	virtual string toString() const;
protected:
	// update components
	virtual void updateComponents();
private:
	// text object
	Text m_text;
	// text color
	Color m_textColor;
};

