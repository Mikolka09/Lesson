#pragma once
#include<iostream>
#include<string>
using namespace std;


enum ERRORS
{
	SIZE_FULL,
	SIZE_EMPTY,
	OUT_OF_MEMORY,
	INVALID_INDEX,
	NULLPTR,
	OUT_OF_RANGE
};

class MyException
{
	ERRORS error_;
public:
	MyException (ERRORS e):error_(e){}
	string get_error()
	{
		switch (error_)
		{
		case SIZE_FULL:
			return "Список полный";
			break;
		case SIZE_EMPTY:
			return "Список пустой";
			break;
		case OUT_OF_MEMORY:
			return "Нехватка памяти";
			break;
		case INVALID_INDEX:
			return "Неправельный индекс";
			break;
		case NULLPTR:
			return "Список нулевой";
			break;
		case OUT_OF_RANGE:
			return "Переполнение разрядов";
			break;
		default:
			return "Не известная проблема";
			break;
		}
	}

	//Проверка на выход за пределы
	static int get_value()
	{
		int a;
		do {
			try {
				cin >> a;
				if (a == INT_MAX || a == INT_MIN)
				{
					cin.clear();
					cin.ignore(32767, '\n');
					throw MyException(OUT_OF_RANGE);
				}
				cout << a << endl;
			}
			catch (MyException &el)
			{
				cout << el.get_error() << endl;
			}
		} while (a == INT_MAX || a == INT_MIN);
		return a;
	}
};