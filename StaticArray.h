#pragma once

template<class T, int size>//тип параметров notipe
class StaticArray
{
private:
	T arr[size];
public:
	StaticArray()
	{

	}
	~StaticArray()
	{

	}

	void print()
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	
	T &operator[](int i)
	{
		return arr[i];
	}
};


