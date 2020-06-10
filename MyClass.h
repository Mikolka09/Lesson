#pragma once
using namespace std;


class MyClass
{
private:
	int m_Value; //поле класса
	const int m_V;

	mutable int cnt = 0;//модификатор для возможности изменения констатного метода


public:
	MyClass(): m_V(8)//конструктор без параметров + инициализ. конст. поля
	{
		cout << "Constructor" << endl;
	}
	MyClass(int v, int c): m_V(c)//конструктор с одним параметром
	{
		m_Value = v;
		cout << "Constructor 1 para" << endl;
	}
	void Print() const //метод класса
	{
		cnt++;
		cout << "Value = " << m_Value << endl;
	}

	void setValue(int v)
	{
		m_Value = v;
	}

	int getValue() const
	{
		return m_Value;
	}

	int getConst() const
	{
		return m_V;
	}
};

//все методы которые не должны модифицировать объект должны быть константы!!!
//mutable - модификатор для возможности изменения констатного метода.