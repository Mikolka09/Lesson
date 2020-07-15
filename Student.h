#pragma once
#include<iostream>

using namespace std;

class Student
{
	char* m_name = nullptr;
	int m_age = 0;
	int* m_mark = nullptr;
	int m_sizeMark = 0;

public:
	Student();
	Student(const char* name);
	Student(int age, const char* name);
	~Student();
	void print();
	char* getName();
	void setName(char* n) {
		m_name = n;
	}
};

Student::Student() : Student("No name") {}
Student::Student(const char* name) : Student(0, name) {}
Student::Student(int age, const char* name)
{
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
	m_age = age;
}

Student::~Student()
{
	delete[]m_name;
	delete[]m_mark;
}

inline void Student::print()
{
	cout << "Name: " << m_name << endl;
	cout << "Age: " << m_age << endl;
	cout << "Mark: ";
	for (size_t i = 0; i < m_sizeMark; i++)
	{
		cout << m_mark[i] << " ";
	}
	cout << endl << endl;
}

inline char* Student::getName()
{
	return m_name;
}


/*Student st2("Ivanoff", 33);
st2.print();*/
