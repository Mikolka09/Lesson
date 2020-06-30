#pragma once

#include<iostream>
#include<Windows.h>
#include"Stack.h"
#include"Queue.h"

using namespace std;

int getPriorety(char c)
{
	switch (c)
	{
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	case '(': case ')':
		return 3;
	default:
		break;
	}
}

int operation(int a, int b, char op)
{
	switch (op)
	{
	case '+': return a + b; break;
	case '-': return b - a; break;
	case '*': return a * b; break;
	case '/': return b / a; break;
	default:
		break;
	}
}


int main()
{
	//Калькулятор
	char data[80];
	cin.getline(data, 80);

	DynamicStack<int, 50> num;
	DynamicStack<char, 50> op;

	int i = 0;
	while (data[i])
	{
		if (isdigit(data[i]))
			num.push(data[i] - 48);
		else
		{
			if (data[i] == '(')
				op.push(data[i]);
			if (data[i] == ')')
			{
				while (data[i] != '(')
				{
					int a = num.pop();
					int b = num.pop();
					num.push(operation(a, b, op.pop()));
				}
				op.pop();
			}
			else if (data[i] == '*' || data[i] == '/' || data[i] == '+' || data[i] == '-')
			{
				if (op.isEmpty() || op.peek() == '(')
					op.push(data[i]);
				else
				{
					if (getPriorety(data[i]) >= getPriorety(op.peek()))
					{
						op.push(data[i]);
					}
					else
					{
						int a = num.pop();
						int b = num.pop();
						num.push(operation(a, b, op.pop()));
						op.push(data[i]);
					}
				}
			}
		}
		i++;
	}
	while (!op.isEmpty())
	{
		int a = num.pop();
		int b = num.pop();
		num.push(operation(a, b, op.pop()));
	}

	cout << num.peek() << endl;
}