#include<iostream>  
#include "ex12_19.h"
#include <fstream>
using namespace std;
int main()
{
	std::ifstream ifs("book.txt");
	StrBlob blob;
	for (string str; getline(ifs, str); )
		blob.push_back(str);
	for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend; pbeg.incr())
		cout << pbeg.deref() << endl;
	system("pause");
}
