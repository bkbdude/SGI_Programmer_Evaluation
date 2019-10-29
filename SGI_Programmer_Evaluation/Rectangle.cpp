#include "Rectangle.h"
#include "Point2D.h"

Rectangle::Rectangle()
{
	center = Point2D(0,0);
	width = 1;
	height = 1;
}

Rectangle::Rectangle(Point2D center) : center(center) 
{
	width = 1;
	height = 1;
}

Rectangle::Rectangle(Point2D center, float width, float height) : center(center), width(width), height(height) {}

bool Rectangle::PointContainedInRectangle(Point2D point) 
{
	return (point.x >= LeftBound() && point.x <= RightBound()) && 
		   (point.y >= BottomBound() && point.y <= TopBound());
}

bool Rectangle::AnyPointsContainedInRectangle(Point2D points[], int numOfPoints)
{
	for (int i = 0; i < numOfPoints; i++)
	{
		if (PointContainedInRectangle(points[i]))
		{
			return true;
		}
	}

	return false;
}

bool Rectangle::RectangleIntersectRectangle(Rectangle other)
{
	Point2D corners[] { TopLeftPoint(), TopRightPoint(), BottomLeftPoint(), BottomRightPoint() };
	Point2D otherCorners[] { other.TopLeftPoint(), other.TopRightPoint(), other.BottomLeftPoint(), other.BottomRightPoint() };

	if (AnyPointsContainedInRectangle(otherCorners, other.numberOfCorners) ||
		other.AnyPointsContainedInRectangle(corners, numberOfCorners)
		)
	{
		return true;
	}

	return false;
}