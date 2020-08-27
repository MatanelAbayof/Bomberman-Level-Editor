#pragma once
//---- include section ------
#include <string>
#include "TableLayout.h"
#include "CharacterView.h"
#include "Cell.h"

//---- using section --------
using std::string;
using sf::Vector2i;

/*
 * LevelMap class
 */
class LevelMap :
	public TableLayout
{
public:
	// constructor, size.x = rows, size.y = cols
	LevelMap(RenderWindow &window, const Vector2i &size = Vector2i(0,0));
	// destructor
	~LevelMap();
	// for each all characters views
	void forEach(std::function<void(CharacterView&, const Cell&)> onGetCharacter) const;
	// set new map size
	void setMapSize(const Vector2i &size);
	// get character view
	CharacterView &getCharacterView(const Cell &cell) const;
	// check if have character view at
	bool haveCharViewAt(int numOfRow, int numOfCol) const;
	//get map size
	Vector2i getMapSize() const;
	// convert to string
	virtual string toString() const;
private:
	Vector2i m_size;
	// init components
	void initComponents(const Vector2i &size);
	// check if is legal level map size
	bool checkLegalSize(const Vector2i &size) const;
	// delete map
	void deleteMap();
	// allocate new map
	void allocateMap(const Vector2i &size);
	// redeclaring scope of base class functions in private section of derived class
	using TableLayout::addRow;
	using TableLayout::removeRow;
	using TableLayout::forEach;
	using TableLayout::getRow;
	using TableLayout::getView;
};

