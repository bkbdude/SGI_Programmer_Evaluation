#pragma once
#include "Point2D.h"

class Rectangle
{
	public:	
		Rectangle();
		Rectangle(Point2D center);
		Rectangle(Point2D center, float width, float height);
		bool PointContainedInRectangle(Point2D);
		bool AnyPointsContainedInRectangle(Point2D[], int);
		bool RectangleIntersectRectangle(Rectangle);
		
		float TopBound()
		{
			return (height / 2) + center.y;
		}
		
		float BottomBound()
		{
			return -(height / 2) + center.y;
		}

		float RightBound()
		{
			return (width/2) + center.x;
		}

		float LeftBound()
		{
			return -(width / 2) + center.x;
		}

		Point2D TopCenterPoint()
		{
			return Point2D(center.x, TopBound());
		}

		Point2D BottomCenterPoint()
		{
			return Point2D(center.x, BottomBound());
		}

		Point2D TopRightPoint()
		{
			return Point2D(RightBound(), TopBound());
		}

		Point2D CenterRightPoint()
		{
			return Point2D(RightBound(), center.y);
		}

		Point2D BottomRightPoint()
		{
			return Point2D(RightBound(), BottomBound());
		}

		Point2D TopLeftPoint()
		{
			return Point2D(LeftBound(), TopBound());
		}

		Point2D CenterLeftPoint()
		{
			return Point2D(LeftBound(), center.y);
		}

		Point2D BottomLeftPoint()
		{
			return Point2D(LeftBound(), BottomBound());
		}

	private:
		Point2D center;
		float width, height;
		int const numberOfCorners = 4;
};

