#pragma once
//---- include section ------
#include <string>
#include "HorizonalLayout.h"
#include "TextView.h"

//---- using section --------
using std::string;

/*
 * Toolbar class
 */
class Toolbar :
	public HorizonalLayout
{
public:
	// buttons background colors
	static const Color BT_BACK_COLOR, BT_FOCUS_BACK_COLOR, BT_SEL_BACK_COLOR, BT_SELFCS_BACK_COLOR;
	// constructor
	Toolbar(RenderWindow &window);
	// get 'New' button
	TextView &getNewButton();
	// get 'Save' button
	TextView &getSaveButton();
	// get delete button
	TextView &getDeleteButton();
	// convert to string
	virtual string toString() const;
private:
	// buttons in toolbar
	TextView m_newButton, m_saveButton, m_deleteButton;
	// init components
	void initComponents();
	// init button at me
	void initButton(TextView &button);
	// redeclaring scope of base class functions in private section of derived class
	using HorizonalLayout::addView;
	using HorizonalLayout::removeView;
};

