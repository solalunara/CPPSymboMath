#ifndef OPERATOR_H
#define OPERATOR_H
#pragma once

#include "Node.h"
#include <functional>

#define NonBinClass template<typename... T> class
#define BinClass template<typename T0, typename T1> class

NonBinClass Operator : 
	public Node
{
public:
	Operator( string s, T... Children ) : Node( s ), Children( Children... )
	{
	}

	virtual Node *Simplify()
	{
		return this;
	}

	tuple<T...> Children;
};

BinClass BinaryOperator : 
	public Operator<T0, T1>
{
public:
	BinaryOperator( string s, T0 Left, T1 Right ) : Operator( s, Left, Right )
	{
	}
};

NonBinClass Plus : 
	public Operator<T...>
{
public:
	Plus( T... Args ) : Operator( "+", Args... )
	{
	}

	virtual Node *Simplify()
	{
		//Const<int> *c = dynamic_cast<Const<int>*>( get<0>( this->Children ) );

		IterateChildren< std::tuple_size<decltype( this->Children )>::value >( [] ( int N, Node *n )
		{
			cout << "working" << endl;
		} );

		return this;
	}

	template<int N>
	void IterateChildren( std::function<void( int, Node* )> f)
	{
		f( N, get<N>( this->Children ) );
		if ( N )
			IterateChildren<N - 1>();
	}
};

NonBinClass Times : 
	public Operator<T...>
{
public:
	Times( T... Args ) : Operator( "*", Args... )
	{
	}
};

BinClass Minus : 
	public BinaryOperator<T0, T1>
{
public:
	Minus( T0 Left, T1 Right ) : BinaryOperator( "-", Left, Right)
	{
	}
};

BinClass Div :
	public BinaryOperator<T0, T1>
{
public:
	Div( T0 Left, T1 Right ) : BinaryOperator( "/", Left, Right )
	{
	}
};

#endif