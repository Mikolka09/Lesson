#pragma once

#include<iostream>

using namespace std;

class Array1D
{
	int size = 0; //размер массива
	int sizeFull = 0;//кол-во заполненных элементов
	int* arr = nullptr;

public:
	Array1D(int size);
	Array1D(const Array1D& array);
	~Array1D();

	friend ostream& operator<<(ostream &out, Array1D a);
	friend istream& operator>>(istream &in, Array1D &a);

	void print();
	void add(int elem);
	void resize(int delta);
	int getSize();
	int getsizeFull();
	void insert(int elem, int pos);
	void erase();
	void delPos(int pos);
	void getElem(int pos, int& elem, bool& error);
	void printElem(int pos);
	int operator[](int i);
};

ostream& operator<<(ostream &out, Array1D a)
{
	if (a.sizeFull)
	{
		for (size_t i = 0; i < a.sizeFull; i++)
		{
			out << a.arr[i] << " ";
		}
	}
	else out << "массив пуст" << endl;
	return out;
}

istream& operator>>(istream &in, Array1D &a)
{
	int value;
	do
	{
		in >> value;
		a.add(value);
	} while (cin.peek() != '\n');
	return in;
}

Array1D::Array1D(int size)
{
	if (size > 0)
		this->size = size;
	arr = new int[this->size];
	if (!arr)
		exit(0);
}

inline Array1D::Array1D(const Array1D& array)
{
	size = array.size;
	sizeFull = array.sizeFull;
	arr = new int[this->size];
	memcpy(arr, array.arr, array.size * sizeof(int));
}


Array1D::~Array1D()
{
	delete[]this->arr;
}

inline void Array1D::print()
{
	if (this->sizeFull)
	{
		for (size_t i = 0; i < this->sizeFull; i++)
		{
			cout << this->arr[i] << " ";
		}
		cout << endl;
	}
	else cout << "массив пуст" << endl;
}

inline void Array1D::add(int elem)
{
	if (this->sizeFull == this->size)
		resize(1);

	arr[this->sizeFull] = elem;
	this->sizeFull++;
}

inline void Array1D::resize(int delta)
{
	if ((delta < 0 && this->size - this->sizeFull >= abs(delta)) || delta >= 0)
	{
		int* newarr = new int[this->size + delta];
		memcpy(newarr, this->arr, this->sizeFull * sizeof(int));
		delete[]this->arr;
		this->arr = newarr;
		this->size += delta;
	}
}

inline int Array1D::getSize()
{
	return this->size;
}

inline int Array1D::getsizeFull()
{
	return this->sizeFull;
}

inline void Array1D::insert(int elem, int pos)
{
	if (pos > this->sizeFull - 1)
	{
		add(elem);
	}
	else
	{
		if (this->sizeFull == this->size)
			resize(1);
		memcpy(arr + pos + 1, arr + pos, (sizeFull - pos) * sizeof(int));
		arr[pos] = elem;
		this->sizeFull++;
	}
}

inline void Array1D::erase()
{
	if (sizeFull)
	{
		int* newarr = new int[this->size];
		delete[]this->arr;
		this->arr = newarr;
		this->sizeFull = 0;
	}
}

inline void Array1D::delPos(int pos)
{
	if (pos >= 0 && pos <= sizeFull)
	{
		int* newarr = new int[this->size - 1];
		memcpy(newarr, this->arr, pos * sizeof(int));
		//memcpy(newarr+pos, this->arr+pos+1, (this->sizeFull-pos-1) * sizeof(int));
		for (size_t i = pos + 1; i < sizeFull; i++)
			newarr[i - 1] = this->arr[i];
		delete[]this->arr;
		this->arr = newarr;
		this->size--;
		this->sizeFull--;
	}

}

inline void Array1D::getElem(int pos, int& elem, bool& error)
{
	if (pos >= 0 && pos <= sizeFull)
	{
		elem = this->arr[pos];
		error = false;
	}
	else error = true;
}

inline void Array1D::printElem(int pos)
{
	if (pos >= 0 && pos <= sizeFull)
		cout << this->arr[pos] << endl;
	else cout << "Элемент с таким номером не найден" << endl;
}

inline int Array1D::operator[](int i)
{
	return arr[i];
}



//void foo(Array1D arr)
//{
//	cout << "Foo" << endl;
//	arr.print();
//}
//Array1D arr1(-3);
//arr1.add(5);
//arr1.add(3);
//arr1.add(9);
//arr1.print();
//arr1.erase();
//arr1.print();
//arr1.add(2);
//arr1.add(6);
//arr1.print();
////arr1.resize(5);
//cout << "всего - " << arr1.getSize() << endl;
//cout << "заполнено - " << arr1.getsizeFull() << endl;
//arr1.delPos(2);
//arr1.print();

//cout << arr1[2] << endl;

//cout << "всего - " << arr1.getSize() << endl;
//cout << "заполнено - " << arr1.getsizeFull() << endl;

/*Array1D a(3);
cin >> a;
cout << a << endl;

cout << a.getSize() << endl;
cout << a.getsizeFull() << endl;*/