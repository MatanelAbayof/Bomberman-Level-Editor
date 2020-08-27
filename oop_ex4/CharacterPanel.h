#pragma once
//---- include section ------
#include <string>
#include "HorizonalLayout.h"
#include "CharacterButton.h"

//---- using section --------
using std::string;

/*
 * CharacterPanel class
 */
class CharacterPanel :
	public HorizonalLayout
{
public:
	// buttons background colors
	static const Color BT_BACK_COLOR, BT_FOCUS_BACK_COLOR, BT_SEL_BACK_COLOR, BT_SELFCS_BACK_COLOR;
	// constructor
	CharacterPanel(RenderWindow &window);
	// for each loop on all characters buttons
	void forEach(std::function<void(CharacterButton&)> onGetCharBt);
	// get character button
	CharacterButton &getCharacterButton(Character character);
	// convert to string
	virtual string toString() const;	
private:
	// buttons in toolbar
	CharacterButton m_robotButton, m_guardButton, m_exitDoorButton, 
		            m_rockButton, m_wallButton;
	// init components
	void initComponents();
	// init character button at me
	void initCharButton(CharacterButton &button);
	// redeclaring scope of base class functions in private section of derived class
	using HorizonalLayout::addView;
	using HorizonalLayout::removeView;
};


