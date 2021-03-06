﻿#pragma once

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
	DynamicStack <int, 50> num;
	DynamicStack <char, 50> op;
	int i = 0;
	while (data[i])
	{
		if (isdigit(data[i]))
		{
			int ch = 0;
			while (isdigit(data[i]))
			{
				ch = ch * 10 + (data[i] - 48);
				i++;
			}
			num.push(ch);
		};
		if (data[i] == '*' || data[i] == '/' || data[i] == '+' || data[i] == '-')
		{
			if (op.isEmpty())
				op.push(data[i]);
			else
			{
				if (getPriorety(data[i]) >= getPriorety(op.peek()))
				{
					op.push(data[i]);
				}
				else
				{
					int b = num.pop();
					int a = num.pop();
					num.push(operation(a, b, op.pop()));
					op.push(data[i]);
				}
			}
			i++;
		};
		if (data[i] == '(')
		{
			op.push(data[i]);
			i++;
			while (data[i] != ')')
			{
				if (isdigit(data[i]))
				{
					int ch = 0;
					while (isdigit(data[i]))
					{
						ch = ch * 10 + (data[i] - 48);
						i++;
					}
					num.push(ch);
				};
				if (data[i] == '*' || data[i] == '/' || data[i] == '+' || data[i] == '-')
				{
					if (op.peek() == '(')
						op.push(data[i]);
					else
					{
						if (getPriorety(data[i]) >= getPriorety(op.peek()))
							op.push(data[i]);
						else
						{
							int b = num.pop();
							int a = num.pop();
							num.push(operation(a, b, op.pop()));
							op.push(data[i]);
						}
					}
					i++;
				}
			}
			while (op.peek() != '(')
			{
				int b = num.pop();
				int a = num.pop();
				num.push(operation(a, b, op.pop()));
			}
			op.pop();
			i++;
		}
	}
	while (!op.isEmpty())
	{
		int b = num.pop();
		int a = num.pop();
		num.push(operation(a, b, op.pop()));
	}
	cout << num.peek() << endl;
}


//Проверка на выход за пределы
int a;
do {
	try {
		cin >> a;
		if (a == INT_MAX || a == INT_MIN)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			throw "MAX";
		}
		cout << a << endl;
	}
	catch (const char* n)
	{
		cout << n << endl;
	}
} while (a == INT_MAX || a == INT_MIN);


//Принимает ввод только цифр до нажатия интера
char buff[100] = "", b[10];
int i = 0;
unsigned char c;

do
{
cout << '\r' << buff;
c = _getch();
if (isdigit(c))
{
buff[i++] = c;
buff[i] = '\0';
}

} while (c != '\r');
cout << buff << endl;