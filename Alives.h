#pragma once
#include<iostream>
#include"List.h"
#include<string>


class Alives
{
//protected:
	
	string luchniki = "Luchnik";
	string arbaletchiki = "Arbalet";
	int life;
	int uron;
	int zoloto;
	int kol;
	int size = 10;
	List<Alives*, 10> alives;
public:
	Alives()
	{

	}

};

//class Ricar:public Alives
//{
//	int kol_r;
//	int* ricar = nullptr;
//
//public:
//	Ricar() 
//	{ 
//		kol_r = rand() % 10 + 1;
//		life = rand() % 20 + 1;
//		uron = rand() % 20 + 1;
//		zoloto = rand() % 20 + 1;
//	}
//
//
//
//};
//
//class Luchnik :public Alives
//{
//	int kol_l;
//
//public:
//	Luchnik() 
//	{ 
//		kol_l = rand() % 10 + 1;
//		life = rand() % 20 + 1;
//		uron = rand() % 20 + 1;
//		zoloto = rand() % 20 + 1;
//	}
//};
//
//class Arbalet :public Alives
//{
//	int kol_ar;
//
//public:
//	Arbalet() 
//	{ 
//		kol_ar = rand() % 10 + 1; 
//		life = rand() % 20 + 1;
//		uron = rand() % 20 + 1;
//		zoloto = rand() % 20 + 1;
//	}
//};
