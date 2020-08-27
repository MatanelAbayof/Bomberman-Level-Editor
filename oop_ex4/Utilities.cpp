//---- include section ------
#include "Utilities.h"
#include <windows.h>

bool Utilites::isRobotInMap(const LevelMap &levelMap, Cell &robotCell)
{
	for (int row = 0; row < levelMap.getMapSize().x; row++)
	{
		for (int col = 0; col < levelMap.getMapSize().y; col++)
		{
			Cell cell(row, col);
			CharacterView &charView = levelMap.getCharacterView(cell);
			if (charView.getCharacter() == ROBOT) {
				robotCell = cell;
				return true;
			}
		}
	}
	return false;
}

bool Utilites::isExitDoorInMap(const LevelMap & levelMap, Cell & exitDoorCell)
{
	for (int row = 0; row < levelMap.getMapSize().x; row++)
	{
		for (int col = 0; col < levelMap.getMapSize().y; col++)
		{
			Cell cell(row, col);
			CharacterView &charView = levelMap.getCharacterView(cell);
			if (charView.getCharacter() == EXIT_DOOR) {
				exitDoorCell = cell;
				return true;
			}
		}
	}
	return false;
}