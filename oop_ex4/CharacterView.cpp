//---- include section ------
#include "CharacterView.h"
#include "Resources.h"

CharacterView::CharacterView(RenderWindow & window)
	: ImageView(window), m_character(EMPTY)
{ 
	setBorder(Border(Color::Black, 1));
}

void CharacterView::setCharacter(Character character)
{
	switch (character) {
		case ROBOT: {
			setImage(Resources::Images::Robot);
		} break;
		case GUARD: {
			setImage(Resources::Images::Guard);
		} break;
		case EXIT_DOOR: {
			setImage(Resources::Images::ExitDoor);
		} break;
		case ROCK: {
			setImage(Resources::Images::Rock);
		} break;
		case WALL: {
			setImage(Resources::Images::Wall);
		} break;
		case EMPTY: {
			setImage(ImageTexture(Color::Transparent)); // no image
		} break;
		default: {
			throw string("don't support set the character + " + std::to_string(character));
		} break;
	}
	m_character = character;
}

Character CharacterView::getCharacter() const
{
	return m_character;
}

string CharacterView::toString() const
{
	return "CharacterView: " + ImageView::toString();
}
