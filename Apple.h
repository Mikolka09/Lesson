#pragma once


class Apple
{
	Apple* apple = nullptr;
	int size = 0;
	int weight;
public:
	Apple();
	Apple(int r);
	//Apple(const Apple &obj);
	~Apple();
	void print();
	Apple operator+(Apple b);
	Apple operator*(int b);
	Apple operator+=(Apple b);
	bool operator==(Apple b);
	bool isEqual(Apple b);
	Apple operator[](int i);
	//Apple operator=(const Apple &obj);

private:

};

inline Apple::Apple()
{
}

Apple::Apple(int w)
{
	apple = new Apple;
	apple->size = 1;
	apple->weight = w;
	size = 1;
	weight = w;
}

//inline Apple::Apple(const Apple & obj)
//{
//	this->size = obj.size;
//	this->weight = obj.weight;
//	this->apple = new Apple[this->size];
//	for (size_t i = 0; i < this->size; i++)
//	{
//		this->apple[i] = obj.apple[i];
//	}
//}

Apple::~Apple()
{
}

inline void Apple::print()
{
	cout << "Size - " << size << endl;
	cout << "Weight - " << weight << endl;
	if (size > 1)
	{
		cout << "--------------------------" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << "Вес - " << apple[i].weight << endl;
		}
	}
}

inline Apple Apple::operator+(Apple b)
{
	Apple k;
	k.size = this->size + b.size;
	k.weight = this->weight + b.weight;
	k.apple = new Apple[k.size];
	int j = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		k.apple[j++] = this->apple[i];
	}
	for (size_t i = 0; i < b.size; i++)
	{
		k.apple[j++] = b.apple[i];
	}
	return k;
}

inline Apple Apple::operator*(int b)
{
	Apple k;
	k.size = b * this->size;
	k.weight = b * this->weight;
	k.apple = new Apple[k.size];
	int m = 0;
	for (size_t i = 0; i < b; i++)
	{
		for (size_t j = 0; j < this->size; j++)
		{
			k.apple[m++] = this->apple[j];
		}
	}
	return k;
}

inline Apple Apple::operator+=(Apple b)
{
	*this = *this + b;
	return *this;
}

inline bool Apple::operator==(Apple b)
{
	return this->size == b.size && this->weight == b.weight;
}

inline bool Apple::isEqual(Apple b)
{
	if (!(*this == b))
		return false;
	Apple* tmp = new Apple[b.size];
	for (size_t i = 0; i < b.size; i++)
	{
		tmp[i] = b.apple[i];
	}
	int tmpSize = b.size;
	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = 0; j < tmpSize; j++)
		{
			if (this->apple[i].weight == tmp[j].weight)
			{
				Apple* newTmp = new Apple[tmpSize - 1];
				for (size_t k = 0; k < j; k++)
				{
					newTmp[k] = tmp[k];
				}
				for (size_t k = j + 1; k < tmpSize; k++)
				{
					newTmp[k - 1] = tmp[k];
				}
				delete[]tmp;
				tmpSize--;
				tmp = newTmp;
			}
		}
	}
	return !tmpSize;
}

inline Apple Apple::operator[](int i)
{
	Apple k;
	k.size = apple[i].size;
	k.weight = apple[i].weight;
	k.apple = new Apple[1];
	k.apple[0] = apple[i];
	return k;
}

//inline Apple Apple::operator=(const Apple & obj)
//{
//	this->size = obj.size;
//	this->weight - obj.weight;
//	this->apple = new Apple[this->size];
//	for (size_t i = 0; i < this->size; i++)
//	{
//		this->apple[i] = obj.apple[i];
//	}
//	return *this;
//}



	//Apple a(4);
	//Apple b(2);
	//Apple c(3);
	//Apple d(3);
	//Apple k1;
	//k1 = a + b;
	//Apple k2;
	//k2 = c + d;
	////cout << (k1 == k2) << endl;
	////cout << k1.isEqual(k2) << endl;
	////k1.print();
	//cout << endl;
	////k1.apple[1].print();
	//k2[1].print();
	//k1[0].print();
	//Apple x;
	//x = k1[1] + k2[1];
	//x.print();

	////a.print();
	////k.print();

	///*if (k1 == k2)
	//	cout << "===" << endl;*/
	///*Apple mk = a * 5;
	//mk.print();*/


//+ - * / % += -= *= /= %= < > <= >= == ! !== [] () -> ++a a++ --a a-- ^ | & ~ && || << >>   - можно перегрузить

// :: ?: . .* sizeof # typeid - нельзя перегрузить