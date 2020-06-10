#pragma once
#include<iostream>

using namespace std;

class MyDate
{
public:
	MyDate()// :m_day(1), m_month(1), m_year(1900)
	{

	}
	MyDate(int d, int m, int y)
	{
		if (d > 0 && d <= 31)
			m_day = d;
		else
		{
			cout << "Date error" << endl;
			return;
		}
		m_month = m;
		m_year = y;
	}
	void print()
	{
		cout << m_day << "." << m_month << "." << m_year << endl;
	}


private:
	int m_day = 1, m_month = 1, m_year = 1900;
};
