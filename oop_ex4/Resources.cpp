//---- include section ------
#include "Resources.h"
#include "Utilities.h"

// init resources
Font Resources::Fonts::Arial;
Texture Resources::Images::Robot, Resources::Images::Guard, 
        Resources::Images::Rock, Resources::Images::Wall, 
	    Resources::Images::ExitDoor;
Image Resources::Images::BombermanIcon;


void Resources::loadResources()
{
	Fonts::loadFonts();
	Images::loadImages();
}

void Resources::Images::loadImages()
{
	// images dir relative path
	string imagesDirPath = "images";

	// load images
	Robot.loadFromFile(imagesDirPath + "\\robot.png");
	Guard.loadFromFile(imagesDirPath + "\\guard.png");
	Rock.loadFromFile(imagesDirPath + "\\rock.png");
	Wall.loadFromFile(imagesDirPath + "\\wall.png");
	ExitDoor.loadFromFile(imagesDirPath + "\\exit_door.png");
	BombermanIcon.loadFromFile(imagesDirPath + "\\bomberman-icon.png");
}

void Resources::Fonts::loadFonts()
{
	// fonts dir relative path
	string fontsDirPath = "fonts";

	// load fonts
	Arial.loadFromFile(fontsDirPath + "\\arial.ttf");
}
