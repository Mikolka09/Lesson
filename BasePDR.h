#pragma once
#include<string>
#include<iostream>
#include"List.h"
#include"BTree.h"
#include<fstream>
#include<iomanip>


using namespace myWorks::myList;
using namespace myWorks::myBtree;
using namespace std;

class Protocol
{
	string numTS;//номер транспортного средства
	string date;//дата нарушения
	string numPPN;//номер правил правонарушения
	string tag;//пояснение
	float sum;//сумма штрафа
	string plata = "-";//показатель оплаты протокола
	

public:
	Protocol() {}
	/*void setNumTS(string num) { numTS = num; }
	void setDate(string d) { date = d; }
	void setNumPPN(string num) { numPPN = num; }
	void setTag(string t) { tag = t; }
	void setSum(float s) { sum = s; }
	void setPlata(string pl) { plata = pl; }*/

	
	string getNumTS() { return numTS; }
	void setPlata(string pl) { plata = pl; }


	friend ostream& operator<<(ostream& out, const Protocol& p);
	friend ostream& operator<<(ostream& out, const Protocol* p);
	friend istream& operator>>(istream& in, const Protocol& p);
	friend istream& operator>>(istream& in, Protocol* p);
	friend ofstream& operator<<(ofstream& out, const Protocol& p);//для сохранения в текстовый фаил
	friend ifstream& operator>>(ifstream& in, Protocol* p);//для выгрузки из фаила
};

ostream& operator<<(ostream& out, const Protocol& p)
{
	out << setw(10) << p.numTS << setw(14) << p.date << setw(8) << p.numPPN << setw(12) << p.tag << setw(10) << p.sum << setw(4) << p.plata << endl;
	return out;
}

ostream& operator<<(ostream& out, const Protocol* p)
{
	out << setw(10) << p->numTS << setw(14) << p->date << setw(8) << p->numPPN << setw(12) << p->tag << setw(10) << p->sum << setw(4) << p->plata << endl;
	return out;
}

istream& operator>>(istream& in, Protocol* p)
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
	void shapka();
	void payProtocol();
	void save();
	void load();
};

void BasePDR::menu()
{
	//load();
	do
	{
		system("cls");
		cout << "БАЗА ШТРАФОВ ПДР" << endl;
		cout << "----------------" << endl;
		cout << "1. Добавить протокол" << endl;
		cout << "2. Поиcк ТС" << endl;
		cout << "3. Оплатить протокол" << endl;
		cout << "4. Печать на экран" << endl;
		cout << "5. Сохранить в фаил" << endl;
		cout << "6. Выход" << endl;
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
			payProtocol();
			break;
		case 4:
			print();
			break;
		case 5:
			save();
			break;
		case 6:
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
	Protocol* prot = new Protocol;
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
	system("pause");
}

inline void BasePDR::print()
{
	system("cls");
	cout << "\t\tБаза ПН по ТС" << endl;
	shapka();
	baseTS.print();
	system("pause");
}

inline void BasePDR::find()
{
	system("cls");
	string num;
	cout << "Номер ТС: ";   getline(cin, num);
	List<Protocol*, 100>* list_TS = baseTS.get(num);
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

inline void BasePDR::shapka()
{
	string S(62, '-');
	cout << S << endl;
	cout << setw(10) << "Номер ТС" << setw(12) << "Дата" << setw(13) << "Пункт ПН" << setw(11) << "Комент." << setw(8) << "Сумма" << setw(8) << "Оплата" << endl;
	cout << S << endl;
}

inline void BasePDR::payProtocol()
{
	system("cls");
	string S(62, '-');
	cout << "Оплата протокола" << endl;
	cout << "-------------------------" << endl;
	string num;
	cout << "Введите номер ТС: ";   getline(cin, num);
	List<Protocol*, 100>* list_TS = baseTS.get(num);
	if (!list_TS)
	{
		cout << "Данный номер ТС не найден в базе!" << endl;
	}
	else
	{
		system("cls");
		cout << "\t\tОплата протокола" << endl;
		shapka();
		list_TS->print();
		cout << S << endl << endl;
		int pos;
		cout << "Введите порядковый номер протокола: ";  cin >> pos;
		Protocol* protocolP = list_TS->pop_at(pos - 1);
		int pl;
		system("cls");
		cout << endl;
		cout << "\tЖелаете оплатить этот протокол (ДА - 1, НЕТ - 0): " << endl << endl;
		shapka();
		cout << protocolP << endl;
		cout << S << endl << endl;
		cin >> pl;
		if (pl = 1)
		{
			protocolP->setPlata("+");
			cout << S << endl;
			cout << "\tПротокол оплачен!" << endl << endl;
			list_TS->push_back(protocolP);
			system("pause");
		}
		else if (pl = 0)
		{
			menu();
		}

	}
}

//inline void BasePDR::save()
//{
//	ofstream fout("Base.bin", ios::binary | ios::out);
//	if (fout.is_open())
//	{
//		int length = protocols.getSize();
//		Protocol* prot = new Protocol;
//		fout.write((char*)&length, sizeof(int));
//		while (length != 0)
//		{
//			prot = protocols.pop_front();
//			fout.write((char*)&prot, sizeof(Protocol));
//			length--;
//		}
//	}
//	fout.close();
//}

inline void BasePDR::save()
{
	ofstream fout("Base.txt", ios::binary | ios::out);
	int length = protocols.getSize();
	for (size_t i = 0; i < length; i++)
	{
		out << setw(10) << p.numTS << setw(14) << p.date 
			<< setw(8) << p.numPPN << setw(12) << p.tag 
			<< setw(10) << p.sum << setw(4) << p.plata << endl;
	}
}

inline void BasePDR::load()
{
	ifstream in("Base.bin", ios::binary | ios::in);
	if (in.is_open())
	{
		Protocol* prot = new Protocol;
		int length;
		in.read((char*)&length, sizeof(int));
		while (length != 0)
		{
			in.read((char*)&prot, sizeof(Protocol));
			this->protocols.push_back(prot);
			this->baseTS.push(prot->getNumTS(), this->protocols);
			length--;
		}

	}
	in.close();
}
