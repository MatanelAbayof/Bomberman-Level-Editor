#pragma once
//---- include section ------
#include <string>
#include "ViewGroup.h"
//---- using section --------
using std::string;

/*
 * VerticalLayout class
 */
class VerticalLayout :
	public ViewGroup
{
public:
	// constructor
	VerticalLayout(RenderWindow &window);
	// add view with default height
	virtual void addView(View &view);
	// add view
	virtual void addView(View &view, float relativeHeight);
	// remove view
	virtual void removeView(int index);
	// get relative height of child
	float getChildRelativeHeight(int index) const;
	// convert to string
	virtual string toString() const;
protected:
	// update components
	virtual void updateComponents();
private:
	// my view relative heights
	vector<float> m_relativeHeights;
	// check relative height
	bool checkRelativeHeight(float relativeHeight) const;
	// arrange childrens with same heights
	void arrangeChildrens();
};