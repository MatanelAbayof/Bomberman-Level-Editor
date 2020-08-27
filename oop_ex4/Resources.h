#pragma once
//---- include section ------
#include <SFML/Graphics.hpp>
#include <string>

//---- using section ----------------
using std::string;
using sf::Texture;
using sf::Font;
using sf::Image;

/*
 * Resources namespace
 * all members here are global
 */
namespace Resources {

	// images
	namespace Images {
		extern Texture Robot, Guard, Rock, Wall, ExitDoor;
		extern Image BombermanIcon;
		// load images recources
		void loadImages();
	}
	
	// fonts 
	namespace Fonts {
		extern Font Arial;

		// load fonts recources
		void loadFonts();
	}

	// load all recources
	void loadResources();
}
