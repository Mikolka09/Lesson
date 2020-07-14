#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"MyString.h"
#include"MyClass.h"
#include"Array1D.h"
#include"Point.h"
#include"Apple.h"
#include"Time.h"
#include"Progress.h"
#include"Weather.h"
#include"_3D.h"
#include"Array2D.h"
#include"StaticArray.h"
#include"Stack.h"
#include"Queue.h"
#include"List.h"
#include"BTree.h"
#include"PrintServer.h"
#include"BasePDR.h"
#include"Car.h"
#include"Inheritance.h"
#include"A.h"
#include"Animal.h"
#include<fstream>
#include"Ploshad.h"
#include"MyException.h"
#include"Foo.h"
#include"Boo.h"
#include"Drob.h"

using namespace std;




using namespace myWorks;

int main()
{

	//SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);
	setlocale(0, "");

	myArray1D::Array1D<int> arr(10);
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
	myDynamicStack::DynamicStack<int, 20> dt;





	system("pause");
}