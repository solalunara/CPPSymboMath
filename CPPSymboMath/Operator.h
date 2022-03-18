#ifndef OPERATOR_H
#define OPERATOR_H
#pragma once

#include "Node.h"

template<typename... T>
class Operator : Node
{
public:
	Operator( string s, T... Children ) : Node( s ), Children( Children... )
	{}

	tuple<T...> Children;
};

template<typename T0, typename T1>
class BinaryOperator : Operator<T0, T1>
{
public:
	BinaryOperator( string s, T0 Left, T1 Right ) : Operator( s, Left, Right )
	{}
};

template<typename... T>
class Plus : Operator<T...>
{
public:
	Plus( T... Args ) : Operator( "+", Args... )
	{}
};

#endif