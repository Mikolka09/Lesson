#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"MyString.h"
#include"MyClass.h"
#include"Array1D.h"
#include"Point.h"
#include"Apple.h"
#include"Time.h"
#include"Progress.h"
#include"Weather.h"
#include"_3D.h"

using namespace std;




int main()
{
	setlocale(0, "");

	/*Point3D p(1, 1, 1);
	Vector3D v(2, 4, -1);

	cout << p << endl;

	p.moveByVector(v);
	cout << p << endl;*/


	/*MyString s = "Hello";
	cout << s << endl;*/

	Temperature t(36);
	Humidity h(30);

	/*cout << "Weather now: " << endl;
	cout << "----------------" << endl;
	t.print();
	h.print();*/

	weatherNow(t, h);

	

	//Progress p1(2, -3);
	//Progress p2(3, 3);
	//Progress p = p1 - p2;
	//cout << p.summa(3) << endl;
	//p.print(3);
	//cout << p[1] << endl;

	/*Time t(10);
	Time t1 = 3 * t;
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