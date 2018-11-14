//
//  ex13_27.h
//  Exercise 13.27
#ifndef EX13_27_H
#define EX13_27_H
#include <string>
using namespace std;
class HasPtr {
public:
	HasPtr(const string &s=string()):ps(new string(s)),i(0),use(new size_t(1)) { }
	//拷贝构造函数
	HasPtr(const HasPtr &p) :ps(p.ps), i(p.i), use(p.use) { ++*use; }
	HasPtr& operator=(const HasPtr &rhs) {
		++*rhs.use;
		if (--*use == 0) {
			delete ps;
			delete 
		}
		ps = rhs.ps;
		i = rhs.i;
		use = rhs.use;
		return *this;
	}
	~HasPtr()
	{
		if (--*use == 0)
		{
			delete ps;
			delete use;
		}
	}
private:
	string *ps;
	int i;
	size_t *use;
};
#endif // !EX13_27_H

