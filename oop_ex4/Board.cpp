//---- include section ------
#include "Board.h"

Board::Board(RenderWindow &window)
	: VerticalLayout(window), m_menu(window), m_charPanel(window), m_levelMap(window), m_allRights(window)
{
	initComponents();
}

Toolbar &Board::getMenu()
{
	return m_menu;
}

CharacterPanel &Board::getCharPanel()
{
	return m_charPanel;
}

LevelMap &Board::getLevelMap()
{
	return m_levelMap;
}

string Board::toString() const
{
	return "Board: " + VerticalLayout::toString();
}

void Board::initComponents()
{
	// set my style
	sf::Vector2u windowSize = getWindow().getSize();
	setBound(Vector2f(0, 0), windowSize.x, windowSize.y);

	// init all rights text
	m_allRights.getBackground().setColor(Color::White);
	m_allRights.setText("© Matanel Abayof & Nahum Noga");

	// add childs to me
	addView(m_menu, 0.05f);
	addView(m_charPanel, 0.1f);
	addView(m_levelMap, 0.82f);
	addView(m_allRights, 0.03f);
}
