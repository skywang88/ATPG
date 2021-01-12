// ATPG.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<fstream>
#include<string>
#include <algorithm>
#include"IC.h"
using namespace std;

struct Interval
{
	int Start_Num;
	int End_Num;
	int Num_count;
};
Interval Input_Lines;
Interval Connect_Lines;
Interval Output_Lines;
struct gate
{
	int func;
	INPUT a;
	INPUT b;
	OUTPUT c;
};
string signDef[] = { "INPUT", "OUTPUT", "DFF" };
string funcString[] = { "NOT","AND","NAND","OR","NOR","XOR","XNOR"};
gate *Gates;
gate *Lines;

void Generator()
{

}

void readbuff(vector<string> &readinf, string &stringbuff)
{
	readinf.clear();
	string::size_type start=0, end = 0;
	transform(stringbuff.begin(), stringbuff.end(), stringbuff.begin(), ::toupper);
	while (stringbuff[start] == '(' || stringbuff[start] == ')'
		|| stringbuff[start] == ',' || stringbuff[start] == ' ') 
		start++;
	for (end =start; end < stringbuff.size();end++ ){
		if (stringbuff[end] == '(' || stringbuff[end] == ')'
			|| stringbuff[end] == ',' || stringbuff[end] == ' ')
		{
			readinf.emplace_back(stringbuff, start, end-start);
			while (stringbuff[end] == '(' || stringbuff[end] == ')'
				|| stringbuff[end] == ',' || stringbuff[end] == ' ')
				end++;
			start = end;
		}
	}
}

void readfile(const char *filename)
{
	int nindex = 0;
	int readmode;
	int beginmode = 0;;
	ifstream INF(filename);
	string stringbuff;
	vector<string> readinf;
	while (!INF.eof())
	{
		getline(INF, stringbuff);
		if (stringbuff[0] == '#') {
			continue;
		}
		readbuff(readinf, stringbuff);
		for (int i = 0; i < readinf.size(); i++) {
			cout << readinf[i] << "\t";
		}
		cout << endl;
		for (readmode = beginmode; readmode < 3; readmode++) {
			if (readinf[0] == signDef[readmode]) {
				indexmap[readinf[1]]= nindex;
				nindex++;
				break;
			}
		}
		for()
	}
}

void chekers(vector<INPUT> pattern, OUTPUT eline)
{
	
}

void Solver()
{

}


int main()
{
	readfile("test.txt");
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
