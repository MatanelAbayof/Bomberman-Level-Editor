#pragma once
//---- include section ------
#include <string>
#include <vector>
#include "ViewGroup.h"

//---- using section --------
using std::string;
using std::vector;

/*
 * RelativeLayout class
 */
class RelativeLayout :
	public ViewGroup
{
public:
	// constructor
	RelativeLayout(RenderWindow &window);
	// add view
	virtual void addView(View &view, const FloatRect &relativeBounds);
	// remove view
	virtual void removeView(int index);
	// convert to string
	virtual string toString() const;
protected:
	// update components
	virtual void updateComponents();
private:
	// relative bounds of children
	vector<FloatRect> m_relativeBounds;
	// check relative bounds
	bool checkRelativeBounds(const FloatRect &relativeBounds) const;
	// check if number between 0-1
	bool checkBoundNumOK(float num) const;
};

