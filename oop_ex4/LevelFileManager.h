#pragma once
//---- include section ------
#include <iostream>
#include <fstream>
#include "LevelMap.h"

//---- using section --------
using std::string;
using sf::Vector2i;

/*
 * LevelMap class
 */
class LevelFileManager
{
public:
	//load level map from file
	void loadLevelMap(LevelMap &levelMap);
	// save level map
	void saveLevelMap(const LevelMap &levelMap);
	// check if file exists
	bool fileExists();
private:
	// the name of file
	const char *NAME_OF_FILE = "board.bomb";
	// the signs of charcters on file
	static const char ROBOT_SHAPE = '/';
	static const char GUARD_SHAPE = '!';
	static const char EXIT_DOOR_SHAPE = 'D';
	static const char ROCK_SHAPE = '@';
	static const char WALL_SHAPE = '#';
	static const char EMPTY_SHAPE = ' ';
};

