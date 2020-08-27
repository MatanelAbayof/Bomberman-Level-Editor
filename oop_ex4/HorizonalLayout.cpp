//---- include section ------
#include "HorizonalLayout.h"

HorizonalLayout::HorizonalLayout(RenderWindow & window)
				: ViewGroup(window)
{ }

void HorizonalLayout::addView(View &view)
{
	float relativeWidth = (float)1 / (getNumOfViews() + 1);
	addView(view, relativeWidth);
	arrangeChildrens();
}

void HorizonalLayout::addView(View &view, float relativeWidth)
{
	ViewGroup::addView(view);
	if (!checkRelativeWidth(relativeWidth))
		throw string("Can't set relative width " + std::to_string(relativeWidth));
	m_relativeWidths.push_back(relativeWidth);
	updateComponents();
}

void HorizonalLayout::removeView(int index)
{
	ViewGroup::removeView(index);
	m_relativeWidths.erase(m_relativeWidths.begin() + index);
	updateComponents();
}

void HorizonalLayout::arrangeChildrens()
{
	if (getNumOfViews() > 0) {
		float relativeWidth = (float)1 / getNumOfViews();
		for (int i = 0; i < m_relativeWidths.size(); i++)
			m_relativeWidths[i] = relativeWidth;
		updateComponents();
	}
}

string HorizonalLayout::toString() const
{
	return "HorizonalLayout: view=" + ViewGroup::toString();
}

void HorizonalLayout::updateComponents()
{
	ViewGroup::updateComponents();

	if (isNoSet())
		return;

	if (getNumOfViews() > 0) {
		int childX = 0;
		int childHeight = getHeight();

		for (int i = 0; i < getNumOfViews(); i++) {
			int childWidth = (int)(m_relativeWidths[i] * getWidth());
			Vector2f childPosition(getPosition().x + childX, getPosition().y);
			View &view = getView(i);
			view.setBound(childPosition, childWidth, childHeight);

			childX += childWidth;
		}
	}	
}

bool HorizonalLayout::checkRelativeWidth(float relativeWidth) const
{
	return ((relativeWidth >= 0) && (relativeWidth <= 1));
}
