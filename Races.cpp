#include "Races.h"

Race::Race(const Race& r)
{
	this->type = r.type;
	this->life = r.life;
	this->damage = r.damage;
	this->speed = r.speed;
	this->gold = r.gold;
}

Race Race::operator=(const Race& r)
{
	this->type = r.type;
	this->life = r.life;
	this->damage = r.damage;
	this->speed = r.speed;
	this->gold = r.gold;
	return *this;
}

void Race::attack(Race& r)  //Нанесение урона противнику
{
	r.life = (r.life - this->damage);
}

ostream& operator<<(ostream& out, const Race& r)
{
	out << setw(5) << r.type << setw(8) << "Life: " << r.life << setw(10) << "Damage: "
		<< r.damage << setw(8) << "Speed: " << r.speed << setw(8) << "Gold: " << r.gold << endl;

	return out;
}

War::War()
{
	//Создание армии людей
	while (size)
	{
		int th = rand() % 3 + 1;
		switch (th)
		{
		case KNIGHT: {Knight kn; humans.push_front(kn); } break;
		case ARCHER: {Archer ar; humans.push_front(ar); } break;
		case RIDER: {Rider r; humans.push_front(r); } break;
		default:break;
		}

		//Создание армии монстров
		int tm = rand() % 3 + 1;
		switch (tm)
		{
		case ORC: {Orc or ; monsters.push_front(or ); } break;
		case GOBLIN: {Goblin gb; monsters.push_front(gb); } break;
		case DRAGON: {Dragon dr; monsters.push_front(dr); } break;
		default:break;
		}
		size--;
	}
}

void War::the_fight()
{
	string S(66, '-');
	system("cls");
	cout << "\t\t\tFIGHT!!!" << endl;
	cout << S << endl;
	int nH, nM;
	int gold;
	while (humans.getSize() > 0 && monsters.getSize() > 0)
	{
		//Рандомный выбор соперников
		nH = rand() % humans.getSize();
		nM = rand() % monsters.getSize();
		Race nHum, nMon;
		nHum = humans.pop_at(nH);
		nMon = monsters.pop_at(nM);
		cout << endl;
		cout << "FROM HUMANS: " << nHum << endl;
		cout << S << endl << endl;
		cout << "FROM MONSTERS: " << nMon << endl;
		int f = 0;
		cout << S << endl << endl;
		while (nHum.getLife() > 0 && nMon.getLife() > 0)
		{
			//Очередность определяется по скорости воина, у кого больше скорость тот бьет первым
			cout << "ATTACK:" << endl;
			if (nHum.getSpeed() > nMon.getSpeed())
			{
				cout << "First: " << nHum.getType() << endl;
				nHum.attack(nMon);
				f = 1;
			}
			else
			{
				cout << "First: " << nMon.getType() << endl;
				nMon.attack(nHum);
				f = 2;

			}
			if (f == 1 && nMon.getLife() > 0)
			{
				cout << "Second: " << nMon.getType() << endl;
				nMon.attack(nHum);
			}
			else if (f == 2 && nHum.getLife() > 0)
			{
				cout << "Second: " << nHum.getType() << endl;
				nHum.attack(nMon);
			}
		}
		cout << S << endl << endl;
		cout << "WINNER BATTLE: " << endl;
		if (nHum.getLife() <= 0)
		{
			cout << "Winner - " << nMon.getType() << endl;
			gold = nMon.getGold() + nHum.getGold();
			nMon.setGold(gold);
			monsters.push_back(nMon);
			cout << S << endl << endl;
		}
		else if (nMon.getLife() <= 0)
		{
			cout << "Winner - " << nHum.getType() << endl;
			gold = nHum.getGold() + nMon.getGold();
			nHum.setGold(gold);
			humans.push_back(nHum);
			cout << S << endl << endl;
		}
	}
	print();
	cout << S << endl << endl;
	if (humans.ifEmpty())
		cout << "\t\tTHE MONSTERS WON THE BATTLE !!!" << endl << endl;
	else if (monsters.ifEmpty())
		cout << "\t\tTHE HUMANS WON THE BATTLE !!!" << endl << endl;
	cout << S << endl << endl;
	cout << "\t\t\tEND FIGHT!!!" << endl << endl;
}


void War::print()
{
	system("cls");
	string S(60, '-');
	cout << "HUMANS:\n" << endl;
	if (humans.getSize() != 0)
		humans.print();
	cout << S << endl << endl;
	cout << "MONSTERS:\n" << endl;
	if (monsters.getSize() != 0)
		monsters.print();
	cout << S << endl << endl;
}
