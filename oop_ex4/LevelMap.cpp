//---- include section ------
#include "LevelMap.h"
#include "CharacterView.h"

LevelMap::LevelMap(RenderWindow &window, const Vector2i &size)
	: TableLayout(window)
{
	initComponents(size);
}

LevelMap::~LevelMap()
{
	deleteMap();
}

void LevelMap::forEach(std::function<void(CharacterView&, const Cell&)> onGetCharacter) const
{
	TableLayout::forEach([&onGetCharacter](View &view, const Cell &cell) {
		CharacterView &charView = dynamic_cast<CharacterView&>(view);
		onGetCharacter(charView, cell);
	});
}

void LevelMap::setMapSize(const Vector2i &size)
{
	// delete last map
	deleteMap();
	if (!checkLegalSize(size))
		throw string("Level map not have legal size (" + std::to_string(size.x) + ", " + std::to_string(size.y) + ")");
	m_size = size;
	allocateMap(size);
}

CharacterView &LevelMap::getCharacterView(const Cell &cell) const
{
	return dynamic_cast<CharacterView&>(getView(cell));
}

bool LevelMap::haveCharViewAt(int numOfRow, int numOfCol) const
{
	return ((numOfRow >= 0) && (numOfRow < m_size.x) && (numOfCol >= 0) && (numOfCol < m_size.y));
}

Vector2i LevelMap::getMapSize() const
{
	return m_size;
}

string LevelMap::toString() const
{
	return "LevelMap: " + TableLayout::toString();
}

void LevelMap::initComponents(const Vector2i &size)
{
	getBackground().setColor(Color(255, 255, 230));
	setMapSize(size);
}

bool LevelMap::checkLegalSize(const Vector2i &size) const
{
	return ((size.x >= 0) && (size.y >= 0));
}

void LevelMap::deleteMap()
{
	int numOfRows = getNumOfRows();
	for (int rowNum = 0; rowNum < numOfRows; rowNum++) {
		// get first row
		HorizonalLayout &rowLayout = getRow(0);
		int numOfCols = rowLayout.getNumOfViews();
		for (int colNum = 0; colNum < numOfCols; colNum++) {
			// get first column
			View &colView = rowLayout.getView(0);
			// delete column view
			rowLayout.removeView(0);
			delete &colView;
		}
		// delete row
		removeRow(0);
		delete &rowLayout;
	}
}

void LevelMap::allocateMap(const Vector2i &size)
{
	for (int rowNum = 0; rowNum < size.x; rowNum++) {
		HorizonalLayout *rowLayout = new HorizonalLayout(getWindow());
		for (int colNum = 0; colNum < size.y; colNum++) {
			CharacterView *charView = new CharacterView(getWindow());
			rowLayout->addView(*charView);
		}
		addRow(*rowLayout);
	}
}
