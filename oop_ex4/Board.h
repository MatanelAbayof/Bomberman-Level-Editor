#pragma once
//---- include section ------
#include <string>
#include "VerticalLayout.h"
#include "HorizonalLayout.h"
#include "TableLayout.h"
#include "Toolbar.h"
#include "CharacterPanel.h"
#include "LevelMap.h"

//---- using section --------
using std::string;

/*
 * Board class
 */
class Board :
	public VerticalLayout
{
public:
	// constructor
	Board(RenderWindow &window);
	// get menu
	Toolbar &getMenu();
	// get character panel
	CharacterPanel &getCharPanel();
	// get level map
	LevelMap &getLevelMap();
	// convert to string
	virtual string toString() const;
private:
	// menu toolbar
	Toolbar m_menu;
	// characters buttons
	CharacterPanel m_charPanel;
	// level map
	LevelMap m_levelMap;
	// all rights reserved text
	TextView m_allRights;
	// init components
	void initComponents();
	// redeclaring scope of base class functions in private section of derived class
	using VerticalLayout::addView;
	using VerticalLayout::removeView;
	using VerticalLayout::getView;
	using VerticalLayout::getNumOfViews;
};

