//---- include section ------
#include "View.h"
#include "RectUtils.h"

// init default position
const Vector2f View::DEFAULT_POSITION = { 0, 0 };

View::View(RenderWindow &window)
	: m_window(window), m_show(true), m_clickable(true), m_width(MIN_WIDTH),
	  m_height(MIN_HEIGHT), m_position(DEFAULT_POSITION), m_parent(nullptr),
	  m_mouseIn(false), m_mouseOut(true)
{
	// init texture
	updateComponents();
}

RenderWindow &View::getWindow()
{
	return m_window;
}

void View::sendDrawRequest(const Drawable &drawable)
{
	if (isShow())
		m_window.draw(drawable);
}

void View::callOnClick()
{
	if (m_clickable)
		m_clickHandler.callListeners(*this);
}

void View::addClickListener(ClickHandler::Listener listener)
{
	m_clickHandler.addListener(listener);
}

void View::callOnEnter()
{
	if (m_clickable)
		m_enterHandler.callListeners(*this);
}

void View::addEnterListener(EnterHandler::Listener listener)
{
	m_enterHandler.addListener(listener);
}

void View::callOnLeave()
{
	if (m_clickable)
		m_leaveHandler.callListeners(*this);
}

void View::addLeaveListener(LeaveHandler::Listener listener)
{
	m_leaveHandler.addListener(listener);
}

bool View::isPointInMyArea(int x, int y) const
{
	return isPointInMyArea(Vector2f((float) x, (float) y));
}

bool View::isPointInMyArea(const Vector2f &point) const
{
	return getBound().contains(point);
}

bool View::handleEvent(const Event &event)
{	
	switch (event.type) {
		case Event::MouseButtonPressed: {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				handleClickEvent(event.mouseButton.x, event.mouseButton.y);
			else
				return false; // cannot handle the event
		} break;
		case Event::MouseEntered: {
			handleEnterEvent(event.mouseMove.x, event.mouseMove.y);
		} break;
		case Event::MouseLeft: { // mouse left the screen
			handleLeaveEvent(-1, -1); // fake mouse coordinate
		} break;
		case Event::MouseMoved: {
			handleEnterEvent(event.mouseMove.x, event.mouseMove.y);
			handleLeaveEvent(event.mouseMove.x, event.mouseMove.y);
		} break;
		case Event::Resized: {
			// if is root view
			if (isRootView()) {
				// new bound
				FloatRect newBound = RectUtils::createFloatRect(Vector2f(0, 0), event.size.width, event.size.height);
				// disable SFML resize
				m_window.setView(sf::View(newBound));
				// resize view to maximum
				setBound(newBound);
			}
		} break;
		default: // if cannot handle the event
			return false;
	}
	// come here if event has been handled
	return true;
}

Vector2f View::getPosition() const
{
	return m_position;
}

FloatRect View::getBound() const
{
	return FloatRect(getPosition(), Vector2f((float) m_width, (float) m_height));
}

int View::getWidth() const
{
	return m_width;
}

int View::getHeight() const
{
	return m_height;
}

bool View::isShow() const
{
	return m_show;
}

void View::show()
{
	m_show = true;
	enable();
}

void View::hide()
{
	m_show = false;
	disable();
}

void View::enable()
{
	m_clickable = true;
}

void View::disable()
{
	m_clickable = false;
}

bool View::isEnable() const
{
	return m_clickable;
}

ImageTexture& View::getBackground()
{
	return m_background;
}

void View::setBorder(const Border &border)
{
	m_border = border;
}

Border View::getBorder() const
{
	return m_border;
}

void View::draw()
{
	if (isShow()) {
		FloatRect bounds = getBound();
		// draw background
		m_background.draw(m_window, bounds);
		// draw border
		m_border.draw(m_window, bounds);
	}
}

string View::toString() const
{
	return "View: position: x=" + std::to_string(m_position.x) + ", y=" + std::to_string(m_position.y) + 
		   ", width = " + std::to_string(getWidth()) + ", height = " + std::to_string(getHeight()) + 
		   ", background=" + m_background.toString() + ", border=" + m_border.toString();
}

void View::setWidth(int width)
{
	if (!checkBound(RectUtils::createFloatRect(getPosition(), width, getHeight())))
		throw string(toString() + " is out of bound!");
	// set new width
	m_width = width;
	updateComponents();
}

void View::setHeight(int height)
{
	if (!checkBound(RectUtils::createFloatRect(getPosition(), getWidth(), height)))
		throw string(toString() + " is out of bound!");
	// set new height
	m_height = height;
	updateComponents();
}

void View::setBound(const FloatRect &bound)
{
	if (!checkBound(bound))
		throw string(toString() + " is out of bound!");
	// add members
	m_position = Vector2f(bound.left, bound.top);
	m_width = (int) bound.width;
	m_height = (int) bound.height;

	updateComponents();
}

void View::setBound(const Vector2f &position, int width, int height)
{
	setBound(RectUtils::createFloatRect(position, width, height));
}

void View::setPosition(const Vector2f &position)
{
	if (!checkBound(RectUtils::createFloatRect(position, getWidth(), getHeight())))
		throw string(toString() + " is out of bound!");
	m_position = position;
	updateComponents();
}

void View::setParent(View &view)
{
	m_parent = &view;
}

View &View::getParent() const
{
	if (isRootView())
		throw string("There are no parent view");
	return *m_parent;
}

bool View::isRootView() const
{
	return (m_parent == nullptr);
}

void View::updateComponents()
{ }

bool View::isNoSet() const
{
	return ((getWidth() == MIN_WIDTH || getHeight() == MIN_HEIGHT));
}

bool View::checkBound(const FloatRect &bound) const
{
	// if is no set
	if (isNoSet())
		return true;

	// check legal position
	if (!isLegalPosition(Vector2f(bound.left, bound.top)))
		return false;
	
	// check legal width
	if (!isLegalWidth((int) bound.width))
		return false;
	// check legal height
	if (!isLegalHeight((int) bound.height))
		return false;
	
	// if is root view
	if (isRootView())
		return true;

	// check if area in parent bound
	if (RectUtils::rectInAnother(bound, getParent().getBound()))
		return true;

	return false;
}

bool View::isLegalPosition(const Vector2f &position) const
{
	return ((position.x >= 0) && (position.y >= 0));
}

bool View::isLegalWidth(int width) const
{
	return width >= 0;
}

bool View::isLegalHeight(int height) const
{
	return height >= 0;
}

void View::handleClickEvent(int mouseX, int mouseY)
{
	if (isPointInMyArea(mouseX, mouseY))
		callOnClick();
}

void View::handleEnterEvent(int mouseX, int mouseY)
{
	if (isPointInMyArea(mouseX, mouseY))
	{
		if (!m_mouseIn) {
			callOnEnter();
			m_mouseIn = true;
		}	
	} else {
		m_mouseIn = false;
	}
}

void View::handleLeaveEvent(int mouseX, int mouseY)
{
	if (!isPointInMyArea(mouseX, mouseY))
	{
		if (!m_mouseOut) {
			callOnLeave();
			m_mouseOut = true;
		}
	}
	else {
		m_mouseOut = false;
	}
}