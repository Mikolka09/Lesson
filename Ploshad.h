#pragma once

#include<iostream>
#include<string>
using namespace std;

class Figura
{
public:
	virtual int ploshad() = 0;
};

class Kvadrat:public Figura
{
	int a;
public:
	Kvadrat(int a) :a(a) {}
	virtual double ploshad(int a)  { return pow(a, 2); }

};

class Krug:public Figura
{
	int d;
	int pi;
public:
	Krug(int d, int pi=3.14) :d(d) {}
	virtual double ploshad(int d)  { return pi*pow(d, 2) / 4; }
};

class Pryamoygolnik:public Figura
{
	int a;
	int b;
public:
	Pryamoygolnik(int a, int b):a(a), b(b) {}
	virtual double ploshad(int a, int b) { return a*b; }
};



