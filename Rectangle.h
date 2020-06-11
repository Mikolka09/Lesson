#pragma once
#include"Point.h"

class Rectangle
{
private:
	Point m_p1, m_p2;
public:
	Rectangle(Point p1, Point p2 = { 0,0 });
	~Rectangle();
	void setCoord(Point p1, Point p2);
	void operator()(Point p1, Point p2);
	void operator()(int a, int b, int c, int d);
	int Perimetr();



};

Rectangle::Rectangle(Point p1, Point p2)
{
	m_p1 = p1;
	m_p2 = p2;
}

Rectangle::~Rectangle()
{
}

void Rectangle::setCoord(Point p1, Point p2)
{
	m_p1 = p1;
	m_p2 = p2;
}

inline void Rectangle::operator()(Point p1, Point p2)
{
	m_p1 = p1;
	m_p2 = p2;
}

inline void Rectangle::operator()(int a, int b, int c, int d)
{

}

int Rectangle::Perimetr()
{
	return ((abs(m_p1.getX() - m_p2.getX()) + abs(m_p1.getY() - m_p2.getY())) * 2);
}
