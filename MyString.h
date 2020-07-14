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
	char* stM = new char[1]; //строка отрицательных значений
	int lnM = 0;   //размер отрицательной строки
public:
	BitMyString();
	BitMyString(int len);
	BitMyString(const char* st);
	~BitMyString();

	BitMyString(const BitMyString& obj);
	BitMyString operator=(const BitMyString& obj);

	void print() const;
	char* getString() const;
	char* getStringM() const;


	bool boolString(const char* st); //проверка на наличие других не битовых символов
	int countM(const char* st); //подсчет отрицательных элементов строки
	char* convMDouble(char elem);//перевод в двоичную систему одного отрицательного элемента
	char* convDouble(char elem);//перевод в двоичную систему одного положительного элемента
	const char* convertSTDouble(const char*& st);//перевод в двоичную ситему всей строки
	char* changeSing(char* st, char _old, char _new);//изменение знака числа на отрицательный

	BitMyString operator+(const BitMyString& st);
	BitMyString operator+=(const BitMyString& st);
	bool operator==(const BitMyString& st);
	bool operator!=(const BitMyString& st);
};


inline BitMyString::BitMyString() : MyString(80) {}


inline BitMyString::BitMyString(int len) : MyString(len) {}


inline BitMyString::BitMyString(const char* st)
{
	if (boolString(st))
	{
		if (countM(st))
		{
			int ln = strlen(st);
			this->lnM = countM(st) * 2;
			this->stM = new char[lnM + 1];
			this->len = ln - this->lnM;
			this->str = new char[this->len + 1];
			this->stM[0] = '\0';
			this->str[0] = '\0';
			for (size_t i = 0; i < ln; i++)
			{
				if (st[i] != '-' && st[i - 1] != '-')
				{
					if (st[i] >= '0' || st[i] <= '9')
						strcat(this->str, convDouble(st[i]));
				}
				else if (st[i] == '-')
				{
					if (st[i + 1] >= '0' || st[i + 1] <= '9')
						strcat(this->stM, convMDouble(st[i + 1]));
				}
			}
		}
		else
		{
			convertSTDouble(st);
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
			b[i + 1] = s[i];
		}
		b[0] = elem; b[ln + 1] = '\0';
		_strset(s, '\0');
		strcpy(s, b);
	}

}

char* BitMyString::changeSing(char* st, char _old = '0', char _new = '1')
{
	char* t = new char[1024]{ "" };
	char* s = st;
	int l = 0;
	while (l != 8)
	{
		addSimbChar(s, '0');
		l = strlen(s);
	}
	int i(0);
	while (s[i] != '\0')
	{
		if (s[i] == _old)
			s[i] = _new;
		else
			s[i] = _old;
		i++;
	}
	int ln = strlen(s);
	s[ln - 1] = _new;
	strcpy(t, s);
	return t;
}


char* BitMyString::convMDouble(char elem)
{
	char* result = new char[1];
	result[0] = '\0';
	if (elem == '0' || elem == '1')
		addSimbChar(result, elem);
	else
	{
		char ss = elem;
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
	char* r = changeSing(result);
	return r;

}

char* BitMyString::convDouble(char elem)
{
	char* result = new char[1];
	result[0] = '\0';
	if (elem == '0' || elem == '1')
		addSimbChar(result, elem);
	else
	{
		char ss = elem;
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
	return result;

}


bool BitMyString::boolString(const char* st)
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

inline int BitMyString::countM(const char* st)
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


const char* BitMyString::convertSTDouble(const char*& st)
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
	st = result;
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
	delete[]this->stM;
	this->stM = nullptr;
	this->lnM = 0;
}

inline BitMyString::BitMyString(const BitMyString& obj)
{
	this->lnM = strlen(obj.stM);
	this->stM = new char[this->lnM + 1];
	strcpy(this->stM, obj.stM);
}

inline BitMyString BitMyString::operator=(const BitMyString& obj)
{
	if (this->stM != nullptr)
	{
		delete[]stM;
	}
	this->lnM = strlen(obj.stM);
	this->stM = new char[this->lnM + 1];
	strcpy(this->stM, obj.stM);
	return *this;
}

inline void BitMyString::print() const
{
	cout << endl;
	if (this->len == 0)
		cout << "Положительных элементов в побитовой строке нет!" << endl << endl;
	else
		cout << "Вывод положительной побитовой строки: " << getString() << endl << endl;
	if (this->lnM == 0)
		cout << "Отрицательных элементов в побитовой строке нет!" << endl << endl;
	else
		cout << "Вывод отрицательной побитовой строки: " << getStringM() << endl << endl;
}

inline char* BitMyString::getString() const
{
	return this->str;
}

inline char* BitMyString::getStringM() const
{
	return this->stM;
}
