#pragma once
#include<iostream>

using namespace std;

class B;

class A
{
	B b;
	int a;
public:
	A() { cout << "Constructor A" << endl;  }
	A(int aa) :a(aa) { cout << "Constructor A 2" << endl; }
	~A() { cout << "Destructor A" << endl; }
	friend class B;
	friend class C;
};

class B
{
	A a;
public:
	B() { cout << "Constructor B" << endl; }
	B(A aa) :a(aa) { cout << "Constructor B 2" << endl; }
	~B() { cout << "Destructor B" << endl;  }
	friend class C;
};

class C
{
	A a;
	B b;
public:
	C() { cout << "Constructor C" << endl; }
	C(int aa) :b(aa) { cout << "Constructor C 2" << endl; }
	~C() { cout << "Destructor C" << endl; }

};

//Проверка работы