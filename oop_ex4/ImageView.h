#pragma once
//---- include section ------
#include "View.h"
#include <string>

//---- using section --------
using std::string;

class ImageView :
	public View
{
public:
	//constructor
	ImageView(RenderWindow &window, const ImageTexture &imageTexture = ImageTexture());
	//set image
	void setImage(const ImageTexture &imageTexture);
	//get image
	ImageTexture getImage() const;
	// draw in window
	virtual void draw();
	// convert to string
	virtual string toString() const;
private:
	// image texture
	ImageTexture m_image;
};

