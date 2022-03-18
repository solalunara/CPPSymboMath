#ifndef NODE_H
#define NODE_H
#pragma once

#include <string>
#include <iostream>
#include <tuple>
#include <map>

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

	virtual void Print()
	{

	}
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

#define MapElement( a ) {FuncType::a, "a"}

enum class FuncType : char
{
	Sin, Cos, Tan,
	Sqrt, Ln
};
std::map<FuncType, string> GetFunctionString{ MapElement( Sin ), MapElement( Cos ), MapElement( Tan ), MapElement( Sqrt ), MapElement( Ln ) };

class Func
	: public Node
{
public:
	Func( FuncType f ) : Node( GetFunctionString[ f ] )
	{
	}
};


#endif