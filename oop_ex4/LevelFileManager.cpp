//---- include section ------------
#include <experimental/filesystem>
#include "LevelFileManager.h"
#include "CharacterView.h"

void LevelFileManager::loadLevelMap(LevelMap &levelMap)
{
	int numOfRow, numOfCol;

	std::ifstream fp(NAME_OF_FILE);

	//can't open the file
	if (!fp.is_open())
		throw string("Cannot open file " + string(NAME_OF_FILE));
	
	fp >> numOfRow >> numOfCol;
	fp.get();
	levelMap.setMapSize(sf::Vector2i(numOfRow, numOfCol));
	for (int row = 0; row < numOfRow; row++)
	{
		for (int col = 0; col < numOfCol; col++)
		{
			char character = fp.get();
			Cell cell(row, col);
			CharacterView &cv = levelMap.getCharacterView(cell);
				switch (character)
				{
				case ROBOT_SHAPE: {
					cv.setCharacter(ROBOT);
				} break;
				case GUARD_SHAPE: {
					cv.setCharacter(GUARD);
				} break;
				case EXIT_DOOR_SHAPE: {
					cv.setCharacter(EXIT_DOOR);
				} break;
				case ROCK_SHAPE: {
					cv.setCharacter(ROCK);
				} break;
				case WALL_SHAPE: {
					cv.setCharacter(WALL);
				} break;
				 case EMPTY_SHAPE: {
					cv.setCharacter(EMPTY);
				} break;
				default:
					throw string("Cannot parser this sign " + character);
				}
		}
		// for new line
		fp.get();
	}
	fp.close();
}

void LevelFileManager::saveLevelMap(const LevelMap &levelMap)
{
	std::ofstream fp(NAME_OF_FILE);
	// can't open the file
	if (!fp.is_open())
		throw string("Cannot open file " + string(NAME_OF_FILE));

	fp << levelMap.getMapSize().x << " " << levelMap.getMapSize().y << std::endl;

	for (int row = 0; row < levelMap.getMapSize().x; row++)
	{
		for (int col = 0; col < levelMap.getMapSize().y; col++)
		{
			Cell cell(row, col);
			CharacterView &cv = levelMap.getCharacterView(cell);
			switch (cv.getCharacter())
			{
				case ROBOT: {
					fp << ROBOT_SHAPE;
				} break;
				case GUARD: {
					fp << GUARD_SHAPE;
				} break;
				case EXIT_DOOR: {
					fp << EXIT_DOOR_SHAPE;
				} break;
				case ROCK: {
					fp << ROCK_SHAPE;
				} break;
				case WALL: {
					fp << WALL_SHAPE;
				} break;
				case EMPTY: {
					fp << EMPTY_SHAPE;
				} break;
				default:
					throw string("Cannot parse this view " + cv.toString());
			}
		}
		fp << std::endl;
	}
	fp.close();

}

bool LevelFileManager::fileExists()
{
	return std::experimental::filesystem::exists(NAME_OF_FILE);
}
