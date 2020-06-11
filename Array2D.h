#pragma once
#include<iostream>
#include<ctime>
using namespace std;

template<class T>
class Array2D
{
private:
	int row, col;
	T**arr = nullptr;


public:
	Array2D(int, int);
	void setRandom(int min = 0, int max = 9);
	//void setRandom(int min = 0, int max = 9);
	T *operator[](int ind);
	void print();

	//friend istream& operator>> <T>(istream &in, const Array2D<T> &a);
	//friend ostream& operator<< <T>(ostream &out, const Array2D<T> &a);
	//friend ostream& operator<< (ostream &out, const Array2D<double> &a);
	~Array2D();



};

template<class T>
Array2D<T>::Array2D(int r, int c):row(r),col(c)
{
	arr = new T*[row];
	for (size_t i = 0; i < row; i++)
	{
		arr[i] = new T[col];
	}
}

template<class T>
inline void Array2D<T>::setRandom(int min, int max)
{
	cout << "All" << endl;
	srand(time(NULL));
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % (max - min + 1) + min;
		}
	}
}



template<>
inline void Array2D<double>::setRandom(int min, int max)
{
	cout << "Double" << endl;
	srand(time(NULL));
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % ((max - min + 1)*(int)pow(10, 2)) / pow(10, 2) + min;
		}
	}
}

template<class T>
inline T * Array2D<T>::operator[](int ind)
{
	return arr[ind];
}

template<class T>
ostream& operator<< (ostream &out, const Array2D<T> &a)
{
	for (size_t i = 0; i < a.row; i++)
	{
		for (size_t j = 0; j < a.col; j++)
		{
			out << a.arr[i][j] <<" ";
		}
		out << endl;
	}
	return out;
}

//template<>
//ostream& operator<< (ostream &out, const Array2D<double> &a)
//{
//	for (size_t i = 0; i < a.row; i++)
//	{
//		for (size_t j = 0; j < a.col; j++)
//		{
//			out << a.arr[i][j] << " ";
//		}
//		out << endl;
//	}
//	return out;
//}

template<class T>
istream& operator>> (istream &in, const Array2D<T> &a) 
{
	for (size_t i = 0; i < a.row; i++)
	{
		for (size_t j = 0; j < a.col; j++)
		{
			in >> a.arr[i][j];
		}
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return in;
}

template<class T>
inline void Array2D<T>::print()
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

template<class T>
Array2D<T>::~Array2D()
{
	for (size_t i = 0; i < row; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
}
