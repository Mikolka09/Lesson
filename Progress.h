#pragma once

class Progress
{
private:

	int a0 = 1;
	int step = 1;


public:
	Progress();
	Progress(int a0, int step);
	int operator[](int n);
	Progress operator+(const Progress &p);
	Progress operator-(const Progress &p);
	int summa(int n);
	bool operator==(const Progress &p);
	bool operator!=(const Progress &p);
	bool isElem(int elem);
	void print(int n);
	~Progress();



};

Progress::Progress()
{
}

inline Progress::Progress(int a0, int step)
{
	this->a0 = a0;
	this->step = step;
}

inline int Progress::operator[](int n)
{
	return a0 + step*(n - 1);
}

inline Progress Progress::operator+(const Progress & p)
{
	Progress temp;
	temp.a0 = this->a0 + p.a0;
	temp.step = this->step + p.step;
	return temp;
}

inline Progress Progress::operator-(const Progress & p)
{
	Progress temp;
	temp.a0 = this->a0 - p.a0;
	temp.step = this->step - p.step;
	return temp;
}

inline int Progress:: summa(int n)
{
	return (2 * a0 + step*(n - 1))*n / 2;
}

inline bool Progress::operator==(const Progress & p)
{
	cout << boolalpha;
	return (this->a0 == p.a0 && this->step == step);
}

inline bool Progress::operator!=(const Progress & p)
{
	cout << boolalpha;
	return (this->a0 != p.a0 && this->step != step);;
}

inline bool Progress::isElem(int value)
{
	int elem = a0;
	while (value < step)
	{
		elem += step;
	} 
	cout << boolalpha;
	return value == step;
}

inline void Progress::print(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a0 + step*i << " ";
	}
	cout << endl;
}

Progress::~Progress()
{
}
