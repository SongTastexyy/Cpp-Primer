#include "ex12_27.h"
#include <iostream>

using namespace std;

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter the word to look for,or q to quit" << endl;
		string s;
		if (!(cin >> s) || s == "q") break;
		print(cout,tq.query(s))<<endl;
	}
}
int main()
{
	ifstream file("1.txt");
	runQueries(file);
}
