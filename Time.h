#pragma once

class Time
{
private:
	int h;//часы
	int m;//минуты
	int s;//секунды

public:
	Time();
	Time(int s);
	Time(int m, int s);
	Time(int h, int m, int s);

	Time operator+ (Time t2);
	Time operator- (Time t2);
	Time operator* (int k);

	friend Time operator* (int k, Time t);

	Time &operator++ ();
	Time &operator++ (int);
	Time &operator-- ();
	Time &operator-- (int);
	bool operator> (Time t2);
	bool operator< (Time t2);
	bool operator== (Time t2);
	bool operator!= (Time t2);
	void operator() (Time t, int f);//перегрузка вывода времени с укзанием формата

	friend ostream& operator<< (ostream &out, Time t);

	void printTo12() const;
	void printTo24() const;

	~Time();
};

ostream& operator<< (ostream &out, Time t)
{
	int temp, sek, min, hou;
	temp = t.s + t.m * 60 + t.h * 3600;
	hou = temp / 3600;
	min = (temp - hou * 3600) / 60;
	sek = temp - hou * 3600 - min * 60;
	out << "\n\n";
	out << " Время в 24 часовом формате: ";
	if (hou > 24)
	{
		int d;
		d = hou / 24;
		hou = hou - d * 24;
	}
	hou < 10 ? out << "0" << hou : out << hou;
	out << ":";
	min < 10 ? out << "0" << min : out << min;
	out << ":";
	sek < 10 ? out << "0" << sek : out << sek << endl;
	out << endl;
	return out;
}

Time::Time()
{
	this->h = 0;
	this->m = 0;
	this->s = 0;
}

inline Time::Time(int s) : Time()
{
	this->s = s;
}

inline Time::Time(int m, int s) : Time(s)
{
	this->m = m;
}

inline Time::Time(int h, int m, int s) : Time(m, s)
{
	this->h = h;
}

inline Time Time::operator+ (Time t2)
{
	Time t;
	t.h = this->h + t2.h;
	t.m = this->m + t2.m;
	t.s = this->s + t2.s;
	return t;
}

inline Time Time::operator-(Time t2)
{
	Time t;
	t.h = abs(this->h - t2.h);
	t.m = abs(this->m - t2.m);
	t.s = abs(this->s - t2.s);
	return t;
}

inline Time Time::operator*(int k)
{
	Time t;
	t.h = this->h * k;
	t.m = this->m * k;
	t.s = this->s * k;
	return t;
}

 Time operator*(int k, Time t)
{
	Time temp;
	temp.h =  k * t.h;
	temp.m =  k * t.m;
	temp.s =  k * t.s;
	return temp;
}

inline Time &Time::operator++()
{
	this->s++;
	return *this;
}

inline Time &Time::operator++(int)
{
	Time temp(this->h, this->m, this->s);
	++(*this);
	return temp;
}

inline Time & Time::operator--()
{
	this->s--;
	return *this;
}

inline Time & Time::operator--(int)
{
	Time temp(this->h, this->m, this->s);
	--(*this);
	return temp;
}

inline bool Time::operator>(Time t2)
{
	cout << boolalpha;
	return (this->h * 3600 + this->m * 60 + this->s) > (t2.h * 3600 + t2.m * 60 + t2.s);
}

inline bool Time::operator<(Time t2)
{
	cout << boolalpha;
	return (this->h * 3600 + this->m * 60 + this->s) < (t2.h * 3600 + t2.m * 60 + t2.s);
}

inline bool Time::operator==(Time t2)
{
	cout << boolalpha;
	return (this->h * 3600 + this->m * 60 + this->s) == (t2.h * 3600 + t2.m * 60 + t2.s);
}

inline bool Time::operator!=(Time t2)
{
	cout << boolalpha;
	return (this->h * 3600 + this->m * 60 + this->s) != (t2.h * 3600 + t2.m * 60 + t2.s);
}

inline void Time::operator()(Time t, int f)
{
	int s, sek, min, hou;
	s = t.s + t.m * 60 + t.h * 3600;
	hou = s / 3600;
	min = (s - hou * 3600) / 60;
	sek = s - hou * 3600 - min * 60;
	if (f == 12)
	{
		cout << "\n\n";
		cout << " Время в 12 часовом формате: ";
		if (hou > 24)
		{
			int d;
			d = hou / 24;
			hou = hou - d * 24;
		}
		if (hou >= 0 && hou < 12)
		{
			hou < 10 ? cout << "0" << hou : cout << hou;
			cout << ":";
			min < 10 ? cout << "0" << min : cout << min;
			cout << ":";
			sek < 10 ? cout << "0" << sek : cout << sek;
			cout << " AM" << endl;
			cout << endl;
		}
		else
		{
			if (hou >= 12 && hou < 24)
			{
				if (hou > 12)
					(hou - 12) < 10 ? cout << "0" << hou - 12 : cout << hou - 12;
				else
					cout << hou;
				cout << ":";
				min < 10 ? cout << "0" << min : cout << min;
				cout << ":";
				sek < 10 ? cout << "0" << sek : cout << sek;
				cout << " PM" << endl;
				cout << endl;
			}
		}
	}
	else if (f == 24)
	{
		cout << "\n\n";
		cout << " Время в 24 часовом формате: ";
		if (hou > 24)
		{
			int d;
			d = hou / 24;
			hou = hou - d * 24;
		}
		hou < 10 ? cout << "0" << hou : cout << hou;
		cout << ":";
		min < 10 ? cout << "0" << min : cout << min;
		cout << ":";
		sek < 10 ? cout << "0" << sek : cout << sek << endl;
		cout << endl;
	}
}

inline void Time::printTo12() const
{
	int t, sek, min, hou;
	t = this->s + this->m * 60 + this->h * 3600;
	hou = t / 3600;
	min = (t - hou * 3600) / 60;
	sek = t - hou * 3600 - min * 60;
	cout << "\n\n";
	cout << " Время в 12 часовом формате: ";
	if (hou > 24)
	{
		int d;
		d = hou / 24;
		hou = hou - d * 24;
	}
	if (hou >= 0 && hou < 12)
	{
		hou < 10 ? cout << "0" << hou : cout << hou;
		cout << ":";
		min < 10 ? cout << "0" << min : cout << min;
		cout << ":";
		sek < 10 ? cout << "0" << sek : cout << sek;
		cout << " AM" << endl;
		cout << endl;
	}
	else
	{
		if (hou >= 12 && hou < 24)
		{
			if (hou > 12)
				(hou - 12) < 10 ? cout << "0" << hou - 12 : cout << hou - 12;
			else
				cout << hou;
			cout << ":";
			min < 10 ? cout << "0" << min : cout << min;
			cout << ":";
			sek < 10 ? cout << "0" << sek : cout << sek;
			cout << " PM" << endl;
			cout << endl;
		}
	}

}

inline void Time::printTo24() const
{
	int t, sek, min, hou;
	t = this->s + this->m * 60 + this->h * 3600;
	hou = t / 3600;
	min = (t - hou * 3600) / 60;
	sek = t - hou * 3600 - min * 60;
	cout << "\n\n";
	cout << " Время в 24 часовом формате: ";
	if (hou > 24)
	{
		int d;
		d = hou / 24;
		hou = hou - d * 24;
	}
	hou < 10 ? cout << "0" << hou : cout << hou;
	cout << ":";
	min < 10 ? cout << "0" << min : cout << min;
	cout << ":";
	sek < 10 ? cout << "0" << sek : cout << sek << endl;
	cout << endl;
}

Time::~Time()
{
}
