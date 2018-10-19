#include <iostream>
#include <vector>
#include <memory>
using namespace std;

using Sptr = shared_ptr<vector<int>>;

auto make_with_shared_ptr()
{
	return make_shared<vector<int>>();
}

auto populate(Sptr vec)
{
	for (int i; cout << "Please input：\n", cin >> i; vec->push_back(i));
	return vec;
}

void vector_k(Sptr _ptr)
{
	for (size_t i = 0; i < (*_ptr).size(); ++i)
	{
		cout << (*_ptr)[i] << endl;
	}
}

int main()
{
	Sptr my_vector = make_with_shared_ptr();
	my_vector = populate(my_vector);
	vector_k(my_vector);
	cout << (*my_vector).size() << endl;
	system("pause");
	return 0;
}
