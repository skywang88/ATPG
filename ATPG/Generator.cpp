#include"Generator.h"
#include<cmath>
#include<set>
#define min(a,b) (a<b?a:b)
using namespace std;
set<_int64> scflag;
struct clause
{
	int a;  //original num, 5 represent 101   A!BC
	int b;  //cover num, a=5 and b=2 represent 1x1, i.e., AC 
	int c; //count one num for a, when a=3,5,6, c=2
	_int64 d; //flag for contain clauses
};

int CountOne(int N)
{
	int count=0;
	while (N != 0) {
		N = ((N - 1)&N);
		count++;
	}
	return count;
}
int IsCountOne(int N)
{
	if (((N - 1)&N) == 0)
		return 1;
	else return 0;
}

int RandInt(int a, int b)
{ 

}

int MergeClause(clause &a, clause &b, clause &c)
{
	if (abs(a.d - b.d) == 1)
		return 0;
	if ((a.c!=b.c)||(!IsCountOne(a.a^b.a)))
		return 0;
	if (scflag.find(c.d = a.d | b.d) != scflag.end()) {
		c.a = a.a &b.a;
		c.b = (a.a^b.a) | c.b;
		c.c = min(a.c, b.c);
		return 1;
	}

}

void QM(vector<clause> &setc)
{
	clause c;
	while (1) {
		for (int i = 0; i < setc.size(); i++) {
			for (int j = 1; j < setc.size(); j++) {
				MergeClause(setc[i], setc[j], c);
			}
		}
	}
}


void Generator(int Innum, int Outnum)
{
	int TinputC = pow(2, Innum);
	int *flag = new int[TinputC];
	vector<clause> Group;
	int nnum;
	clause fsc;
	for (nnum = 0; nnum < Outnum; nnum++) {
		int knum = rand()%64;
		memset(flag, 0, sizeof(int)*TinputC);
		Group.clear();
		for(int kn=0; kn<knum;kn++) {
			do {
				fsc.a = rand() % TinputC;
			} while (flag[fsc.a]);
			fsc.b = 0;
			fsc.c = CountOne(fsc.a);
			fsc.d = 1 << kn;
			scflag.insert(fsc.d);
			Group.emplace_back(fsc);
			QM(Group);
		}
	}
}