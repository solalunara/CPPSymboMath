#include "Operator.h"

#define n( a ) new int( a )

//Operator<int*, int*, int*, int*, int*, int*, int*> o = Operator<int*, int*, int*, int*, int*, int*, int*>( "+", n( 0 ), n( 1 ), n( 2 ), n( 3 ), n( 4 ), n( 5 ), n( 6 ) );

Plus<Node *, Node *> p = Plus<Node *, Node *>( new Const<int>( 0 ), new Var( "x" ) );

int main()
{
	Node *n = p.Simplify();
	Node np = *n;
	return 0;
}

