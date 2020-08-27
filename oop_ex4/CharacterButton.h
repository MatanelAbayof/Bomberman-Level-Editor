#pragma once
//---- include section ------
#include <string>
#include "ImageButton.h"
//---- using section --------
using std::string;


// enum of character
enum Character {
	ROBOT, GUARD, EXIT_DOOR, ROCK, WALL, EMPTY
};

/*
 * CharacterButton class
 */
class CharacterButton :
	public ImageButton
{
public:
	// constructor
	CharacterButton(RenderWindow &window);	
	// set character
	void setCharacter(Character character);
	// get character
	Character getCharacter() const;
	// convert to string
	virtual string toString() const;
private:
	// character
	Character m_character;
};