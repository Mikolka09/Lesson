#pragma once
#include<iostream>
#include<string>
using namespace std;


enum ERRORS;


class MyException
{
protected:
	ERRORS error_;
public:
	MyException (ERRORS e):error_(e){}

	enum ERRORS
	{
		SIZE_FULL,
		SIZE_EMPTY,
		OUT_OF_MEMORY,
		INVALID_INDEX,
		NULLPTR,
		OUT_OF_RANGE,
		DEL_NULL,
	};

		
};

class MyListException : public MyException
{

public:
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
					throw MyException::ERRORS(OUT_OF_RANGE);
				}
				cout << a << endl;
			}
			catch (MyListException& el)
			{
				cout << el.get_error() << endl;
			}
		} while (a == INT_MAX || a == INT_MIN);
		return a;
	}

};

class MyStackException :MyException
{
public:
	string get_error()
	{
		switch (error_)
		{
		case SIZE_FULL:
			return "Стэк полный";
			break;
		case SIZE_EMPTY:
			return "Стэк пустой";
			break;
		case NULLPTR:
			return "Стэк нулевой";
			break;
		default:
			return "Не известная проблема";
			break;
		}
	}
};

class MyArrayException :MyException
{
public:
	string get_error()
	{
		switch (error_)
		{
		case SIZE_FULL:
			return "Массив полный";
			break;
		case SIZE_EMPTY:
			return "Массив пустой";
			break;
		case OUT_OF_MEMORY:
			return "Нехватка памяти";
			break;
		case INVALID_INDEX:
			return "Неправельный индекс";
			break;
		case NULLPTR:
			return "Массив нулевой";
			break;
		default:
			return "Не известная проблема";
			break;
		}
	}

};

class MyQueueException :MyException
{
public:
	string get_error()
	{
		switch (error_)
		{
		case SIZE_FULL:
			return "Очередь полная";
			break;
		case SIZE_EMPTY:
			return "Очередь пустая";
			break;
		case NULLPTR:
			return "Очередь нулевая";
			break;
		default:
			return "Не известная проблема";
			break;
		}
	}
};

class MyMathException :MyException
{
public:
	string get_error()
	{
		switch (error_)
		{
		case OUT_OF_RANGE:
			return "Переполнение разрядов";
			break;
		case DEL_NULL:
			return "Деление на ноль";
			break;
		default:
			return "Не известная проблема";
			break;
		}
	}
};