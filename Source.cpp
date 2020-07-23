#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<conio.h>
//#include"MyString.h"
//#include"MyClass.h"
//#include"Array1D.h"
#include"Point.h"
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
//#include"Student.h"
//#include"Pointer.h"
//#include<memory>
//#include"Races.h"
#include<vector>
#include<iterator>
#include<algorithm>
#include<list>
#include<map>
#include<set>
#include"Calc.h"

#define LAMBDA [&](int a) { cout << "Hello " << a << " " << ++d <<  endl; }

using namespace std;

using namespace myWorks::myDrob;
using namespace myWorks::myList;


//void doo()
//{
//
//	SmartPointer<Point> p(new Point(2, 3));
//	p->print();
//	int n;
//	cin >> n;
//	if (n == 0)
//		return;
//
//
//}

//void printArr(int *a, int &n)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//
//}
//
//int printArr(int *a, int &&n)
//{
//	for (size_t i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	n++;
//	//cout << n << endl;
//	return n;
//}
//
//template<class T>
//void _swap(T& a, T& b )
//{
//	T temp{ move(a) };
//	a = movi(b);
//	b = move (temp);
//}
//
//template<class T>
//void __swap(T& a, T& b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}


//SmartPointer<Point>doo1()
//{
//	SmartPointer<Point> p(new Point);
//	return p;
//}

//template<class T>
bool MinToMax(int a, int b)
{
	return a < b;
}
//template<class T>
bool MaxToMin(int a, int b)
{
	return a > b;
}

//template<class T>
bool evenFirst(int a, int b)
{
	if (a % 2 == 0 && b % 2 == 1)
		return true;
	if (a % 2 == 1 && b % 2 == 0)
		return false;
	return MinToMax(a, b);
}

bool is0(int v) {
	if (v == 0)
		return true;
	return false;
}

class Summator
{
	int even = 0;
	int odd = 0;
public:
	Summator() {}
	void operator()(int i)
	{
		if (i % 2)
			odd += i;
		else
			even += i;
	}

	int evenSum() { return even; }
	int oddSum() { return odd; }
};

template<class T>
class calc
{
	char op;
public:
	calc(char op) : op(op) {}
	T operator()(T a, T b)
	{
		if (op == '+')
			return a + b;
		if (op == '-')
			return a - b;
		if (op == '/')
			return a / b;
		if (op == '*')
			return a*b;
	}
};

