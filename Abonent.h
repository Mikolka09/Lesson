#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
class Abonent
{
	char* name = nullptr;
	char* mobTel = nullptr;
	char* homeTel = nullptr;


public:
	Abonent();
	Abonent(const char* name);
	Abonent(const char* name, const char* mobTel);
	Abonent(const char* name, const char* mobTel, const char* homeTel);
	Abonent(const Abonent& abon);
	Abonent operator=(const Abonent& obj);
	~Abonent();
	char* getName();
	char* getMobTel();
	char* getHomeTel();
	void print();


};


inline Abonent::Abonent() : Abonent("no name", "no tel", "no tel") {};
inline Abonent::Abonent(const char* name) : Abonent(name, "no tel", "no tel") {}
inline Abonent::Abonent(const char* name, const char* mobTel) : Abonent(name, mobTel, "no tel") {};
inline Abonent::Abonent(const char* name, const char* mobTel, const char* homeTel)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	bool flag = 1;
	for (size_t i = 0; i < strlen(mobTel); i++)
	{
		if (!(mobTel[i] == 40 || mobTel[i] == 41 || mobTel[i] == 45
			|| mobTel[i] >= 48 && mobTel[i] <= 57))
			flag = 0;
	}
	if (flag == 1)
	{
		this->mobTel = new char[strlen(mobTel) + 1];
		strcpy(this->mobTel, mobTel);
	}
	else
	{
		this->mobTel = new char[7];
		strcpy(this->mobTel, "no tel");
	}
	flag = 1;
	for (size_t i = 0; i < strlen(homeTel); i++)
	{
		if (!(homeTel[i] == 40 || homeTel[i] == 41 || homeTel[i] == 45
			|| homeTel[i] >= 48 && homeTel[i] <= 57))
			flag = 0;
	}
	if (flag == 1)
	{
		this->homeTel = new char[strlen(homeTel) + 1];
		strcpy(this->homeTel, homeTel);
	}
	else
	{
		this->homeTel = new char[7];
		strcpy(this->homeTel, "no tel");
	}
}

inline Abonent::Abonent(const Abonent& abon)
{
	name = new char[strlen(abon.name) + 1];
	memcpy(name, abon.name, (strlen(abon.name) + 1) * sizeof(char));
	mobTel = new char[strlen(abon.mobTel) + 1];
	memcpy(mobTel, abon.mobTel, (strlen(abon.mobTel) + 1) * sizeof(char));
	homeTel = new char[strlen(abon.homeTel) + 1];
	memcpy(homeTel, abon.homeTel, (strlen(abon.homeTel) + 1) * sizeof(char));
}

inline Abonent Abonent::operator=(const Abonent& obj)
{
	name = new char[strlen(obj.name) + 1];
	memcpy(name, obj.name, (strlen(obj.name) + 1) * sizeof(char));
	mobTel = new char[strlen(obj.mobTel) + 1];
	memcpy(mobTel, obj.mobTel, (strlen(obj.mobTel) + 1) * sizeof(char));
	homeTel = new char[strlen(obj.homeTel) + 1];
	memcpy(homeTel, obj.homeTel, (strlen(obj.homeTel) + 1) * sizeof(char));

	return *this;
}

Abonent::~Abonent()
{
	delete[]this->name;
	delete[]this->mobTel;
	delete[]this->homeTel;
}

inline char* Abonent::getName()
{
	return this->name;
}

inline char* Abonent::getMobTel()
{
	return this->mobTel;
}

inline char* Abonent::getHomeTel()
{
	return this->homeTel;
}

inline void Abonent::print()
{
	cout << setw(20) << this->name << setw(15) << this->mobTel << setw(15) << this->homeTel << endl;
}