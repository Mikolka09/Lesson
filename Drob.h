#pragma once
#include<iostream>
using namespace std;

namespace myWorks
{
	namespace myDrob
	{
		class Drob
		{
		public:
			Drob()
			{

			}

			int NOD(int a, int b)
			{
				for (int i = a; i > 0; i--)
				{
					if (a % i == 0 && b % i == 0)
						return i;
				}
			}

			Drob(int c, int ch, int zn)
			{
				if (zn > 0)
				{
					m_c = c;
					m_ch = ch;
					m_zn = zn;
				}
				else
				{
					cout << "input error" << endl;
					return;
				}
			}
			~Drob()
			{

			}

			void print()
			{
				if (m_c)
					cout << m_c << " " << m_ch << "/" << m_zn << endl;
				else
					cout << m_ch << "/" << m_zn << endl;
			}

			Drob add(Drob b)
			{
				Drob x;
				x.m_zn = m_zn * b.m_zn;
				x.m_ch = m_ch * b.m_zn + m_zn * b.m_ch;
				x.FSD();
				return x;
			}

			Drob operator+(Drob b)
			{
				Drob x;
				x.m_zn = m_zn * b.m_zn;
				x.m_ch = m_ch * b.m_zn + m_zn * b.m_ch;
				x.FSD();
				return x;
			}

			int getC() const { return m_c; }
			int getCh() const { return m_ch; }
			int getZn() const { return m_zn; }

			operator float()
			{
				return m_c + (float)m_ch / m_zn;
			}

		private:
			int m_c = 0, m_ch = 0, m_zn = 1;

			void FSD()
			{
				if (abs(m_ch) > m_zn)
				{
					if (m_c >= 0 && m_ch > 0)
					{

						m_c += m_ch / m_zn;
						m_ch = m_ch % m_zn;
					}
					else
					{
						if (m_c < 0)
						{
							m_c -= m_ch / m_zn;
							m_ch = m_ch % m_zn;
						}
						else
							if (m_ch < 0)
							{
								m_c = m_ch / m_zn;
								m_ch = abs(m_ch) % m_zn;
							}
					}

				}
				if (m_ch != 0)
				{
					int nod = NOD(abs(m_ch), m_zn);
					if (nod != 1)
					{
						m_ch /= abs(nod);
						m_zn /= abs(nod);
					}
				}
				if (m_zn == m_ch)
				{
					m_ch = 0;
					m_c++;
				}

			}


		};
	}

}
