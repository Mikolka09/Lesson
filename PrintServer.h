#pragma once

#include"MyData.h"
#include"Queue.h"
#include"List.h"
#include<string>
#include<iomanip>
#include"Time.h"

using namespace std;

class TaskPrint
{
	string department;
	string docName;
	int timePrint = -1;
public:
	TaskPrint() {}
	TaskPrint(string dep, string doc, int t) :department(dep), docName(doc), timePrint(t) {};
	Priorety getPriorety();
	friend ostream& operator << (ostream& out, const TaskPrint tp);
	int getTimePrint();
	void setTimePrint(int t);
};

Priorety TaskPrint::getPriorety()
{
	if (department == "Admin")
		return HIGH;
	else if (department == "Economic")
		return MEDIUM;
	else
		return LOW;
}

inline int TaskPrint::getTimePrint()
{
	return timePrint;
}

inline void TaskPrint::setTimePrint(int t)
{
	timePrint = t;
}

ostream& operator << (ostream& out, const TaskPrint tp)
{
	out << setw(10) << tp.department << setw(10) << tp.docName << setw(4) << tp.timePrint;
	return out;
}

class PrintServer
{
	string IP;
	PrioretyQueue<TaskPrint, 100> qPrint;
	TaskPrint docPrint, forLogs;
	List<TaskPrint, 100> logs;
public:
	PrintServer(string ip) :IP(ip) {}
	void addTaskPrint(TaskPrint tp);
	void work();
	int getAllTime();
};

void PrintServer::addTaskPrint(TaskPrint pt)
{
	qPrint.push(pt, pt.getPriorety());
}

inline void PrintServer::work()
{
	if (docPrint.getTimePrint() == 0)
	{
		logs.push_back(forLogs);
	}

	if (docPrint.getTimePrint() != -1)
	{
		docPrint.setTimePrint(docPrint.getTimePrint() - 1);
	}

	system("cls");
	cout << "PrintServer: " << IP << "                Logs" << endl;
	cout << "----------------------------------------------------------------" << endl;

	cout << "Printing:" << endl;
	cout << "--------------------------" << endl;
	if (docPrint.getTimePrint() != -1)
		cout << docPrint << endl;
	else
		cout << endl;
	cout << endl << endl;

	cout << "Waiting:" << endl;
	cout << "--------------------------" << endl;
	qPrint.print();

	if (!qPrint.isEmpty() && docPrint.getTimePrint() == -1)
	{
		docPrint = forLogs = qPrint.pop();
	}

	logs.print(40, 2);
	gotoxy(0, 15);
	cout << "----------------------------------------------------------------" << endl;
	cout << "Íàïå÷àòàíî " << logs.getSize() << " äîêóìåíòîâ,  Îáùåå âðåìÿ ðàáîòû " << Time(getAllTime());
}

inline int PrintServer::getAllTime()
{
	int t = 0;
	for (size_t i = 0; i < logs.getSize(); i++)
	{
		t += logs[i].getTimePrint();
	}
	return t;
}


//string dep[4] = { "Admin", "Economic", "Transport", "HR" };
//string file[4] = { "file1.doc", "file2.pdf", "file3.txt", "file4.xls" };
//
//PrintServer ps("10.6.0.185");
//
//int t = 0;
//while (true)
//{
//	int m = rand() % 10 + 10;
//	if (t % m == 0)
//	{
//		ps.addTaskPrint(TaskPrint(dep[rand() % 4], file[rand() % 4], rand() % 9 + 1));
//	}
//	ps.work();
//	t++;
//	Sleep(1000);
//}
