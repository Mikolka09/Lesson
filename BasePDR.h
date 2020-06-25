#pragma once
#include<string>
#include<iostream>
#include"List.h"
#include"BTree.h"

using namespace std;

class Protocol
{
	string numTS;//номер транспортного средства
	string date;//дата нарушения
	string numPPN;//номер правил правонарушения
	string tag;//пояснение
	float sum;//сумма штрафа

public:
	Protocol(){}
	/*void setNumTS(string num) { numTS = num; }
	void setDate(string d) { date = d; }
	void setNumPPN(string num) { numPPN = num; }
	void setTag(string t) { tag = t; }
	void setSum(float s) { sum = s; }*/

	string getNumTS() { return numTS; }

	friend ostream& operator<<(ostream &out, const Protocol &p);
	friend ostream& operator<<(ostream &out, const Protocol *p);
	friend istream& operator>>(istream &in, const Protocol &p);
	friend istream& operator>>(istream &in, Protocol *p);
};

ostream& operator<<(ostream &out, const Protocol &p)
{
	out << p.numTS << " " << p.date << " " << p.numPPN << " " << p.tag << " " << p.sum << endl;
	return out;
}

ostream& operator<<(ostream &out, const Protocol *p)
{
	out << p->numTS << " " << p->date << " " << p->numPPN << " " << p->tag << " " << p->sum << endl;
	return out;
}

istream& operator>>(istream &in, Protocol *p)
{
	cout << "Номер ТС: ";   getline(in, p->numTS);
	cout << "Дата: ";       getline(in, p->date);
	cout << "Пункт ПН: ";   getline(in, p->numPPN);
	cout << "Коментарий: ";	getline(in, p->tag);
	cout << "Сумма: ";      in >> p->sum;
	return in;
}


class BasePDR
{
	List<Protocol*, 100> protocols;//список протоколов
	BTree<string, List<Protocol*, 100>> baseTS;//база транспортных средств

public:
	void menu();
	void push_protocol();
	void print();
	void find();
};

void BasePDR::menu()
{
	setlocale(0, "");
	do
	{
		system("cls");
		cout << "БАЗА ШТРАФОВ ПДР" << endl;
		cout << "----------------" << endl;
		cout << "1. Добавить протокол" << endl;
		cout << "2. Поиcк ТС" << endl;
		cout << "3. Печать" << endl;
		cout << "4. Выход" << endl;
		int n;
		cin >> n;
		cin.ignore();
		switch (n)
		{
		case 1:
			push_protocol();
			break;
		case 2:
			find();
			break;
		case 3:
			print();
			break;
		case 4:
			return;
			break;
		}

	} while (true);
	
}

inline void BasePDR::push_protocol()
{
	system("cls");
	cout << "Новый протокол" << endl;
	cout << "--------------------------------" << endl;
	Protocol *prot = new Protocol;
	cin >> prot;
	protocols.push_back(prot);
	List<Protocol*, 100>* list_TS = baseTS.get(prot->getNumTS());
	if (!list_TS)
	{
		cout << "Данный номер ТС не найден в базе и будет добавлен!" << endl;
		List<Protocol*, 100> newList_TS;
		newList_TS.push_back(prot);
		baseTS.push(prot->getNumTS(), newList_TS);
	}
	else
	{
		list_TS->push_back(prot);
		cout << "Список ПН по данному ТС обновлен!" << endl;
	}

}

inline void BasePDR::print()
{
	system("cls");
	cout << "База ПН по ТС" << endl;
	cout << "--------------------------------" << endl;
	baseTS.print();
	system("pause");
}

inline void BasePDR::find()
{
	system("cls");
	string num;
	cout << "Номер ТС: ";   getline(cin, num);
	List<Protocol*, 100> *list_TS = baseTS.get(num);
	if (!list_TS)
	{
		cout << "Данный номер ТС не найден в базе!" << endl;
		
	}
	else
	{
		list_TS->print();
	}
	system("pause");
}
