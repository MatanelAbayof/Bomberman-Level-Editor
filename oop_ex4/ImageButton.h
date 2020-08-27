#pragma once
//---- include section ------
#include <string>
#include "VerticalLayout.h"
#include "ImageView.h"
#include "TextView.h"
//---- using section --------
using std::string;

/*
 * ImageButtom class
 */
class ImageButton :
	public VerticalLayout
{
public:
	//constractor
	ImageButton(RenderWindow &window, const ImageTexture &imageTexture = ImageTexture(), const string &text = "");
	// set image
	void setImage(const ImageTexture &imageView);
	// get image
	ImageTexture getImage() const;
	//set text
	void setText(const string &text);
	//get text
	string getText() const;
	// set text colot
	void setTextColor(const Color &textColor);
	// get text color
	Color getTextColor() const;
	// convert to string
	virtual string toString() const;
private:
	// image
	ImageView m_image;
	// text
	TextView m_text;
	// init components
	void initComponents();
	// redeclaring scope of base class functions in private section of derived class
	using VerticalLayout::addView;
	using VerticalLayout::removeView;
};

