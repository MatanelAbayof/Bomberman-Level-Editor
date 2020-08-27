//---- include section ------
#include "TableLayout.h"

TableLayout::TableLayout(RenderWindow &window)
	: VerticalLayout(window)
{ }

void TableLayout::addRow(HorizonalLayout &row)
{
	addView(row);
}

void TableLayout::addRow(HorizonalLayout &row, float relativeheight)
{
	addView(row, relativeheight);
}

int TableLayout::getNumOfRows() const
{
	return getNumOfViews();
}

void TableLayout::removeRow(int index)
{
	removeView(index);
}

HorizonalLayout &TableLayout::getRow(int index) const
{
	View *rowView = &getView(index);
	if (HorizonalLayout *rowHLayout = dynamic_cast<HorizonalLayout*>(rowView)) {
		return *rowHLayout;
	}
	throw string("Can't parse row at " + std::to_string(index));
}

View &TableLayout::getView(const Cell &cell) const
{
	if (!haveViewInCell(cell))
		throw string("No found view at " + cell.toString());

	return getRow(cell.getRowNum()).getView(cell.getColNum());
}

void TableLayout::forEach(std::function<void(View&, const Cell&)> onGetView) const
{
	for (int rowNum = 0; rowNum < getNumOfRows(); rowNum++) {
		HorizonalLayout &rowLayout = getRow(rowNum);
		for (int colNum = 0; colNum < rowLayout.getNumOfViews(); colNum++) {
			View &rowChild = rowLayout.getView(colNum);
			onGetView(rowChild, Cell(rowNum, colNum));
		}
	}
}

string TableLayout::toString() const
{
	return "TableLayout: view=" + VerticalLayout::toString();
}

bool TableLayout::haveViewInCell(const Cell &cell) const
{
	// check rows
	if (cell.getRowNum() >= getNumOfRows())
		return false;
	// get row
	HorizonalLayout &row = getRow(cell.getRowNum());
	// check columns
	if (cell.getColNum() >= row.getNumOfViews())
		return false;
	return true;
}
