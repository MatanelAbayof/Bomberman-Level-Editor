#pragma once
//---- include section ------
#include <string>
#include <vector>
#include "View.h"
//---- using section --------
using std::string;
using std::vector;

/*
 * ViewGroup abstract class
 */
class ViewGroup :
	public View
{
public:
	// get view
	virtual View &getView(int index) const;
	// get number of views
	virtual int getNumOfViews() const;
	// draw
	virtual void draw();
	// convert to string
	virtual string toString() const;
protected:
	// constructor
	ViewGroup(RenderWindow &window);
	// handle click event
	virtual void handleClickEvent(int mouseX, int mouseY);
	// handle enter event
	virtual void handleEnterEvent(int mouseX, int mouseY);
	// handle leave event
	virtual void handleLeaveEvent(int mouseX, int mouseY);
	// check if have view in index
	bool haveViewAt(int index) const;
	// remove view
	virtual void removeView(int index);
	// add view
	virtual void addView(View &view);
private:
	// views in layout
	vector<View*> m_views;
};