int main()
{
	srand(time(0));
	//SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);
	setlocale(0, "");

	string st;
	cin >> st;
	cout << Calc(st) << endl;

	/*double a, b;
	char op;
	cin >> a >> op >> b;
	cout << a << op << b << "=" << calc<double>(op)(a, b) << endl;*/



	//ФУНКТОРЫ//////////////////////////////////////////////
	/*int a[10];
	generate(a, a + 10, []() { return rand() % 10; });
	for (auto&x : a)
		cout << x << " ";
	cout << endl;*/

	//Summator s;

	//s = for_each(a, a + 10, s);//s - вызывается как функция из-за перегруженных()
	/*Summator s = for_each(a, a + 10, Summator());
	cout << s.evenSum() << endl;
	cout << s.oddSum() << endl;*/


	//ЛЯМБДА выражения///////////////////////////////////////////
	/*int d = 7, b = 9;
	auto foo = LAMBDA;
	foo(15);*/ //"=" - любая переменная но только по значению
	//"&" - захват всех переменных по ссылке

	/*int a[10];
	generate(a, a + 10, []() { return rand() % 10; });
	for (auto&x : a)
		cout << x << " ";
	cout << endl;
	sort(a, a + 10, [](int a, int b) {return a < b; });
	cout << endl;
	for (auto&x : a)
		cout << x << " ";
	cout << endl;
	for_each(a, a + 10, [](int &i) {i *= 10; });
	cout << endl;
	for (auto&x : a)
		cout << x << " ";
	cout << endl;*/

	/*int a[10] = { 1,2,3,4,6,8,4,7 };
	sort(a, a + 10, evenFirst);

	for (auto&x : a)
		cout << x << " ";*/


		/*set<int> s;
		s.insert(4);
		s.insert(2);
		s.insert(3);
		s.insert(5);
		s.insert(6);

		for (auto&x : s)
			cout << x << " ";
		cout << endl;*/


		/*hash<string> t;
		cout << t("asbfvasd") << endl;*/


		//АСИЦИАТИВНЫЙ МАССИВ (КЛЮЧ, ЗНАЧЕНИЕ)/////////////////////
		//map<string, int> m1;
		//pair<string, int> p1("vvvaaa", 4);
		//m1.insert(p1);
		//m1.insert(make_pair("jjjj", 5));

		//for (auto&x : m1)
		//	cout << x.first << " " << x.second << endl;

		//cout << m1["jjjj"] << endl;
		//m1["jjjj"] = 22;

		//cout << m1.count("jjjj") << endl;//возвращает есть ли такой ключ

		//auto it = m1.find("jjjj");
		//if (it != m1.end())
		//	it->second = 66;





		//СПИСКИ//////////////////////////////////////////////////////
		//list<int>l1;
		//l1.push_back(10);
		//l1.push_back(15);
		//l1.push_back(20);
		//l1.push_back(16);
		//l1.push_back(11);
		//l1.push_back(20);
		//l1.push_back(20);
		//list<int> l2;
		//l2.push_back(12);
		//l2.push_back(10);
		//l2.push_back(13);
		//l2.push_back(14);


		//copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
		//cout << endl;

		////l1.insert(find(++l1.begin(), l1.end(), 20), 100);//работает только инкремент и дикремент
		//auto it = l1.begin();
		//advance(it, 2);
		//l1.insert(it, 100);

		//for (auto&l:l1)
		//	cout << l << " ";
		//cout << endl;

		//l1.erase(it);//удаляет по итератору

		//for (auto&l : l1)
		//	cout << l << " ";
		//cout << endl;

		//l1.remove(100);//удаляет по значению

		//for (auto&l : l1)
		//	cout << l << " ";
		//cout << endl;

		//l1.unique();

		//for (auto&l : l1)
		//	cout << l << " ";
		//cout << endl;

		//l1.reverse();

		//for (auto&l : l1)
		//	cout << l << " ";
		//cout << endl;

		//cout << l1.size() << endl;
		//cout << l1.max_size() << endl;
		/////////////////////////////////////////////////////////////////////////

		//ВЕКТОР////////////////////////////////////////////////////////////////////////////////////
		//vector<int> v1(15);
		//for (size_t i = 0; i < v1.size(); i++)
		//{
		//	v1[i] = rand() % 20 + 10;
		//}
		//cout << endl;


		//for (size_t i = 0; i < v1.size(); i++)
		//{
		//	cout << v1[i] << " ";
		//}
		//cout << endl;

		////v1.assign(2, 5);//переопределения размера и новых значений
		////v1.insert(v1.begin() + 2, 1000);//вставить в произвольную позицию


		////v1.erase(v1.begin() + 2);


		//
		//*auto it2=v1.begin();
		//while ((it2 = find_if(v1.begin(), v1.end(), is0)) != v1.end())
		//{
		//	v1.erase(it2);
		//}*/
		//
		//sort(v1.begin(), v1.end());

		//for (auto&x : v1)
		//	cout << x << " ";
		//cout << endl;

		//random_shuffle(v1.begin(), v1.end());//перемешивает данные

		//copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
		//cout << endl;

		//vector<Drob> v1;

		/*v1.push_back(Drob(0, 2, 3));
		v1.push_back(Drob(1, 5, 3));
		v1.push_back(Drob(4, 2, 5));
		v1.push_back(Drob(0, 4, 3));

		for (size_t i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;*/

		//vector<int>::iterator it = v1.begin();
		//for (it; it < v1.end(); ++it)
		//	cout << *it << " ";
		//cout << endl;

		//cout << v1.size() << endl;//количесвто заполненных элемонтов вектора
		//cout << v1.capacity() << endl;//сколько можно еще положить элементов без выделения памяти
		//cout << v1.max_size() << endl;//сколько элементов можно запичасть элементов
		///////////////////////////////////////////////////////////////////////////////////////////////////////


		/*const int n = 10000;
		int a[n];
		for (size_t i = 0; i < n; i++)
		{
			a[i] = rand();
		}

		for (size_t i = 0; i < n-1; i++)
		{
			for (size_t j = 0; j < n-1-i; j++)
			{
				if (a[i] > a[i + 1])
					__swap(a[i], a[i + 1]);
			}
		}*/


		/*unique_ptr<Point> u = make_unique<Point>(2, 5);
		unique_ptr<Point> u2;

		cout << (bool)u << endl;
		cout << (bool)u2 << endl;

		u2 = move(u);

		cout << (bool)u << endl;
		cout << (bool)u2 << endl;

		Point *pp = new Point;
		shared_ptr<Point> p1(pp);
		{
			shared_ptr<Point> p2(p1);
		}*/

		/*int a[5] = { 2, 3, 5, 4, 6 };
		int&& k = printArr(a, 5);
		cout << k << endl;

		int n = 5;
		int & r = n;
		int && r2 = 8;*/


		/*SmartPointer<Point> p1;
		p1 = doo1();*/

		/*SmartPointer<Point> p1(new Point(2, 3));
		SmartPointer<Point> p2(p1);
		p2->print();*/

		//p1->print();

		//SmartPointer<Point> p2=doo1();

		//auto_ptr<Point>p3(new Point);

		//doo1();



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