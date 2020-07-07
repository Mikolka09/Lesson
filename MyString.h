#pragma once
#include<iostream>
using namespace std;

class MyString
{
protected:

	int len;
	char* str;
	static int count;

public:

	static int getCount();

	MyString();
	MyString(int len);
	MyString(const char* str);

	void inputString();
	void print() const;

	MyString(const MyString& obj);
	MyString operator=(const MyString& obj);

	~MyString();

	MyString operator+(const MyString& st);
	MyString operator+=(const MyString& st);
	bool operator==(const MyString& st);
	bool operator!=(const MyString& st);

	char* getString() const;
	int getLen() const;
	void clear();

	friend ostream& operator<<(ostream& out, const MyString& s);
};


int MyString::count = 0;

int MyString::getCount()
{
	return count;
}

MyString::MyString() :MyString(80) {}

MyString::MyString(int len)
{
	this->str = new char[len + 1];
	this->str[0] = '\0';
	count++;
}

ostream& operator<<(ostream& out, const MyString& s)
{
	out << s.str;
	return out;
}

MyString::MyString(const char* str)
{
	this->len = strlen(str);
	this->str = new char[this->len + 1];
	strcpy(this->str, str);
	count++;
}

inline void MyString::inputString()
{
	char* str = new char[1024];
	cout << "Введите строку :";
	cin.getline(str, 1024);
	delete[]this->str;
	this->len = strlen(str);
	this->str = new char[this->len + 1];
	strcpy(this->str, str);
	this->len = strlen(this->str);
}

inline void MyString::print() const
{
	cout << "Вывод строки: " << getString() << endl;
}

MyString::MyString(const MyString& obj)
{
	this->len = strlen(obj.str);
	this->str = new char[this->len + 1];
	strcpy(this->str, obj.str);
}

MyString MyString::operator=(const MyString& obj)
{
	if (this->str != nullptr)
	{
		delete[]str;
	}
	this->len = strlen(obj.str);
	this->str = new char[this->len + 1];
	strcpy(this->str, obj.str);
	return *this;
}

MyString::~MyString()
{
	delete[] this->str;
	this->str = nullptr;
	this->len = 0;
	count--;
}

inline MyString MyString::operator+(const MyString& st)
{
	MyString newS;
	newS.len = this->len + st.len;
	newS.str = new char[newS.len + 1];
	for (size_t i = 0; i < this->len; i++)
	{
		newS.str[i] = this->str[i];
	}
	for (size_t i = 0, j = this->len; i < st.len; i++, j++)
	{
		newS.str[j] = st.str[i];
	}
	newS.str[newS.len] = '\0';
	this->clear();
	*this = newS;
	return *this;
}

inline MyString MyString::operator+=(const MyString& st)
{
	MyString newS;
	newS.len = this->len + st.len;
	newS.str = new char[newS.len + 1];
	for (size_t i = 0; i < this->len; i++)
	{
		newS.str[i] = this->str[i];
	}
	for (size_t i = 0, j = this->len; i < st.len; i++, j++)
	{
		newS.str[j] = st.str[i];
	}
	newS.str[newS.len] = '\0';
	this->clear();
	*this = newS;
	return *this;
}

inline bool MyString::operator==(const MyString& st)
{
	if (this->len != st.len)
		return false;
	for (size_t i = 0; i < this->len; i++)
	{
		if (this->str[i] != st.str[i])
			return false;
	}
	return true;
}

inline bool MyString::operator!=(const MyString& st)
{
	if (this->len == st.len)
		return false;
	for (size_t i = 0; i < this->len; i++)
	{
		if (this->str[i] == st.str[i])
			return false;
	}
	return true;
}

char* MyString::getString() const
{
	return this->str;
}

inline int MyString::getLen() const
{
	return strlen(this->str);
}

inline void MyString::clear()
{
	this->str[0] = '\0';
}


class BitMyString :public MyString
{
private:
	char* stM; //строка отрицательных значений
	int lnM;   //размер отрицательной строки
public:
	BitMyString() :MyString() {}
	BitMyString(int len) :MyString(len) {}
	BitMyString(char* st);
	~BitMyString();


	bool boolString(char* st); //проверка на наличие других не битовых символов
	int countM(char* st); //подсчет отрицательных элементов строки
	char* transDouble(char* st);
};


inline BitMyString::BitMyString(char* st) :MyString(st)
{
	if (boolString(st))
	{
		if (countM(st))
		{
			this->len = strlen(st);
			this->stM = new char[countM(st) + 1];
			this->str = new char[this->len + 1];
			for (size_t i = 0; i < this->len; i++)
			{
				if (st[i] < 0)
					this->stM[i] = st[i];
				else
					this->str[i] = st[i];
			}
		}
		else
		{
			transDouble(st);
			this->len = strlen(st);
			this->str = new char[this->len + 1];
			strcpy(this->str, st);
		}
	}
	else
	{
		this->str = new char[this->len + 1];
		this->str[0] = '\0';
	}
	count++;
}

bool BitMyString::boolString(char* st)
{
	int len = strlen(st);
	for (size_t i = 0; i < len; i++)
	{
		if (st[i] < '0' || st[i] > '9')
			return false;
	}
	return true;
}

inline int BitMyString::countM(char* st)
{
	int countM(0);
	int len = strlen(st);
	for (size_t i = 0; i < len; i++)
	{
		if (st[i] < 0)
			countM++;
	}
	return countM;
}

void addSimbChar(char* s, char elem)
{
	if (!strlen(s))
	{
		int ln = strlen(s);
		char* b = new char[ln + 1];
		b[ln] = elem;
		s[0] = b[ln];
	}
	else
	{
		int ln = strlen(s);
		char* b = new char[ln + 1];
		for (size_t i = 0; i < ln; i++)
		{
			b[i] = s[i];
		}
		b[ln] = elem;
		_strset(s, '\0');
		strcpy(s, b);
	}

}

char* BitMyString::transDouble(char* st)
{
	int len = strlen(st);
	char* result = new char[80];
	int k(0);
	while (len)
	{
		int i(0);
		do
		{
			if (st[i] == '0' || st[i] == '1')
				addSimbChar(result, st[i]);
			char res = ('0' + (st[i] % 2));
			if (res == '0' || res == '1')
				addSimbChar(result, res);
			st[i] = (int)st[i] / 2;
			i++;
		} while (st[i] > 0);
		len--;
	}
	return result;
}


inline BitMyString::~BitMyString()
{
	delete[]stM;
}