#pragma once
using namespace std;

class Point
{
	int m_x;
	int m_y;

public:
	Point() :Point(0, 0) {}
	explicit Point(int x) :m_x(x), m_y(0) {}
	Point(int x, int y) :m_x(x), m_y(y) { /*cout << "Constructor" << endl;*/ }

	~Point() // деструктор
	{
		//print();
		//cout << "Destructor" << endl;
	}

	void setCoord(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	void operator()(int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	void print()
	{
		cout << "X = " << m_x << ", Y = " << m_y << endl;
	}
	/*int GetX()
	{
		return m_x;
	}
	int GetY()
	{
		return m_y;
	}*/

	friend void print2(Point p);
};


void print2(Point p)
{
	cout << "(" << p.m_x << ", " << p.m_y << ")" << endl;
}

// инициализация динамических переменных
//Point p1[2] = { Point(), Point(2,5) };

/*Point *p2 = new Point();
p2->print();*/

/*Point *p3 = new Point[2]{ Point(2,5), Point() };
p3[0].print();
p3[1].print();*/

/*Point *p4 = new Point[2];
p4[0] = Point();
p4[1] = Point(3, 8);
p4[0].print();
p4[1].print();
delete[]p4;*/


#pragma once
#include"Point.h"
class Rectangle
{
	Point m_p1, m_p2;


public:
	Rectangle(Point p1, Point p2 = { 0,0 });
	~Rectangle();
	void setCoord(Point p1, Point p2);
	int Perimetr();
	void operator()(Point p1, Point p2);
	void operator()(int x1, int y1, int x2, int y2);
};

Rectangle::Rectangle(Point p1, Point p2)
{
	m_p1 = p1;
	m_p2 = p2;
}

Rectangle::~Rectangle()
{
}

void Rectangle::setCoord(Point p1, Point p2)
{
	m_p1 = p1;
	m_p2 = p2;
}

//int Rectangle::Perimetr()
//{
//	return ((abs(m_p1.GetX() - m_p2.GetX()) + abs(m_p1.GetY() - m_p2.GetY())) * 2);
//}

inline void Rectangle::operator()(Point p1, Point p2)
{
	m_p1 = p1;
	m_p2 = p2;
}

inline void Rectangle::operator()(int x1, int y1, int x2, int y2)
{
	m_p1 = Point(x1, y1);
	m_p2 = Point(x2, y2);
}


//Rectangle r1({ 2,3 }, { 3,5 });
////r1.setCoord({ 7,8 }, { 2,10 });
//Rectangle r2({ 2,2 });
//cout << r2.Perimetr() << endl;



int a[5] = { 1,2,3,4,5 };
ofstream out;
out.open("test.txt");
for (size_t i = 0; i < 5; i++)
{
	out << a[i] << " ";
}
out.close();

/*int b[5];
ifstream in;
in.open("test.txt");
if (in.is_open())
{
	for (size_t i = 0; i < 5; i++)
	{
		in >> b[i];
	}
}
in.close();*/

/*List<int, 100> l;;
int b;
ifstream in;
in.open("test.txt");
if (in.is_open())
{
	while (in >> b)
	{
		l.push_back(b);
	}
	in.close();
}
l.print();*/

//List<int, 100> l;;
//char b[80];
//ifstream in;
//in.open("test.txt");
//if (in.is_open())
//{
//	while (in.getline(b, 80))
//	{
//		cout << b << endl;
//	}
//	in.close();
//}
////l.print();

//fstream o2;



//Поток вывода
//cout.setf(ios::boolalpha);//включение флага
//cout << true << endl;

////cout.unsetf(ios::dec);//отключение флага (отключение десятичной системы)
////cout.setf(ios::showpos | ios::oct | ios::showbase);//перечесление флагов через побитовый |
//cout << 30 << endl;
//cout << -30 << endl;

//cout.setf(ios::left);//равнение по левой стороне
//cout.fill('*');//заполняет все пустые клетки символом
//cout << setw(10) << 75984 << "85498" << endl;

//cout << scientific;//экспонициальная форма записи
//cout << fixed;//будет использована десятичная запись числа
//cout << setprecision(3) << 123.231 << endl;

//Поток вывода
//char buff[10];
//cin.getline(buff, 5);//Потоковый ввод с учетом пробелов органичено числом символов
//cin >> setw(5) >> buff;//Потоковый ввод с ограничением до пробела или количества введеных
//cout << buff << endl;
//cout << cin.gcount() << endl;//подсчитывает количество символов

//char buff[10];
/*cin >> setw(3) >> buff;
cout << buff << endl;
cin.ignore();
cin >> setw(3) >> buff;
cout << buff << endl;
cin.ignore();
cin >> buff;
cout << buff << endl;*/







/*string f;
getline(cin, f);
cout << f << endl;*/







/*BitMyString bst = "125-5-4";
bst.print();*/


/*char ss = '5';
bool t = true;
while (t)
{
	char res = ('0' + (ss % 2));
	ss = ('0' + ss) / 2;
	int p = (int(ss)-(int)'0') / 2;

	if (p == 0)
		t = false;
}*/

/*Cat c("Dodo", 2);
Animal& a = c;

cout << a.getName() << endl;
a.voice();

Animal aa = c;
cout << aa.getName() << endl;
aa.voice();*/

/*Animal* aaa = generator(2);
cout << aaa->getName() << endl;
aaa->voice();

Cat* c = dynamic_cast<Cat*>(aaa);
if (c)
	c->getArea();*/


	//my_stack::StaticStack<int, 10> st;

	/*cout << Foo::operation(3, 6) << endl;
	cout << Boo::operation(3, 6) << endl;
	Koo::Doo::oper1(2, 3);

	namespace voo = Koo::Doo;
	voo::oper1(3, 5);
	::oper(3, 5);

	{
		using namespace Foo;
		cout << Foo::operation(3, 6) << endl;
	}

	{
		using namespace Boo;
		cout << Boo::operation(3, 6) << endl;
	}*/


	/*FileErrorLog fn ("data.txt");
	cout << discrm(5,1,1, fn) << endl;*/


	/*try
	{
		try
		{
			throw Cat("Bim", 2);
		}

		catch (Animal &a)
		{
			cout << "Exception for Cat" << endl;
			cout << a.getName() << endl;
			a.voice();
			throw;
		}

	}

	catch (Animal &a)
	{
		cout << endl<< "Exception for Cat 2" << endl;
		cout << a.getName() << endl;
		a.voice();

	}*/


	/*int a;
	a = MyException::get_value();*/






	//List<int, 5> ls;
	//try
	//{
	//	/*ls.push_front(5);
	//	ls.push_front(15);
	//	ls.push_front(25);
	//	ls.push_front(35);
	//	ls.push_front(45);
	//	ls.push_front(55);*/
	//	ls.print();
	//}

	//catch (const char *n)
	//{
	//	cout << n << endl;
	//}
	//catch (MyException &e)
	//{
	//	cerr << e.get_error() << endl;
	//}



	//BitMyString bst = "156789";

	//int a, b, c;
	//cin >> a >> b;
	//try//ловит исключение
	//{
	//	cout << division(a, b) << endl;
	//	/*if (b == 0)
	//		throw "Делить на ноль нельзя!";
	//	cout << a / b << endl;*/
	//	//throw 1; //говорить о том что будет выброшено исключение, после этой команды код не пойдет
	//}
	//catch (int a)//обрабатывает исключение
	//{
	//	cout << "Обработано исключение целого типа со значение "<< a << endl;
	//}
	//
	//catch (double a)//обрабатывает исключение
	//{
	//	cout << "Обработано исключение вещественного типа со значение " << a << endl;
	//}

	//catch (const char *n)
	//{
	//	cout << n << endl;
	//}

	//catch (...)//обрабатывает все, что не обработалось
	//{
	//	cout << "Что-то не так!" << endl;
	//}

	//cout << "Stop" << endl;

	/*FileErrorLog fl("data.txt");
	ConsoleErrorLog cl;
	cout << mySQRT(25, cl) << endl;*/
	//cout << cl.getError() << endl;



	//MyString st("aaa");
	//cout << st << endl;
	//cout << st.getLen() << endl;
	////st.clear();
	////cout << "--------------------" << endl;
	////cout << st << endl;
	//MyString st1("ddd");
	////st1 = st;
	//cout << "--------------------" << endl;
	//cout << st1 << endl;
	////MyString st2;
	//st += st1;
	//cout << "--------------------" << endl;
	//cout << st << endl;

	//bool s = st != st1;
	//cout << s << endl;


	/*Dog D("Hulk", 10);
	cout << D.getName() << endl;


	Animal &rD = D;
	cout << rD.getName() << endl;

	Animal *pD = &D;
	cout << pD->getName() << endl;

	Cat C("Tom", 3);
	Animal *pC = &C;
	cout << pC->getName() << endl;

	Medusa M("Jerry", 1);

	Animal *animal[] = { &C, &D, &M };
	for (size_t i = 0; i < 3; i++)
	{
		cout << animal[i]->getName() << " ";
		animal[i]->voice();
	}
	cout << endl;*/

	/*A a;
	a.a1 = 5;
	a.a2 = 5;
	a.a3 = 5;
	a.pr();


	B b;
	b.a1 = 5;
	b.a2 = 5;
	b.a3 = 5;
	b.pr();*/



	/*Human h;
	cout << endl;

	FootballPlayer fp;
	fp.print();
	cout << endl;
	TypeFP tfp("Ronaldo", 35, 100, 1000, "Forward");
	tfp.print();*/

	//fp.name = "Ronaldo";
	//fp.print();


	/*Engin *en = new Engin(8);

	Car c("Opel", en);
	c.print();*/





	/*BasePDR b;
	b.menu();*/



	/*BTree<int, int> tr;
	tr.push_r(35, 35);
	tr.push_r(15, 15);
	tr.push_r(25, 25);
	tr.push_r(65, 65);
	tr.push_r(5, 5);
	tr.push_r(0, 0);
	tr.print();*/
	//tr.del();



	//ForwardList<int, 5> l;
	//l.push_front(5);
	//l.push_front(30);
	//l.push_front(25);
	//l.push_back(20);
	//l.print();
	////l.sort();
	//l.sort_revers();
	//l.print();
	//ForwardList<int, 5> l1;
	//l1.push_front(10);
	//l1.push_front(15);
	//l1.push_front(20);
	//l1.push_back(35);
	//l1.print();
	//ForwardList<int, 5> l2;
	//l2 = l * l1;
	//l2.print();
	////cout<< l.peek_at(1);
	/*cout << endl;
	l.print();
	l.print_reverse();*/


	/*List<int, 10> list;
	list.push_front(35);
	list.push_front(20);
	list.push_front(30);
	list.push_front(15);
	list.print();*/
	/*list.sort_revers();
	list.sort();
	cout << list;
	list.print();*/
	/*List<int, 10> list1;
	list1.push_front(30);
	list1.push_front(5);
	list1.push_front(50);
	list1.push_front(20);
	list1.print();
	List<int, 10> list3;
	list3 = list + list1;
	list3.print();*/
	//list.push_front(25);
	/*list.print();
	list.push_back(40);
	list.push_back(50);*/
	//cout << endl;
	//int at = list.peek_at(2);
	//cout << at << endl;
	//list.print();
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
	st.print();*/





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