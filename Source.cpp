#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<conio.h>
//#include"MyString.h"
//#include"MyClass.h"
//#include"Array1D.h"
//#include"Point.h"
//#include"Apple.h"
//#include"Time.h"
//#include"Progress.h"
//#include"Weather.h"
//#include"_3D.h"
//#include"Array2D.h"
//#include"StaticArray.h"
//#include"Stack.h"
//#include"Queue.h"
#include"List.h"
#include"BTree.h"
//#include"PrintServer.h"
#include"BasePDR.h"
//#include"Car.h"
//#include"Inheritance.h"
//#include"A.h"
//#include"Animal.h"
#include<fstream>
//#include"Ploshad.h"
//#include"MyException.h"
//#include"Foo.h"
//#include"Boo.h"
#include"Drob.h"
#include"Student.h"

using namespace std;

using namespace myWorks::myDrob;
using namespace myWorks::myList;

int main()
{
	srand(time(0));
	//SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);
	setlocale(0, "");


	/*BasePDR b;
	b.menu();*/

	/*List<int, 100> l;
	char b[80];
	ifstream in("test.txt");
	cout << in.rdbuf() << '\n';*/


	/*Cat c("Tom", 5);
	cout << sizeof(Cat) << endl;*/

	//Drob a[3] = { Drob(1,2,3), Drob(2,5,3),  Drob(4,2,5) };
	//fstream out;
	//out.open("test.bin", ios::binary | ios::out);
	//for (size_t i = 0; i < 5; i++)
	//{
	//	out.write((char*)&a[i], sizeof(Drob));
	//	//out << a[i] << " ";
	//}
	//out.close();

	/*ifstream in("test.bin", ios::binary);
	int i;
	cin >> i;
	in.seekg(0, ios::end);
	int n = in.tellg();
	if (i < n / sizeof(Drob))
	{
		in.seekg(i*sizeof(Drob));
		Drob b;
		in.read((char*)&b, sizeof(Drob));
		b.print();
	}
	else
		cout << "error" << endl;*/


	/*Student st(16, "Ivanov");
	st.print();

	ofstream out("stud.bin", ios::binary);
	out.write((char*)&st, sizeof(Student));
	int l = strlen(st.getName());
	out.write((char*)&l, sizeof(int));
	out.write((char*)st.getName(), l);
	out.close();*/

	/*Student st1;
	ifstream in("stud.bin", ios::binary);
	in.read((char*)&st1, sizeof(Student));
	int l;
	in.read((char*)&l, sizeof(int));
	char* n = new char[l + 1];
	in.read((char*)n, l);
	n[l] = '\0';
	st1.setName(n);
	st1.print();*/


	/*myArray1D::Array1D<int> arr(10);
	myArray2D::Array2D<int> arr2(10,10);
	myBtreeNode::BTreeNode<string, myList::List<int, 100>>;
	myDrob::Drob d(1, 2, 3);
	myList::List<int, 100> l;
	myString::MyString st;
	myBitString::BitMyString str;
	myQueue::Queue<int, 10> q;
	myRingQueue::RingQueue<int, 10> r;
	myPrioretyQueue::PrioretyQueue<int, 20> p;
	myStaticStack::StaticStack<int,10> stk;
	myDynamicStack::DynamicStack<int, 20> dt;*/





	system("pause");
}