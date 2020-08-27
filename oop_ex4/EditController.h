#pragma once
//---- include section ------
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "LevelFileManager.h"
#include "CharacterButton.h"

//---- using section --------
using sf::RenderWindow;

/*
 * EditController class
 */
class EditController
{
public:
	// constructor
	EditController();
	// main function of controller
	void run();	
private:
	// edit option (select character or delete character)
	enum EditOption {
		SELECT_CHAR, DELETE_CHAR
	};
	// read new level size (width and height) from standard input
	void readLevelSize(RenderWindow &window, Board &board);
	// handle events
	void handleEvents(Board &board, LevelFileManager &lfm, EditOption &editOption, Character &selectCharacter);
	// handle menu events
	void handleMenuEvents(Board &board, LevelFileManager &lfm, EditOption &editOption, Character &selectCharacter);
	// handle character panel events
	void handleCharPanelEvents(Board &board, LevelFileManager &lfm, EditOption &editOption, Character &selectCharacter);
	// handle level map events
	void handleLevelMapEvents(Board &board, LevelFileManager &lfm, EditOption &editOption, Character &selectCharacter);
	// run window loop
	void runWindow(RenderWindow &window, Board &board);
};

