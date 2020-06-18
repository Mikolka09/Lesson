#pragma once
#include"MyData.h"

template<class T, int size>
class List
{
	MyData<T> *first = nullptr;
	MyData<T> *last = nullptr;
	int length = 0;
public:
	~List();
	void push_front(T val);
	void push_back(T val);
	void push_at(T val, int pos);
	T pop_front();
	T pop_back();
	T pop_at(int pos);
	T operator[](int pos);
	T peek_front();
	T peek_back();
	T peek_at(int pos);
	int getSize();
	bool ifEmpty();
	bool isFull();
	void print();
	void clear();


};

template<class T, int size>
inline List<T, size>::~List()
{
	clear();
}

template<class T, int size>
inline void List<T, size>::push_front(T val)
{
	if (length < size)
	{
		if (length == 0)
		{
			first = new MyData<T>;
			first->value = val;
			last = first;
		}
		else
		{
			MyData<T> *temp = new MyData<T>;
			temp->value = val;
			temp->next = first;
			first = temp;
		}
		length++;
	}
	else
		cout << "List overflow!" << endl;
}

template<class T, int size>
inline void List<T, size>::push_back(T val)
{
	if (length < size)
	{
		if (length == 0)
		{
			first = new MyData<T>;
			first->value = val;
			last = first;
		}
		else
		{
			MyData<T> *temp = new MyData<T>;
			temp->value = val;
			last->next = temp;
			last = temp;
		}
		length++;
	}
}

template<class T, int size>
inline void List<T, size>::push_at(T val, int pos)
{
	if (pos == 0)
		push_front(val);
	else
	{
		if (pos == length - 1)
			push_back(val);
		else
		{
			if (length < size)
			{
				MyData<T> *temp = new MyData<T>;
				temp->value = val;
				MyData<T> *num = first;
				for (size_t i = 0; i < pos - 1; i++)
				{
					num = num->next;
				}
				temp->next = num->next;
				num->next = temp;
				length++;
			}
			else
				cout << "List overflow" << endl;
		}
	}
}

template<class T, int size>
inline T List<T, size>::pop_front()
{
	
	MyData<T> *temp = first;
	first = first->next;
	T val = temp->value;
	delete temp;
	length--;
	return val;
}

template<class T, int size>
inline T List<T, size>::pop_back()
{
	MyData<T> *temp = first;
	T val = last->value;
	for (size_t i = 0; i < length - 2; i++)
	{
		temp = temp->next;
	}
	delete last;
	last = temp;
	last->next = nullptr;
	length--;
	return val;
}

template<class T, int size>
inline T List<T, size>::pop_at(int pos)
{
	if (pos == 0)
		pop_front();
	else
	{
		if (pos == length - 1)
			pop_back();
		else
		{
			MyData<T> *temp = first;
			for (size_t i = 0; i < pos - 1; i++)
			{
				temp = temp->next;
			}
			MyData<T> *num = temp->next;
			T val = num->value;
			temp->next = num->next;
			delete num;
			length--;
			return val;
		}
	}

}

template<class T, int size>
inline T List<T, size>::operator[](int pos)
{
	if (pos >= 0 && pos < length)
	{
		MyData<T> *temp = first;
		for (size_t i = 0; i < pos; i++)
		{
			temp = temp->next;
		}
		return temp->value;
	}
	return last->value;
}

template<class T, int size>
inline void List<T, size>::print()
{
	if (length == 0)
	{
		cout << "List empty" << endl;
		return;
	}
	MyData<T> *temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T, int size>
inline void List<T, size>::clear()
{
	while (length)
	{
		pop_front();
	}
	first = last = nullptr;
	cout << "List cleared!" << endl;
}
