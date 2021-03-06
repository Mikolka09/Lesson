﻿#pragma once
#include"MyData.h"

namespace myWorks
{
	namespace myQueue
	{

		template<class T, int size>
		class Queue //простая очередь
		{
		private:
			MyData<T>* first = nullptr;
			MyData<T>* last = nullptr;
			int length = 0;
		public:
			~Queue();
			void push(T val);
			T pop();
			int getSize();
			bool ifEmpty();
			bool isFull();
			T peek();
			void print();
			void clear();





		};

		template<class T, int size>
		inline Queue<T, size>::~Queue()
		{
			clear();
		}

		template<class T, int size>
		inline void Queue<T, size>::push(T val)
		{
			if (length < size)
			{
				if (length == 0)
				{
					first = new MyData<T>;
					if (!first)
						throw MyQueueException::NULLPTR;
					first->value = val;
					last = first;
				}
				else
				{
					MyData<T>* temp = new MyData<T>;
					if (!temp)
						throw MyQueueException::NULLPTR;
					temp->value = val;
					last->next = temp;
					last = temp;
				}
				length++;
			}
			else
				throw MyQueueException::SIZE_FULL;
		}

		template<class T, int size>
		inline T Queue<T, size>::pop()
		{
			T val = first->value;
			MyData<T>* temp = first;
			if (!temp)
				throw MyQueueException::NULLPTR;
			first = first->next;
			delete temp;
			length--;
			return val;
		}

		template<class T, int size>
		inline int Queue<T, size>::getSize()
		{
			return length;
		}

		template<class T, int size>
		inline bool Queue<T, size>::ifEmpty()
		{
			return length == 0;
		}

		template<class T, int size>
		inline bool Queue<T, size>::isFull()
		{
			return length == size;
		}

		template<class T, int size>
		inline T Queue<T, size>::peek()
		{
			return first->value;
		}

		template<class T, int size>
		inline void Queue<T, size>::print()
		{
			if (length == 0)
			{
				throw MyQueueException::SIZE_EMPTY;
			}
			MyData<T>* temp = first;
			if (!temp)
				throw MyQueueException::NULLPTR;
			while (temp)
			{
				cout << temp->value << " ";
				temp = temp->next;
			}
			cout << endl;
		}

		template<class T, int size>
		inline void Queue<T, size>::clear()
		{
			while (length)
			{
				pop();
			}
			first = last = nullptr;
			cout << "Queue cleared!" << endl;
		}

	}


	///////////////////////////////////////////////////////////

	namespace myRingQueue
	{

		template<class T, int size>
		class RingQueue//циклическая очередь
		{
		private:
			MyData<T>* first = nullptr;
			MyData<T>* last = nullptr;
			int length = 0;

		public:
			~RingQueue();
			void push(T val);
			void pop();
			int getSize();
			bool isEmpty();
			bool isFull();
			T peek();
			void print();
			void clear();

		};

		template<class T, int size>
		inline RingQueue<T, size>::~RingQueue()
		{
		}

		template<class T, int size>
		inline void RingQueue<T, size>::push(T val)
		{
			if (length < size)
			{
				if (length == 0)
				{
					first = new MyData<T>;
					if (!first)
						throw MyQueueException::NULLPTR;
					first->value = val;
					last = first;
				}
				else
				{
					MyData<T>* temp = new MyData<T>;
					if (!temp)
						throw MyQueueException::NULLPTR;
					temp->value = val;
					last->next = temp;
					last = temp;
				}
				length++;
			}
			else
				throw MyQueueException::SIZE_FULL;
		}

		template<class T, int size>
		inline void RingQueue<T, size>::pop()
		{
			MyData<T>* temp = first;
			if (!temp)
				throw MyQueueException::NULLPTR;
			first = first->next;
			last->next = temp;
			last = temp;
			last->next = nullptr;
		}

		template<class T, int size>
		inline T RingQueue<T, size>::peek()
		{
			return first->value;
		}

