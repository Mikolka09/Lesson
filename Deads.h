#pragma once
#include<iostream>
#include"List.h"
#include<string>


class Deads
{
//protected:
	
	int kol;
	int size = 10;
	List<int, 10> deads;
public:
	Deads()
	{
		while (size)
		{
			int vib = rand() % 3 + 1;
			switch (vib)
			{
			case 1:
				deads.push_front(orki);
			case 2:
				deads.push_front(dragon);
			case 3:
				deads.push_front(sce);
			default:
				break;
			}
			size--;
		}
	}


};

class Orki :public Deads
{
	int life_o;
	int uron_o;
	int zoloto_o;
	string orki = "Orki";
public:
	Orki() 
	{ 
		life_o = rand() % 20 + 1;
		uron_o = rand() % 20 + 1; 
		zoloto_o = rand() % 20 + 1;
	}
};

class Dragon :public Deads
{
	int life_d;
	int uron_d;
	int zoloto_d;
	string dragons = "Dragon";
public:
	Dragon() 
	{ 
		life_d = rand() % 20 + 1;
		uron_d = rand() % 20 + 1;
		zoloto_d = rand() % 20 + 1;
	}
};

class Sceleton :public Deads
{
	int life_s;
	int uron_s;
	int zoloto_s;
	string sceletons = "Scelet";
public:
	Sceleton() 
	{ 
		life_s = rand() % 20 + 1;
		uron_s = rand() % 20 + 1;
		zoloto_s = rand() % 20 + 1;
	}
};
