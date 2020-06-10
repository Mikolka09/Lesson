#pragma once

class Counter
{
	int a;
	static int count; // статическая переменная, единая для всех экз класса
public:
	Counter() { count++; }
	static int getCount() // статический метод
	{
		//a = count; // плохо
		return count;
	}
};

int Counter::count = 0; // инициализация статического поля


	//Counter c1;
	//cout << c1.getCount() << endl;

	////Counter c2;
	//
	//cout << Counter::getCount() << endl;
	//// вызов на прямую и через объект
