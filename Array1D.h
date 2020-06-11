#pragma once

#include<iostream>

using namespace std;

template<class T>
class Array1D
{
	int size = 0; //размер массива
	int sizeFull = 0;//кол-во заполненных элементов
	T* arr = nullptr;

public:
	Array1D(int size);
	Array1D(const Array1D& array);
	~Array1D();

	friend ostream& operator<< <T>(ostream &out, const Array1D<T> &a);//Такой синтексис только для дружествееных методов
    friend istream& operator>> <T>(istream &in, const Array1D<T> &a);

	void print();
	void add(T elem);
	void resize(int delta);
	int getSize();
	int getsizeFull();
	void insert(T elem, int pos);
	void erase();
	void delPos(int pos);
	void getElem(int pos, T& elem, bool& error);
	void printElem(int pos);
	T operator[](int i);
};

template<class T>
ostream& operator<<(ostream &out, const Array1D<T> &a)//Такой синтексис только для дружествееных методов
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

template<class T>
istream& operator>>(istream &in, const Array1D<T> &a)
{
	int value;
	do
	{
		in >> value;
		a.add(value);
	} while (cin.peek() != '\n');
	return in;
}

template<class T>
Array1D<T>::Array1D(int size)
{
	if (size > 0)
		this->size = size;
	arr = new T[this->size];
	if (!arr)
		exit(0);
}

template<class T>
inline Array1D<T>::Array1D(const Array1D& array)
{
	size = array.size;
	sizeFull = array.sizeFull;
	arr = new T[this->size];
	memcpy(arr, array.arr, array.size * sizeof(T));
}

template<class T>
Array1D<T>::~Array1D()
{
	delete[]this->arr;
}

template<class T>
inline void Array1D<T>::print()
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

template<class T>
inline void Array1D<T>::add(T elem)
{
	if (this->sizeFull == this->size)
		resize(1);

	arr[this->sizeFull] = elem;
	this->sizeFull++;
}

template<class T>
inline void Array1D<T>::resize(int delta)
{
	if ((delta < 0 && this->size - this->sizeFull >= abs(delta)) || delta >= 0)
	{
		T* newarr = new T[this->size + delta];
		memcpy(newarr, this->arr, this->sizeFull * sizeof(T));
		delete[]this->arr;
		this->arr = newarr;
		this->size += delta;
	}
}

template<class T>
inline int Array1D<T>::getSize()
{
	return this->size;
}

template<class T>
inline int Array1D<T>::getsizeFull()
{
	return this->sizeFull;
}

template<class T>
inline void Array1D<T>::insert(T elem, int pos)
{
	if (pos > this->sizeFull - 1)
	{
		add(elem);
	}
	else
	{
		if (this->sizeFull == this->size)
			resize(1);
		memcpy(arr + pos + 1, arr + pos, (sizeFull - pos) * sizeof(T));
		arr[pos] = elem;
		this->sizeFull++;
	}
}

template<class T>
inline void Array1D<T>::erase()
{
	if (sizeFull)
	{
		T* newarr = new T[this->size];
		delete[]this->arr;
		this->arr = newarr;
		this->sizeFull = 0;
	}
}

template<class T>
inline void Array1D<T>::delPos(int pos)
{
	if (pos >= 0 && pos <= sizeFull)
	{
		T* newarr = new T[this->size - 1];
		memcpy(newarr, this->arr, pos * sizeof(T));
		//memcpy(newarr+pos, this->arr+pos+1, (this->sizeFull-pos-1) * sizeof(int));
		for (size_t i = pos + 1; i < sizeFull; i++)
			newarr[i - 1] = this->arr[i];
		delete[]this->arr;
		this->arr = newarr;
		this->size--;
		this->sizeFull--;
	}

}

template<class T>
inline void Array1D<T>::getElem(int pos, T& elem, bool& error)
{
	if (pos >= 0 && pos <= sizeFull)
	{
		elem = this->arr[pos];
		error = false;
	}
	else error = true;
}

template<class T>
inline void Array1D<T>::printElem(int pos)
{
	if (pos >= 0 && pos <= sizeFull)
		cout << this->arr[pos] << endl;
	else cout << "Элемент с таким номером не найден" << endl;
}

template<class T>
inline T Array1D<T>::operator[](int i)
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