		template<class T, int size>
		inline void RingQueue<T, size>::print()
		{
			if (length == 0)
			{
				throw MyQueueException::SIZE_EMPTY;
			}
			MyData<T>* temp = first;
			if (!temp)
				throw MyQueueException::NULLPTR;
			while (temp)
			{
				cout << temp->value << " ";
				temp = temp->next;
			}
			cout << endl;
		}

		template<class T, int size>
		inline void RingQueue<T, size>::clear()
		{
			while (length)
			{
				pop();
				length--;
			}
			first = last = nullptr;
		}


		template<class T, int size>
		inline bool RingQueue<T, size>::isEmpty()
		{
			return length == 0;
		}

		template<class T, int size>
		inline bool RingQueue<T, size>::isFull()
		{
			return length == size;
		}

		template<class T, int size>
		inline int RingQueue<T, size>::getSize()
		{
			return length;
		}

	}

	//////////////////////////////////////////////////////////

	namespace myPrioretyQueue
	{

		template<class T, int size>
		class PrioretyQueue
		{
		private:
			MyData<T>* first = nullptr;
			MyData<T>* last = nullptr;
			int length = 0;
		public:
			~PrioretyQueue();
			void push(T val, Priorety pre);
			T pop();
			int getSize();
			bool isEmpty();
			bool isFull();
			T peek();
			void print();
			void clear();
		};

		template<class T, int size>
		inline PrioretyQueue<T, size>::~PrioretyQueue()
		{
			clear();
		}

		template<class T, int size>
		inline void PrioretyQueue<T, size>::push(T val, Priorety pre)
		{
			if (length < size)
			{
				if (length == 0)
				{
					first = new MyData<T>;
					if (!first)
						throw MyQueueException::NULLPTR;
					first->value = val;
					first->pre = pre;
					last = first;
				}
				else
				{
					MyData<T>* temp = new MyData<T>;
					if (!temp)
						throw MyQueueException::NULLPTR;
					temp->value = val;
					temp->pre = pre;
					MyData<T>* num = first;
					if (!num)
						throw MyQueueException::NULLPTR;
					if (last->pre >= pre)
					{
						last->next = temp;
						last = temp;
					}
					else
					{
						if (pre > first->pre)
						{
							temp->next = first;
							first = temp;
						}
						else
						{
							while (num->pre >= pre && num->next->pre >= pre)
							{
								num = num->next;
							}
							temp->next = num->next;
							num->next = temp;
						}
					}
				}
				length++;
			}
			else
				throw MyQueueException::SIZE_FULL;
		}

		template<class T, int size>
		inline T PrioretyQueue<T, size>::pop()
		{
			if (length > 0)
			{
				MyData<T>* temp = first;
				if (!temp)
					throw MyQueueException::NULLPTR;
				first = first->next;
				T val = temp->value;
				delete temp;
				length--;
				return val;
			}
		}

		template<class T, int size>
		inline int PrioretyQueue<T, size>::getSize()
		{
			return length;
		}

		template<class T, int size>
		inline bool PrioretyQueue<T, size>::isEmpty()
		{
			return length == 0;
		}

		template<class T, int size>
		inline bool PrioretyQueue<T, size>::isFull()
		{
			return length == size;
		}

		template<class T, int size>
		inline T PrioretyQueue<T, size>::peek()
		{
			return first->value;
		}

		template<class T, int size>
		inline void PrioretyQueue<T, size>::print()
		{
			if (length == 0)
			{
				throw MyQueueException::SIZE_EMPTY;
			}
			MyData<T>* temp = first;
			if (!temp)
				throw MyQueueException::NULLPTR;
			while (temp)
			{
				cout << temp->value << "(" << temp->pre << ")" << " ";
				temp = temp->next;
			}
			cout << endl;

		}

		template<class T, int size>
		inline void PrioretyQueue<T, size>::clear()
		{
			while (length)
			{
				pop();
				length--;
			}
			first = last = nullptr;
		}

	}

}
