#pragma once
#include<iostream>

using namespace std;

class MyData
{
private:
	int m_day, m_month, m_year;

public:
	MyData() :m_day(1), m_month(1), m_year(1900)
	{

	}
	MyData(int d, int m, int y)
	{
		if (d > 0 && d <= 31)
			m_day = d;
		else
		{
			cout << "Data error" << endl;
			return;
		}
		m_month = m;
		m_year = y;
	}

	void Print()
	{
		cout << m_day << "." << m_month << "." << m_year << endl;
	}
};
