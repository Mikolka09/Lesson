#pragma once
#include<iostream>
#include<string>
using namespace std;

class Human
{
public:
	string name;
	int age;

	Human(string n = "", int a = 0) :name(n), age(a) { cout << "HUman constr" << endl; }
	void print() const
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
};


class FootballPlayer :public Human
{
public:
	int goals;
	int rating;

	FootballPlayer(string n, int a, int g = 0, int r = 0) :goals(g), rating(r), Human(n, a) { cout << "FP constr" << endl; }
	FootballPlayer(int g = 0, int r = 0) :goals(g), rating(r), Human() { cout << "FP constr" << endl; }
	void print() const
	{
		Human::print();
		cout << "Goals: " << goals << endl;
		cout << "Rating: " << rating << endl;
	}
};

class TypeFP:public FootballPlayer
{
public:
	string typeFP;
	TypeFP(string n, int a, int g, int r, string tfp):typeFP(tfp), FootballPlayer(n, a,g,r)
	{ 
		cout << "TyFP constr" << endl; 
	}
	void print() const
	{
		FootballPlayer::print();
		cout << "TypeFP: " << typeFP << endl;
	}
};
