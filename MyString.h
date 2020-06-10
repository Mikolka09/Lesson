#pragma once
using namespace std;

class MyString
{
	int len;
	char* str;

public:
	MyString() :MyString(80, "") {}
	MyString(const char* str) :MyString(1, str) {}
	explicit MyString(int l) :MyString(l, "") {}
	MyString(int l, const char* str)
	{
		this->len = strlen(str);
		this->str = new char[this->len + 1];
		strcpy(this->str, str);
		//cout << "Constructor" << endl;
	}

	MyString(const MyString& obj)
	{
		this->len = strlen(obj.str);
		this->str = new char[this->len + 1];
		strcpy(this->str, obj.str);
		//cout << "Constructor copy" << endl;
	}

	MyString operator=(const MyString& obj)
	{
		this->len = strlen(obj.str);
		this->str = new char[this->len + 1];
		strcpy(this->str, obj.str);
		//cout << "Constructor copy" << endl;
		return *this;
	}

	~MyString()
	{
		delete[]str;
		//cout << "Destructor" << endl; 
	}

	char* getString()
	{
		return this->str;
	}

};
