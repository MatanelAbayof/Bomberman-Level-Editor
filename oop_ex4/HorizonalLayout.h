#pragma once
//---- include section ------
#include <string>
#include "ViewGroup.h"

//---- using section --------
using std::string;

/*
 * HorizonalLayout class
 */
class HorizonalLayout :
	public ViewGroup
{
public:
	// constructor
	HorizonalLayout(RenderWindow &window);
	// add view with default width
	virtual void addView(View &view);
	// add view with custom width
	virtual void addView(View &view, float relativeWidth);
	// remove view
	virtual void removeView(int index);
	// convert to string
	virtual string toString() const;
protected:
	// update components
	virtual void updateComponents();
private:
	// childrens relative heights
	vector<float> m_relativeWidths;
	// check relative height
	bool checkRelativeWidth(float relativeWidth) const;
	// arrange all childrens with same widths
	void arrangeChildrens();
};

