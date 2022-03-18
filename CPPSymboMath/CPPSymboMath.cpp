#include <iostream>
#include "Node.h"
#include <tuple>
#include <type_traits>

Operator<int, int, int, int, int, int, int> o = Operator<int, int, int, int, int, int, int>( "+", 0, 1, 2, 3, 4, 5, 6 );

int main()
{
	cout << get<0>( o.Children ) << endl;
}

