#pragma once
#include <string>
#include <utility>
#include "Stack.h"
using namespace std;
using namespace myWorks::myDynamicStack;

class Calc
{
	string m_data;
	int getPrioryti(const char c) const;
	int operation(const int a, const int b, const char op) const;
public:
	Calc(string st) :m_data(st) {};
	int getResult() const;
	friend ostream& operator<<(ostream& out, const Calc& c)
	{
		out << c.getResult();
		return out;
	}
};


inline int Calc::getResult() const
{
	//m_data = d;
	DynamicStack <int, 50> num;
	DynamicStack <char, 50> op;
	auto i = 0;
	while (m_data[i])
	{
		if (isdigit(m_data[i]))
		{
			auto ch = 0;
			while (isdigit(m_data[i]))
			{
				ch = ch * 10 + (m_data[i] - 48);
				i++;
			}
			num.push(ch);
		};
		if (m_data[i] == '*' || m_data[i] == '/' || m_data[i] == '^' || m_data[i] == '+' || m_data[i] == '-')
		{
			if (op.isEmpty())
				op.push(m_data[i]);
			else
			{
				if (getPrioryti(m_data[i]) >= getPrioryti(op.peek()))
				{
					op.push(m_data[i]);
				}
				else
				{
					auto b = num.pop();
					auto a = num.pop();
					num.push(operation(a, b, op.pop()));
					op.push(m_data[i]);
				}
			}
			i++;
		};
		if (m_data[i] == '(')
		{
			op.push(m_data[i]);
			i++;
			while (m_data[i] != ')')
			{
				if (isdigit(m_data[i]))
				{
					auto ch = 0;
					while (isdigit(m_data[i]))
					{
						ch = ch * 10 + (m_data[i] - 48);
						i++;
					}
					num.push(ch);
				};
				if (m_data[i] == '*' || m_data[i] == '^' || m_data[i] == '/' || m_data[i] == '+' || m_data[i] == '-')
				{
					if (op.peek() == '(')
						op.push(m_data[i]);
					else
					{
						if (getPrioryti(m_data[i]) >= getPrioryti(op.peek()))
							op.push(m_data[i]);
						else
						{
							auto b = num.pop();
							auto a = num.pop();
							num.push(operation(a, b, op.pop()));
							op.push(m_data[i]);
						}
					}
					i++;
				}
			}
			while (op.peek() != '(')
			{
				auto b = num.pop();
				auto a = num.pop();
				num.push(operation(a, b, op.pop()));
			}
			op.pop();
			i++;
		}
	}

	while (!op.isEmpty())
	{
		auto b = num.pop();
		auto a = num.pop();
		num.push(operation(a, b, op.pop()));
	}

	return num.peek();
}


inline int Calc::getPrioryti(const char c) const
{
	switch (c)
	{
	case '+': case '-':
		return 1;
	case '*': case '/': case'^':
		return 2;
	default:
		break;
	}
}

inline int Calc::operation(const int a, const int b, const char op) const
{

	switch (op)
	{
	case '+': return a + b; break;
	case '-': return a - b; break;
	case '*': return a * b; break;
	case '/': return a / b; break;
	case '^': return pow(a, b); break;
	default:
		break;
	}
}
