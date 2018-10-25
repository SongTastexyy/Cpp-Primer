/ex12_19.h
//created by youyu xu
#ifndef EX12_19_H
#define EX12_19_H
#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using namespace std;
class StrBlobPtr;
class StrBlob {
public:
	typedef vector<string>::size_type size_type;
	friend class StrBlobPtr;
	StrBlobPtr begin();
	StrBlobPtr end();
	StrBlob():data(make_shared<vector<string>>()) { }
	StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)) {}

	size_type size() const { return data->size(); }
	bool empty() { return data->empty(); }
	//元素添加和删除
	void push_back(const string &t) { data->push_back(t); }
	void pop_back() {
		check(0, "pop_back on empty StrBlob");
		data->pop_back();
	}
	//元素访问
	string& front() {
		check(0, "front on empty StrBlob");
		return data->front();
	}
	string& back() {
		check(0, "back on empty StrBlob");
		return data->back();
	}
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const {
		if (i >= data->size()) throw out_of_range(msg);
	}

};
class StrBlobPtr {
public:
	StrBlobPtr():curr(0) { }
	StrBlobPtr(StrBlob &a,size_t sz=0):wptr(a.data),curr(sz) { }
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
	
	string& deref() const {
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	StrBlobPtr& incr() {
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}
private:
	shared_ptr<vector<string>> check(size_t i, const string& msg) const {
		auto ret = wptr.lock();
		if (!ret)
			throw runtime_error("unbond StrBlobPtr");
		if (i >= ret->size())
			throw out_of_range(msg);
		return ret; //返回指向vector的shared_ptr
	}
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}
#endif // !EX12_19_H
