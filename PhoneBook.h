#pragma once
#include"Abonent.h"
class PhoneBook
{
	Abonent* book = nullptr;
	int size;

public:
	PhoneBook();
	PhoneBook(int size);
	PhoneBook(const PhoneBook& book);
	~PhoneBook();
	void print();
	void add(const char* name, const char* mobTel, const char* homeTel);
	void del();
	void scan();
	void scanName();
	void scanMobTel();
	void scanHomeTel();
	void menu();
};

PhoneBook::PhoneBook() :PhoneBook(0) {};
inline PhoneBook::PhoneBook(int size)
{
	book = new Abonent[size];
	this->size = size;
}

inline PhoneBook::PhoneBook(const PhoneBook& Book)
{
	this->size = Book.size;
	this->book = new Abonent[Book.size];
	memcpy(this->book, Book.book, Book.size * sizeof(Abonent));
}

PhoneBook::~PhoneBook()
{
	delete[]book;
}

inline void PhoneBook::print()
{
	cout << setw(35) << "Òåëåôîííûé ñïðàâî÷íèê" << endl << endl;
	cout << "------------------------------------------------------" << endl;
	cout << "|" << setw(12) << "ÔÈÎ" << "        |" << setw(16) << "ìîá. òåëåôîí |" << setw(16) << "äîì. òåëåôîí |" << endl;
	cout << "------------------------------------------------------" << endl;
	for (size_t i = 0; i < this->size; i++)
	{
		this->book[i].print();
	}
	cout << "------------------------------------------------------" << endl;
}

inline void PhoneBook::add(const char* name, const char* mobTel, const char* homeTel)
{
	Abonent abon(name, mobTel, homeTel);
	Abonent* NewBook = new Abonent[this->size + 1];
	if (this->size > 0)
	{
		//memcpy(NewBook, this->book, (this->size) * sizeof(Abonent));
		for (size_t i = 0; i < this->size; i++)
		{
			NewBook[i] = this->book[i];
		}
		delete[] this->book;
	}
	NewBook[this->size] = abon;
	this->book = NewBook;
	this->size += 1;

};

inline void PhoneBook::del()
{
}

inline void PhoneBook::scan()
{
}

inline void PhoneBook::scanName()
{
}

inline void PhoneBook::scanMobTel()
{
}

inline void PhoneBook::scanHomeTel()
{
}

inline void PhoneBook::menu()
{
}


/*PhoneBook p;
p.add("asdasd", "312313", "23234234");
p.print();*/#pragma once
