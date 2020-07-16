#include "Warrior.h"

void Race::attack()
{
}

ostream& operator<<(ostream& out, const Race& r)
{
	out << setw(8) << r.type << setw(10) << "Life: " << r.life << setw(12) << "Damage: "
		<< r.damage << setw(10) << "Speed: " << r.speed << setw(10) << "Gold: " << r.gold << endl;

	return out;
}

War::War()
{
	//Создание армии людей
	while (size)
	{
		int tp = rand() % 3 + 1;
		switch (tp)
		{
		case KNIGHT: {Knight kn; humans.push_front(kn); } break;
		case ARCHER: {Archer ar; humans.push_front(ar); } break;
		case RIDER: {Rider r; humans.push_front(r); } break;
		default:break;
		}
		size--;
	}

	//Создание армии монстров
	while (size)
	{
		int tp = rand() % 3 + 1;
		switch (tp)
		{
		case ORC: {Orc or; humans.push_front(or); } break;
		case GOBLIN: {Goblin gb; humans.push_front(gb); } break;
		case DRAGON: {Dragon dr; humans.push_front(dr); } break;
		default:break;
		}
		size--;
	}
}

void War::print()
{
}
