#pragma once
//---- include section ------
#include <string>
#include "ImageView.h"
#include "CharacterButton.h"

//---- using section --------
using std::string;

/*
 * CharacterView class
 */
class CharacterView :
	public ImageView
{
public:
	// constructor
	CharacterView(RenderWindow &window);
	// set character
	void setCharacter(Character character);
	// get character
	Character getCharacter() const;
	// convert to string
	virtual string toString() const;
private:
	// character
	Character m_character;
	// redeclaring scope of base class functions in private section of derived class
	using ImageView::setImage;
	using ImageView::getImage;
};

