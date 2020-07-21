#pragma once

template<class T>
class My_unique_ptr
{
	T* ptr;
public:
	My_unique_ptr(T* p = nullptr) :ptr(p) {}
	~My_unique_ptr() { delete ptr; }

	T* operator->() const { return ptr; }
	T& operator*() const { return *ptr; }

	My_unique_ptr(My_unique_ptr&& p)
	{
		ptr = p.ptr;
		p.ptr = nullptr;
	}

	My_unique_ptr& operator=(const My_unique_ptr&& p)
	{
		if (&p == this)
			return *this;
		delete ptr;
		ptr = p.ptr;
		p.ptr = nullptr;
		return *this;
	}
};


template<class T>
class My_shared_ptr
{
	T* ptr;
	int* count;
public:

	My_shared_ptr() :ptr = nullptr, count = nullptr {}
	My_shared_ptr(T* p = nullptr) :ptr(p), coutn(new int(1)) {}
	~My_shared_ptr()
	{
		if (count) 
		{
			if (*count == 1) 
			{
				delete count;
				delete ptr;
			}
			else (*count)--;
		}
	}

	int use_count() const
	{
		if (count != 0)
			return *count;
		else
			return 0;
	}

	bool unique() const
	{
		return (*count == 1);
	}

	T* operator->() const { return ptr; }
	T& operator*() const { return *ptr; }

	My_shared_ptr(My_shared_ptr<T>& p)
	{
		count = p.count;
		ptr = p.ptr;
		*(count)++;
	}


	My_shared_ptr& operator=(const My_shared_ptr& p)
	{
		if (this != &p)
		{
			if (count)
			{
				if (*count == 1)
				{
					delete count;
					delete ptr;
				}
				else (*count)--;
			}
			ptr = p.ptr;
			count = p.count;
			(*count)++;
		}
		return *this;
	}

};
