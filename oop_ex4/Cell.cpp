//---- include section ------
#include "Cell.h"

Cell::Cell(int rowNum, int colNum) 
{
	setCell(rowNum, colNum);
}

int Cell::getRowNum() const
{
	return m_rowNum;
}

int Cell::getColNum() const
{
	return m_colNum;
}

void Cell::setCell(int rowNum, int colNum)
{
	if (isValidCell(rowNum, colNum))
	{
		m_rowNum = rowNum;
		m_colNum = colNum;
	}
	else
		throw string("Illegal cell: rowNum = " + std::to_string(rowNum) + ", colNum = " + std::to_string(colNum));
}

bool Cell::isValidCell(int rowNum, int colNum) const
{
	if ((rowNum < 0) || (colNum < 0))
		return false;
	return true;
}

Cell Cell::getUpCell() const
{
	return Cell(m_rowNum - 1, m_colNum);
}

Cell Cell::getDownCell() const
{
	return Cell(m_rowNum + 1, m_colNum);
}

Cell Cell::getLeftCell() const
{
	return Cell(m_rowNum, m_colNum - 1);
}

Cell Cell::getRightCell() const
{
	return Cell(m_rowNum, m_colNum + 1);
}

string Cell::toString() const
{
	return "Cell: number of row: " + std::to_string(m_rowNum) + ", number of col: " + std::to_string(m_colNum);
}

bool Cell::operator==(const Cell &anotherCell)
{
	return (getRowNum() == anotherCell.getRowNum()) && (getColNum() == anotherCell.getColNum());
}

bool Cell::operator!=(const Cell &anotherCell)
{
	return ((getRowNum() != anotherCell.getRowNum()) || (getColNum() != anotherCell.getColNum()));
}

bool Cell::isAboveThen(Cell otherCell) const
{
	return (m_rowNum == otherCell.m_rowNum - 1 && m_colNum == otherCell.m_colNum);
}

bool Cell::isUnderThen(Cell otherCell) const
{
	return (m_rowNum == otherCell.m_rowNum + 1 && m_colNum == otherCell.m_colNum);
}

bool Cell::isLeftTo(Cell otherCell) const
{
	return (m_rowNum == otherCell.m_rowNum && m_colNum == otherCell.m_colNum - 1);
}

bool Cell::isRightTo(Cell otherCell) const
{
	return (m_rowNum == otherCell.m_rowNum && m_colNum == otherCell.m_colNum + 1);
}