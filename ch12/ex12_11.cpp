/***************************************************************************
*  @file       The code is for the exercises in C++ Primmer 5th Edition
*  @author     youyu Xu
*  @date       24  10 2018
*
*  @remark
***************************************************************************/
//利用p的get函数得到的内置指针来初始化临时的智能指针，一旦调用结束，该临时指针会被销毁，内置指针所指的
//对象内存会被释放，p会变成空悬指针，试图使用p时显示未定义，并且，销毁p时这块内存会被二次delete；
#include <iostream>
#include <memory>

using namespace std;
void process(shared_ptr<int> ptr)
{
	cout<< "inside the process function: " << ptr.use_count() << endl;
}

int main()
{
	shared_ptr<int> p(new int(42));
	process(shared_ptr<int>(p.get()));
	system("pause");
	return 0;
}
