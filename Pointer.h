#pragma once

template<class T>
class SmartPointer
{
	T* ptr;
public:
	SmartPointer(T* ptr=nullptr):ptr(ptr){}
	~SmartPointer() { delete ptr; }

	T* operator->() const { return ptr; }
	T& operator*() const { return *ptr; }

	SmartPointer(const SmartPointer& p)//конструктор копирования
	{
		ptr = new T;
		*ptr = *p.ptr;
	}

	SmartPointer(SmartPointer&& p)//конструктор перемещения
	{
		ptr = p.ptr;
		p.ptr = nullptr;
	}

	SmartPointer& operator=(SmartPointer&& p)
	{
		if (&p == this)
			return *this;
		delete ptr;
		ptr = p.ptr;
		p.ptr = nullptr;
		return *this;
	}

	SmartPointer& operator=(const SmartPointer& p)
	{
		if (&p == this)
			return *this;
		delete ptr;
		ptr = new T;
		*ptr = *p.ptr;
		return *this;
	}

};
