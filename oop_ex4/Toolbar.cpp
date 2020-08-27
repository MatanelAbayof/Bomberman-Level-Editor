//---- include section ------
#include "Toolbar.h"

// init buttons background colors
const Color Toolbar::BT_BACK_COLOR(0xD1, 0xD1, 0xD1), Toolbar::BT_FOCUS_BACK_COLOR(0x98, 0x98, 0x98),
            Toolbar::BT_SEL_BACK_COLOR(0x63, 0x60, 0xFF), Toolbar::BT_SELFCS_BACK_COLOR(0x39, 0x36, 0xFF);

Toolbar::Toolbar(RenderWindow &window)
	: HorizonalLayout(window), m_newButton(window), m_saveButton(window), m_deleteButton(window)
{
	initComponents();
}

TextView &Toolbar::getNewButton()
{
	return m_newButton;
}

TextView &Toolbar::getSaveButton()
{
	return m_saveButton;
}

TextView &Toolbar::getDeleteButton() 
{
	return m_deleteButton;
}

string Toolbar::toString() const
{
	return "Toolbar: " + HorizonalLayout::toString();
}

void Toolbar::initComponents()
{
	// set my border & background
	setBorder(Border(Color::Black, 1));
	getBackground().setColor(Color(232, 232, 232));

	// set buttons texts
	m_newButton.setText("New");
	m_saveButton.setText("Save");
	m_deleteButton.setText("Delete");

	// init buttons
	initButton(m_newButton);
	initButton(m_saveButton);
	initButton(m_deleteButton);
}

void Toolbar::initButton(TextView &button)
{
	button.getBackground().setColor(BT_BACK_COLOR);
	button.setBorder(Border(Color::Black, 1));
	float relativeCSize = (float)1 / 8;
	addView(button, relativeCSize);
}
