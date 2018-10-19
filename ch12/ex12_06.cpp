/***************************************************************************
*  @file       The code is for the exercises in C++ Primmer 5th Edition
*  @author     youyu Xu
*  @date       18  10 2018
*           
*  @remark
***************************************************************************/
#include <iostream> 
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
using Ptr = std::vector<int>*;

Ptr make_dynamically()
{   
	return new vector<int>{};
}
Ptr populate(Ptr vec)
{
	for (int i; cout << "please input:\n", cin >> i; vec->push_back(i));
	return vec;
}

void print(Ptr vec)
{
	for (auto i : *vec)
	{
		cout << i << endl;
	}
}
int main()
{
	vector<int>* ss = make_dynamically();
	ss = populate(ss);
	print(ss);
	delete ss;
	system("pause"); 
	return 0;
}
