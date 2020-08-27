#pragma once
//---- include section ------
#include <string>
#include "LevelMap.h"

//---- using section ----------------
using std::string;

/*
 * Utilites namespace
 */
namespace Utilites {
	// check if robot in level map
	bool isRobotInMap(const LevelMap &levelMap, Cell &robotCell);
	// check if exit door in level map
	bool isExitDoorInMap(const LevelMap &levelMap, Cell &exitDoorCell);
}
