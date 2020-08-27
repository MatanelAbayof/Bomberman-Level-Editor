#pragma once
//---- include section ------
#include <string>
//---- using section --------
using std::string;

/*
 * Cell class
 */
class Cell
{
public:
	// default row number and column number of cell
	static const int DEFAULT_ROW_NUM = 0, DEFAULT_COL_NUM = 0;
	// constructor
	Cell(int rowNum = DEFAULT_ROW_NUM, int colNum = DEFAULT_COL_NUM);
	//get num of row
	int getRowNum() const;
	//get num of column
	int getColNum() const;
    //set new cell
	void setCell(int rowNum, int colNum);
	// get up cell
	Cell getUpCell() const;
	//get down cell
	Cell getDownCell() const;
	//get left cell
	Cell getLeftCell() const;
	//get right cell
	Cell getRightCell() const;
	//check if cell is above the other
	bool isAboveThen(Cell otherCell) const;
	//check if cell is under the other
	bool isUnderThen(Cell otherCell) const;
	//check if cell is left to the other
	bool isLeftTo(Cell otherCell) const;
	//check if cell is right to the other
	bool isRightTo(Cell otherCell) const;
	//check if the cell is valid
	bool isValidCell(int rowNum, int colNum) const;
	// convert to string
	virtual string toString() const;
	// overload compare operator
	bool operator == (const Cell &anotherCell);
	// overload compare operator
	bool operator != (const Cell &anotherCell);
private:
	// number of row
	int m_rowNum;
	// number of column
	int m_colNum;
};
