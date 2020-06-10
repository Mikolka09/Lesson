#pragma once
using namespace std;

class Point
{
	int m_x;
	int m_y;

public:
	Point() :Point(0, 0) {}
	explicit Point(int x) :m_x(x), m_y(0) {}
	Point(int x, int y) :m_x(x), m_y(y) { /*cout << "Constructor" << endl;*/ }

	~Point() // деструктор
	{
		//print();
		//cout << "Destructor" << endl;
	}

	void setCoord(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	void operator()(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	void print()
	{
		cout << "X = " << m_x << ", Y = " << m_y << endl;
	}
	/*int GetX()
	{
		return m_x;
	}
	int GetY()
	{
		return m_y;
	}*/

	friend void print2(Point p);
};


void print2(Point p)
{
	cout << "(" << p.m_x << ", " << p.m_y << ")" << endl;
}

// инициализация динамических переменных
//Point p1[2] = { Point(), Point(2,5) };

/*Point *p2 = new Point();
p2->print();*/

/*Point *p3 = new Point[2]{ Point(2,5), Point() };
p3[0].print();
p3[1].print();*/

/*Point *p4 = new Point[2];
p4[0] = Point();
p4[1] = Point(3, 8);
p4[0].print();
p4[1].print();
delete[]p4;*/


#pragma once
#include"Point.h"
class Rectangle
{
	Point m_p1, m_p2;


public:
	Rectangle(Point p1, Point p2 = { 0,0 });
	~Rectangle();
	void setCoord(Point p1, Point p2);
	int Perimetr();
	void operator()(Point p1, Point p2);
	void operator()(int x1, int y1, int x2, int y2);
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

//int Rectangle::Perimetr()
//{
//	return ((abs(m_p1.GetX() - m_p2.GetX()) + abs(m_p1.GetY() - m_p2.GetY())) * 2);
//}

inline void Rectangle::operator()(Point p1, Point p2)
{
	m_p1 = p1;
	m_p2 = p2;
}

inline void Rectangle::operator()(int x1, int y1, int x2, int y2)
{
	m_p1 = Point(x1, y1);
	m_p2 = Point(x2, y2);
}


//Rectangle r1({ 2,3 }, { 3,5 });
////r1.setCoord({ 7,8 }, { 2,10 });
//Rectangle r2({ 2,2 });
//cout << r2.Perimetr() << endl;

