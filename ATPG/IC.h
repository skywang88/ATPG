#pragma once
#include<vector>
#include<string>
#include<map>
using INPUT = int;
using OUTPUT = int;
enum LineDef
{
	in,
	out
};
enum Gatefunc
{
	NOT,
	AND,
	NAND,
	OR,
	NOR,
	XOR,
	XNOR
};