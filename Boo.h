#pragma once

namespace Boo
{
	int operation(int a, int b)
	{
		return a - b;
	}
}

namespace Foo
{
	int oper(int a, int b)
	{
		return a + b;
	}
}

namespace Koo
{
	namespace Doo
	{
		int oper1(int a, int b)
		{
			return a + b;
		}
	}
}
