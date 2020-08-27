//---- include section ------
#include "CharacterButton.h"
#include "Resources.h"


CharacterButton::CharacterButton(RenderWindow &window)
	:ImageButton(window), m_character(EMPTY)
{ }

void CharacterButton::setCharacter(Character character)
{
	switch (character) {
		case ROBOT:{
			setText("Robot");
			setImage(Resources::Images::Robot);
		} break;
		case GUARD: {
			setText("Guard");
			setImage(Resources::Images::Guard);
		} break;
		case EXIT_DOOR: {
			setText("Exit Door");
			setImage(Resources::Images::ExitDoor);
		} break;
		case ROCK: {
			setText("Rock");
			setImage(Resources::Images::Rock);
		} break;
		case WALL: {
			setText("Wall");
			setImage(Resources::Images::Wall);
		} break;
		case EMPTY: {
			setText(" ");
			setImage(ImageTexture(Color::Transparent)); // no image
		} break;
	}
	m_character = character;
}

Character CharacterButton::getCharacter() const
{
	return m_character;
}

string CharacterButton::toString() const
{
	return "CharacterButton: " + ImageButton::toString();
}


