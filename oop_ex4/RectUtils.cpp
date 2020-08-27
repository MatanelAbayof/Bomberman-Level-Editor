//---- include section ------
#include "RectUtils.h"

FloatRect RectUtils::createFloatRect(const Vector2f & position, int width, int height)
{
	return FloatRect(position.x, position.y, (float) width, (float) height);
}

IntRect RectUtils::createIntRect(const FloatRect &floatRect)
{
	return IntRect((int)floatRect.left, (int)floatRect.top, (int)floatRect.width, (int)floatRect.height);
}

bool RectUtils::rectInAnother(const FloatRect &rect1, const FloatRect &rect2)
{
	return  ((rect1.left + rect1.width) <= (rect2.left + rect2.width) &&
			(rect1.left >= rect2.left) && (rect1.top >= rect2.top) &&
			(rect1.top + rect1.height) <= (rect2.top + rect2.height));
}
