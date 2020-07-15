﻿#pragma once
#include<iostream>
#include"List.h"
#include<string>
#include<iomanip>

using namespace myWorks::myList;

enum Hum { KNIGHT = 1, ARCHER, RIDER };
enum Mon { ORC = 1, GOBLIN, DRAGON };

class Race
{
protected:

	string type;
	int life;
	int damage;
	int speed;
	int gold;

public:

	Race() {}
	Race(int l, int d, int s) : life(l), damage(d), speed(s)
	{
		this->type = "";
		this->gold = rand() % 50 + 1;
	}
	void attack();
	friend ostream& operator<<(ostream& out, const Race& r);


};

//////////////////////////////////////////////////////////Расса людей
class Knight :public Race  //Рыцарь
{
public:
	Knight() :Race(80, 60, 50) { this->type = "Knight"; }
};

class Archer :public Race //Лучник
{
public:
	Archer() :Race(60, 40, 30) { this->type = "Archer"; }
};

class Rider :public Race  //Всадник
{
public:
	Rider() :Race(100, 80, 70) { this->type = "Rider"; }
};


//////////////////////////////////////////////////////////Расса монстров
class Orc :public Race
{
public:
	Orc() :Race(70, 60, 40) { this->type = "Ork"; }
};

class Goblin :public Race
{
public:
	Goblin() :Race(60, 50, 50) { this->type = "Goblin"; }
};

class Dragon :public Race
{
public:
	Dragon() :Race(100, 80, 70) { this->type = "Dragon"; }
};


class War
{
	List<Race, 10> humans;    //армия людей
	List<Race, 10> monsters;  //армия монстров
	int size = 10;            //количество воинов в одной армии
public:
	War();
	void print();
};