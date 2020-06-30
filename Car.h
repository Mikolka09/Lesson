#pragma once
#include<iostream>
#include<string>
using namespace std;

class Engin
{
	int porshen;

public:
	Engin(int p):porshen(p){ cout << "Engine constroy" << endl; }
	~Engin() { cout << "Engine destroy" << endl; }
	void print()
	{
		cout << "Porshhey: " << porshen << endl;
	}
};

class Car
{
	string name;
	Engin *en;

public:
	Car(string n, Engin *p):name(n), en(p){ cout << "Car constroy" << endl; }
	~Car() { cout << "Car destroy" << endl; }
	void print()
	{
		cout << name << endl;
		en->print();
	}
};
