//---- include section ------
#include "CharacterPanel.h"

// init buttons background colors
const Color CharacterPanel::BT_BACK_COLOR(0xD1, 0xD1, 0xD1), CharacterPanel::BT_FOCUS_BACK_COLOR(0x98, 0x98, 0x98),
			CharacterPanel::BT_SEL_BACK_COLOR(0x63, 0x60, 0xFF), CharacterPanel::BT_SELFCS_BACK_COLOR(0x39, 0x36, 0xFF);

CharacterPanel::CharacterPanel(RenderWindow &window)
	: HorizonalLayout(window), m_robotButton(window), m_guardButton(window), m_exitDoorButton(window),
	  m_rockButton(window), m_wallButton(window)
{
	initComponents();
}

void CharacterPanel::forEach(std::function<void(CharacterButton&)> onGetCharBt)
{
	onGetCharBt(m_robotButton);
	onGetCharBt(m_guardButton);
	onGetCharBt(m_exitDoorButton);
	onGetCharBt(m_rockButton);
	onGetCharBt(m_wallButton);
}

CharacterButton &CharacterPanel::getCharacterButton(Character character)
{
	switch (character) {
		case ROBOT: {
			return m_robotButton;
		} break;
		case GUARD: {
			return m_guardButton;
		} break;
		case EXIT_DOOR: {
			return m_exitDoorButton;
		} break;
		case ROCK: {
			return m_rockButton;
		} break;
		case WALL: {
			return m_wallButton;
		} break;
		default: {
			throw string("Not found button of character " + std::to_string(character));
		} break;
	}
}

string CharacterPanel::toString() const
{
	return "CharacterPanel: " + HorizonalLayout::toString();
}

void CharacterPanel::initComponents()
{
	// set my border & background
	setBorder(Border(Color::Black, 1));
	getBackground().setColor(Color(240, 255, 239));

	// set characters at buttons
	m_robotButton.setCharacter(ROBOT);
	m_guardButton.setCharacter(GUARD);
	m_exitDoorButton.setCharacter(EXIT_DOOR);
	m_rockButton.setCharacter(ROCK);
	m_wallButton.setCharacter(WALL);

	// init buttons
	initCharButton(m_robotButton);
	initCharButton(m_guardButton);
	initCharButton(m_exitDoorButton);
	initCharButton(m_rockButton);
	initCharButton(m_wallButton);
}

void CharacterPanel::initCharButton(CharacterButton &button)
{
	button.getBackground().setColor(BT_BACK_COLOR);
	button.setBorder(Border(Color::Black, 1));
	float relativeCSize = (float)1 / 14;
	addView(button, relativeCSize);
}



