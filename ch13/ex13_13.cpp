#include <iostream>
#include <vector>
using namespace std;
struct X {
	X() { std::cout << "构造函数" << std::endl; }
	X(const X&) { std::cout << "拷贝构造" << std::endl; }
	X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
	~X() { std::cout << "~X()析构" << std::endl; }
};

void f(const X &rx, const X &x)
{
	std::vector<X> vec;
	vec.reserve(1);
	vec.push_back(rx);
	vec.push_back(x);
}

int main()
{
	X *px = new X;
	f(*px, *px);
	delete px;
	system("pause");
	return 0;
}
