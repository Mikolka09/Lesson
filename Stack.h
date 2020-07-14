#pragma once
#include"MyData.h"
#include"MyException.h"

namespace myWorks
{

	namespace myStaticStack
	{


		template<class T, int size>
		class StaticStack
		{
		private:
			MyData<T> data[size];
			int top = 0;//вершины у стека по началу нет
		public:
			void push(T val);//добавление в стек (положить)
			T pop(); //удаление из стека (удалить)
			int getSize();//количество элементов
			T peek();//смотреть кто на вершине (последний)
			bool isEmpty();//проверка на пустоту
			bool isFull();//проверка на полноту
			void clear();//очистка стека
			void print();//печать стека

		};

		template<class T, int size>
		inline void StaticStack<T, size>::push(T val)
		{
			if (top < size)
				data[top++].value = val;
			else
				throw MyStackException::SIZE_FULL;
		}

		template<class T, int size>
		inline T StaticStack<T, size>::pop()
		{
			return data[top--].value;
		}

		template<class T, int size>
		inline int StaticStack<T, size>::getSize()
		{
			return top;
		}

		template<class T, int size>
		inline T StaticStack<T, size>::peek()
		{
			return data[top - 1].value;
		}

		template<class T, int size>
		inline bool StaticStack<T, size>::isEmpty()
		{
			return top == 0;;
		}

		template<class T, int size>
		inline bool StaticStack<T, size>::isFull()
		{
			return top == size;
		}

		template<class T, int size>
		inline void StaticStack<T, size>::clear()
		{
			top = 0;
		}

		template<class T, int size>
		inline void StaticStack<T, size>::print()
		{
			for (size_t i = 0; i < top; i++)
			{
				cout << data[i].value << " ";
			}
			cout << endl;
		}
	}


		////////////////////////////////////////////////

	namespace myDynamicStack
	{

		template<class T, int size>
		class DynamicStack
		{
		private:
			MyData<T>* data = nullptr;
			int top = 0;
		public:
			void push(T val);//добавление в стек (положить)
			T pop(); //удаление из стека (удалить)
			int getSize();//количество элементов
			T peek();//смотреть кто на вершине (последний)
			bool isEmpty();//проверка на пустоту
			bool isFull();//проверка на полноту
			void clear();//очистка стека
			void print();//печать стека
			~DynamicStack();



		};

		template<class T, int size>
		inline void DynamicStack<T, size>::push(T val)
		{
			if (top < size)
			{
				if (top == 0)
				{
					data = new MyData<T>;
					if (!data)
						throw MyStackException::NULLPTR;
					data->value = val;
				}
				else
				{
					MyData<T>* temp = new MyData<T>;
					if (!temp)
						throw MyStackException::NULLPTR;
					temp->value = val;
					temp->next = data;
					data = temp;
				}
				top++;
			}
			else
				throw MyStackException::SIZE_FULL;
		}

		template<class T, int size>
		inline T DynamicStack<T, size>::pop()
		{
			T val = data->value;
			MyData<T>* temp = data;
			if (!temp)
				throw MyStackException::NULLPTR;
			data = data->next;
			delete temp;
			top--;
			return val;
		}

		template<class T, int size>
		inline void DynamicStack<T, size>::print()
		{
			if (top == 0)
			{
				throw MyStackException::SIZE_EMPTY;
			}
			MyData<T>* temp = data;
			if (!temp)
				throw MyStackException::NULLPTR;
			while (temp)
			{
				cout << temp->value << " ";
				temp = temp->next;
			}
			cout << endl;

		}

		template<class T, int size>
		inline DynamicStack<T, size>::~DynamicStack()
		{
			clear();
		}

		template<class T, int size>
		inline T DynamicStack<T, size>::peek()
		{
			if (top > 0)
				return data->value;
			else
				throw MyStackException::NULLPTR;
		}

		template<class T, int size>
		inline bool DynamicStack<T, size>::isEmpty()
		{
			return top == 0;;
		}

		template<class T, int size>
		inline bool DynamicStack<T, size>::isFull()
		{
			return top == size;
		}
		template<class T, int size>
		inline void DynamicStack<T, size>::clear()
		{
			MyData<T>* temp = data;
			if (!temp)
				throw MyStackException::NULLPTR;
			while (data)
			{
				data = temp->next;
				delete temp;
				temp = data;
				top--;
			}
			cout << "Stack cleared!" << endl;
		}
		template<class T, int size>
		inline int DynamicStack<T, size>::getSize()
		{
			return top;
		}

	}
}