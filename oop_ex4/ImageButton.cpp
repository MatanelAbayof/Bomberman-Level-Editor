//---- include section ------
#include "ImageButton.h"

ImageButton::ImageButton(RenderWindow &window, const ImageTexture &imageTexture, const string &text)
	: VerticalLayout(window), m_image(window, imageTexture), m_text(window, text)
{
	initComponents();
}

void ImageButton::setImage(const ImageTexture &imageTexture)
{
	m_image.setImage(imageTexture);
}

ImageTexture ImageButton::getImage() const
{
	return m_image.getImage();
}

void ImageButton::setText(const string &text)
{
	m_text.setText(text);
}

string ImageButton::getText() const
{
	return m_text.getText();
}

void ImageButton::setTextColor(const Color &textColor)
{
	m_text.setTextColor(textColor);
}

Color ImageButton::getTextColor() const
{
	return m_text.getTextColor();
}

string ImageButton::toString() const
{
	return "ImageButton: " + VerticalLayout::toString();
}

void ImageButton::initComponents()
{
	// set my border
	setBorder(Border(Color::Black, 1));

	// set buttons border
	Border buttonBorder(Color::Black, 1);
	m_image.setBorder(buttonBorder);
	m_text.setBorder(buttonBorder);

	addView(m_image, 0.6f);
	addView(m_text, 0.4f);
}
