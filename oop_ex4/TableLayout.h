#pragma once
//---- include section ------
#include <string>
#include "VerticalLayout.h"
#include "HorizonalLayout.h"
#include "Cell.h"

//---- using section --------
using std::string;

/*
 * TableLayout class
 */
class TableLayout :
	public VerticalLayout
{
public:
	// constructor
	TableLayout(RenderWindow &window);
	// add row
	void addRow(HorizonalLayout &row);
	// add row
	void addRow(HorizonalLayout &row, float relativeheight);
	// get number of rows
	int getNumOfRows() const;
	// remove row
	void removeRow(int index);
	// get row
	HorizonalLayout &getRow(int index) const;
	// get view
	View &getView(const Cell &cell) const;
	// for each views
	void forEach(std::function<void(View&, const Cell&)> onGetView) const;
	// convert to string
	virtual string toString() const;
private:
	// if have view in cell
	bool haveViewInCell(const Cell &cell) const;
	// redeclaring scope of base class functions in private section of derived class
	using VerticalLayout::addView;
	using VerticalLayout::removeView;
	using VerticalLayout::getView;
	using VerticalLayout::getNumOfViews;
};

