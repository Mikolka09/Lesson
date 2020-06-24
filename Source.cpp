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
//#include"Array2D.h"
#include"StaticArray.h"
#include"Stack.h"
#include"Queue.h"
#include"List.h"
#include"BTree.h"


using namespace std;




int main()
{
	//setlocale(0, "");


	BTree<int, int> tr;
	tr.push(35, 35);
	tr.push(15, 15);
	tr.push(25, 25);
	tr.push(65, 65);
	tr.push(5, 10);
	tr.push(0, 0);
	tr.print();



	/*ForwardList<int, 5> l;
	l.push_front(5);
	l.push_front(15);
	l.push_front(25);
	l.push_back(35);
	l.print();
	l.pop_at(2);
	l.print();
	l.print_reverse();*/


	/*List<int, 10> list;
	list.push_front(5);
	list.push_front(15);
	list.push_front(25);
	list.print();
	list.push_back(40);
	list.push_back(50);
	list.print();
	list.push_at(100, 3);
	list.print();
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();*/
	//list.pop_at(2);
	//list.print();
	//cout << list[25] << endl;
	//list.print();

	/*PrioretyQueue<int, 10> q;
	q.push(5, HIGH);
	q.push(10, LOW);
	q.push(15, MEDIUM);
	q.push(15, LOW);
	q.push(17, HIGH);
	q.push(16, MEDIUM);
	q.push(60, MEDIUM);
	q.print();*/
	

	/*while (!_kbhit())
	{
		system("cls");
		q.pop();
		q.print();
		Sleep(300);
	}*/
	/*q.print();
	q.pop();
	q.print();
	q.pop();
	q.print();*/


	/*DynamicStack<int, 15> st;
	for (size_t i = 0; i < 10; i++)
	{
		int a;
		cin >> a;
		st.push(a);
	}
	st.print();
*/




/*StaticArray<double, 5> a;
a[0] = 2.3;
a[1] = 9.5;
a.print();*/
//int f;


/*Array2D<Time> a(2, 2);
a[0][0] = Time(1, 2, 5);
a[0][1] = Time(1, 2, 5);
a[1][0] = Time(1, 2, 5);
a[1][1] = Time(1, 2, 5);
a.print();*/

//cout << a << endl;
//cout << a[1][1] << endl;
//a[1][1] = 10;
//cout << a << endl;
/*cin >> a;
cout << a << endl;
cin >> f;
cout << f << endl;*/

/*Array1D<int> arr1(3);
arr1.add(5);
arr1.add(3);
arr1.add(9);
arr1.print();
cout << arr1[2] << endl;
cout << "всего - " << arr1.getSize() << endl;
cout << "заполнено - " << arr1.getsizeFull() << endl;*/

/*Array1D<double> arr2(4);
arr2.add(2.56);
arr2.add(6.58);
arr2.add(3.38);
arr2.print();
cout << "всего - " << arr2.getSize() << endl;
cout << "заполнено - " << arr2.getsizeFull() << endl;*/

/*Array1D a(3);
cin >> a;
cout << a << endl;

cout << a.getSize() << endl;
cout << a.getsizeFull() << endl;*/

/*Point3D p(1, 1, 1);
Vector3D v(2, 4, -1);

cout << p << endl;

p.moveByVector(v);
cout << p << endl;
*/

/*MyString s = "Hello";
cout << s << endl;*/

//Temperature t(36);
//Humidity h(30);

/*cout << "Weather now: " << endl;
cout << "----------------" << endl;
t.print();
h.print();*/

//weatherNow(t, h);



//Progress p1(2, -3);
//Progress p2(3, 3);
//Progress p = p1 - p2;
//cout << p.summa(3) << endl;
//p.print(3);
//cout << p[1] << endl;

//Time t(10);
/*Time t1 = 3 * t;
cout << t1 << endl;*/
/*Time t1;
cin >> t1;
Time t2;
t2 = t1 + t;
cout << t2 << endl;*/

/*Array1D a(3);
a.add(3);
a.add(5);
a.add(8);
cout << a << endl;*/

/*Time t(10);
Time t1 = ++t - ++t;
t1.printTo24();
t.printTo24();*/

/*Rectangle r({ 2,3 }, { 3,3 });
r({ 3,5 }, { 6,7 });
r(2, 4, 6, 8);*/


/*MyString t = "hhhhhhh";
t = "fffffff";
cout << t.getString() << endl;*/



/*Point p(2, 7);
p.print();
print2(p);*/
//p(3, 5);
//p.Print();




	system("pause");
}