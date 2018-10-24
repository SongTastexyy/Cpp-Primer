/***************************************************************************
*  @file       The code is for the exercises in C++ Primmer 5th Edition
*  @author     youyu Xu
*  @date       23  10 2018
*
*  @remark
***************************************************************************/
//练习12.10  正确的
#include <iostream>
#include <memory>
using namespace std;
void process(shared_ptr<int> ptr)
{
	cout << "inside the process function: " << ptr.use_count() << endl;
}
int main()
{
	shared_ptr<int> p(new int(42));
	process(shared_ptr<int>(p));

	cout << p.use_count() << endl;
	auto q = p;
	std::cout << p.use_count() << "\n";
	system("pause");
	return 0;
}
