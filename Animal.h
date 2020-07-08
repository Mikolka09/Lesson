#pragma once
#include<iostream>
#include<string>
using namespace std;


class Animal //final//final - закрывает дальнейшее наследование
{
protected:
	string name;
	int age;
public:
	Animal(string n, int a) : name(n), age(a) {}

	virtual string getName() { return " ??? "; }
	virtual void voice() { cout << " Я немая! "; }
	//virtual void voice() = 0; //теперь класс энимал стал абстрактный
	//виртуальная функция вызывает функции самого нижнего подкласса 
};


//inline void Animal::voice()
//{
//	cout << "Я немая!" << endl;
//}

class Dog : public Animal
{
public:
	Dog(string n, int a) :Animal(n, a) { voice(); }
	virtual string getName() override { return "Dog " + name; }
	virtual void voice() override { cout << "Gaw-Gaw" << endl; }

	//override - следит за правельностью переопределения метода
};


class Cat : public Animal
{
public:
	Cat(string n, int a) :Animal(n, a) {}
	virtual string getName() override { return "Cat " + name; }
	virtual void voice() override { cout << "Myau-Myau" << endl; }
};

class Medusa : public Animal
{
public:
	Medusa(string n, int a) :Animal(n, a) {}
	virtual string getName() override { return "Medusa " + name; }
	virtual void voice() override { Animal::voice(); }
};

class IMyErrorLog
{
public:
	virtual void open() = 0;
	virtual void writeError(string m) = 0;
	virtual string getError() = 0;
	virtual void close() = 0;
};

class ConsoleErrorLog : public IMyErrorLog
{
	string message = "no error";
public:
	ConsoleErrorLog() {}
	void close(){}
	void open(){}
	void writeError(string m) { message = m; cout << message << endl; }
	string getError() { return message; }

};


class FileErrorLog : public IMyErrorLog
{
	string fn;
	string message = "no error";
	ofstream out;
public:
	FileErrorLog(string fn) :fn(fn) {}
	void open() { out.open(fn); }
	void writeError(string m)
	{
		open();
		message = m;
		out << message << endl;
		close();
	}
	string getError() { return message; }
	void close() { out.close(); }
};