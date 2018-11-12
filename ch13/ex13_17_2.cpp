#include <iostream>
using namespace std;

class numbered {
public:
	numbered() {
		mysn = unique++;
		cout << "默认构造" << endl;
	}
	numbered(const numbered& n) {
		mysn = unique++;
		cout << "拷贝构造" << endl;
	}
	int mysn;
	static int unique;
};
int numbered::unique = 10;
void f(numbered s) {
	cout << s.mysn << endl;
}
int main() {
	numbered a,b=a,c=b;
	cout << a.unique << endl;
	f(a);
	f(b);
	f(c);
	cout << a.unique << endl;
	system("pause");
}
