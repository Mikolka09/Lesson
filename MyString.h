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
	virtual void print() const;

	MyString(const MyString& obj);
	MyString operator=(const MyString& obj);

	~MyString();

	MyString operator+(const MyString& st);
	MyString operator+=(const MyString& st);
	bool operator==(const MyString& st);
	bool operator!=(const MyString& st);

	virtual char* getString() const;
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



///////////////////////////////////////////////////////////////////////////////////////////////////////


class BitMyString :public MyString
{
private:
	char* stM; //строка отрицательных значений
	int lnM;   //размер отрицательной строки
public:
	BitMyString();
	BitMyString(int len);
	BitMyString(char* st);
	~BitMyString();

	BitMyString(const BitMyString& obj);
	BitMyString operator=(const BitMyString& obj);

	virtual void print() const;
	virtual char* getString() const;
	char* getStringM() const;


	bool boolString(char* st); //проверка на наличие других не битовых символов
	int countM(char* st); //подсчет отрицательных элементов строки
	char* transDouble(char*& st);//перевод в двоичную ситему

	BitMyString operator+(const BitMyString& st);
	BitMyString operator+=(const BitMyString& st);
	bool operator==(const BitMyString& st);
	bool operator!=(const BitMyString& st);
};


inline BitMyString::BitMyString() : MyString(80) {}


inline BitMyString::BitMyString(int len) : MyString(len) {}


inline BitMyString::BitMyString(char* st)
{
	if (boolString(st))
	{
		if (countM(st))
		{
			this->len = strlen(st);
			this->stM = new char[countM(st) * 2 + 1];
			this->str = new char[(this->len - countM(st) * 2) + 1];
			this->stM[0] = '\0';
			this->str[0] = '\0';
			for (size_t i = 0; i < this->len; i++)
			{
				if (st[i] == '-')
					this->stM[i] = st[i];
				if (st[i - 1] == '-')
					this->stM[i] = st[i];
				if (st[i] != '-')
					if (st[i + 1] >= '0' || st[i + 1] <= '9' && st[i - 1] != '-')
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
		if (st[i] != '-')
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
		if (st[i] == '-')
			if (st[i + 1] >= '0' || st[i + 1] <= '9')
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
		b[ln] = elem; b[ln + 1] = '\0';
		strcpy(s, b);
	}
	else
	{
		int ln = strlen(s);
		char* b = new char[ln + 1];
		for (size_t i = 0; i < ln; i++)
		{
			b[i] = s[i];
		}
		b[ln] = elem; b[ln + 1] = '\0';
		_strset(s, '\0');
		strcpy(s, b);
	}

}

char* BitMyString::transDouble(char*& st)
{
	int len = strlen(st);
	char* result = new char[len + 1];
	result[0] = '\0';
	int i(0);
	while (len)
	{
		if (st[i] == '0' || st[i] == '1')
			addSimbChar(result, st[i]);
		else
		{
			char ss = st[i];
			bool t = true;
			while (t)
			{
				char res = ('0' + (ss % 2));
				if (res == '0' || res == '1')
					addSimbChar(result, res);
				int p = (int(ss) - (int)'0') / 2;
				ss = ('0' + ss) / 2;
				if (p == 0)
					t = false;
			}
		}
		i++;
		len--;
	}
	st = new char[strlen(result) + 1];
	strcpy(st, result);
	return st;

}

inline BitMyString BitMyString::operator+(const BitMyString& st)
{
	BitMyString newS;
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

inline BitMyString BitMyString::operator+=(const BitMyString& st)
{
	BitMyString newS;
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

inline bool BitMyString::operator==(const BitMyString& st)
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

inline bool BitMyString::operator!=(const BitMyString& st)
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


inline BitMyString::~BitMyString()
{
	delete[]stM;
	delete[]this->str;
}

inline BitMyString::BitMyString(const BitMyString& obj)
{
	this->len = strlen(obj.str);
	this->str = new char[this->len + 1];
	strcpy(this->str, obj.str);
}

inline BitMyString BitMyString::operator=(const BitMyString& obj)
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

inline void BitMyString::print() const
{
	cout << "Вывод положительной строки: " << getString() << endl;
	cout << "Вывод отрицательной строки: " << getStringM() << endl;
}

inline char* BitMyString::getString() const
{
	return this->str;
}

inline char* BitMyString::getStringM() const
{
	return this->stM;
}
