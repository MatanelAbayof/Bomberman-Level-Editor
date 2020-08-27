#pragma once
//---- include section ------
#include <functional>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "IHandler.h"
#include "ImageTexture.h"
#include "Border.h"

//---- using section --------
using std::string;
using sf::Vector2f;
using sf::FloatRect;
using std::vector;
using sf::RenderWindow;
using sf::Sprite;
using sf::Texture;
using sf::Drawable;
using sf::Event;
using sf::Color;

/*
 * View abstract class
 */
class View
{
public:
	// type of click handler
	typedef IHandler<View> ClickHandler;
	// type of enter handler
	typedef IHandler<View> EnterHandler;
	// type of leave handler
	typedef IHandler<View> LeaveHandler;
	// default position
	static const Vector2f DEFAULT_POSITION;
	// default width
	static const int MIN_WIDTH = 0;
	// default height
	static const int MIN_HEIGHT = 0;
	// handle events - return false if cannot handle
	bool handleEvent(const Event &event);
	// handle click event
	virtual void handleClickEvent(int mouseX, int mouseY);
	// handle enter event
	virtual void handleEnterEvent(int mouseX, int mouseY);
	// handle leave event
	virtual void handleLeaveEvent(int mouseX, int mouseY);
	// call click event
	virtual void callOnClick();
	// listen to click event
	void addClickListener(ClickHandler::Listener listener);
	// call enter event
	virtual void callOnEnter();
	// listen to enter event
	void addEnterListener(EnterHandler::Listener listener);
	// call leave event
	virtual void callOnLeave();
	// listen to leave event
	void addLeaveListener(LeaveHandler::Listener listener);
	// if point in my area
	bool isPointInMyArea(int x, int y) const;
	bool isPointInMyArea(const Vector2f &point) const;
	// get position
	Vector2f getPosition() const;
	// get bound rectangle
	FloatRect getBound() const;
	// get width
	int getWidth() const;
	// get height
	int getHeight() const;
	// is show
	bool isShow() const;
	// show
	virtual void show();
	// hide
	virtual void hide();
	// enable events
	virtual void enable();
	// disable events
	virtual void disable();
	// check if view is enable
	bool isEnable() const;
	// get background
	ImageTexture& getBackground();
	// set border
	void setBorder(const Border &border);
	// get border
	Border getBorder() const;
	// draw in window
	virtual void draw();
	// set width
	void setWidth(int width);
	// set height
	void setHeight(int height);
	// set area
	void setBound(const FloatRect &bound);
	// set area
	void setBound(const Vector2f &position, int width, int height);
	// set position
	void setPosition(const Vector2f &position);
	// get parent view
	View &getParent() const;
	// check if has no parent view
	bool isRootView() const;
	// set parent view
	void setParent(View &view);
	// get window
	RenderWindow &getWindow();
	// cannot copy view
	View(const View &) = delete;
	View &operator=(const View &) = delete;
	// convert to string
	virtual string toString() const;
protected:
	// constructor
	View(RenderWindow &window);
	// draw in view
	void sendDrawRequest(const Drawable &drawable);
	// update components
	virtual void updateComponents();
	// check if view not set already
	bool isNoSet() const;
private:
	// window
	RenderWindow &m_window;
	// parent view
	View *m_parent;
	// background object
	ImageTexture m_background;
	// border
	Border m_border;
	// size of view
	int m_width, m_height;
	// visibility
	bool m_show;
	// clickable - use for events
	bool m_clickable;
	// position of view
	Vector2f m_position;
	// mouse in view (for enter handler)
	bool m_mouseIn;
	// mouse out of view (for leave handler)
	bool m_mouseOut;
	// click handler
	ClickHandler m_clickHandler;
	// enter handler
	EnterHandler m_enterHandler;
	// leave handler
	EnterHandler m_leaveHandler;
	// check if can set bound
	bool checkBound(const FloatRect &bound) const;
	// check if position OK
	bool isLegalPosition(const Vector2f &position) const;
	// check if width OK
	bool isLegalWidth(int width) const;
	// check if height OK
	bool isLegalHeight(int height) const;
};

