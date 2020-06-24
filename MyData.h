#pragma once

enum Priorety{LOW,MEDIUM, HIGH};

template<class T>
class MyData
{
public:
	T value;
	MyData *next =nullptr;
	MyData *prev= nullptr;
	Priorety pre = LOW;

	



};

