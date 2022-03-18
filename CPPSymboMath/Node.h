#ifndef NODE_H
#define NODE_H
#pragma once

#include <string>
#include <iostream>
#include <tuple>

using std::string;
using std::cout;
using std::endl;
using std::to_string;
using std::tuple;

class Node
{
public:
	Node( string s ) : s( s ) 
	{
	}

	string s;
};

template<typename T>
class Const
	: public Node
{
public:
	Const( T t ) : Node( std::to_string( t ) ), TValue( t )
	{
	}

	T TValue;
};

class Var
	: public Node
{
public:
	Var( string s ) : Node( s )
	{
	}
};

enum class FunctionType
{
	Abs, Acos, Asin, Atan, Sqrt, Cos, Exp, Pow, Sin, Tan
};

class Function
	: public Node
{
public:
	Function( string s ) : Node( s )
	{
		
	}
};


#endif