#include <iostream>
#include <string>

using namespace std;

int main(int argc, char**argv)
{
	//动态分配char数组
	char *s1 = (char*)"abc";
	char *s2 = (char*)"efc";  //字符串字面常量，末尾有空格
     
	char *p = new char[strlen(s1) + strlen(s2) + 1];
	strcpy(p, s1);
	strcat(p, s2);
	cout << p << endl;
	delete[] p;
	//string
	string str1{ "hello" }, str2{ "world" };
	cout << str1 + str2 << endl;
	system("pause");
	return 0;
}
