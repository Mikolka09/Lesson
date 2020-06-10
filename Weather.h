#pragma once

class Humidity;

class Temperature
{

private:

	int temp;

public:
	Temperature(int t):temp(t){}

	void print()
	{
		cout << "Temperature - " << temp << (char)248 << "C" << endl;
	}

	friend void weatherNow(Temperature t, Humidity h);

};



class Humidity
{
private:
	int humidity;
public:
	Humidity(int h):humidity(h){}

	void print()
	{
		cout << "Humidity - " << humidity << "%" << endl;
	}
	
	friend void weatherNow(Temperature t, Humidity h);
};


void weatherNow(Temperature t, Humidity h)
{
	setlocale(0, "C");
	cout << "Weather now: " << endl;
	cout << "----------------" << endl;
	cout << "Temperature - " << t.temp << (char)248 << "C" << endl;
	cout << "Humidity - " << h.humidity << "%" << endl;
	setlocale(0, "");
}