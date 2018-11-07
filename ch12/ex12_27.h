//exercise 12_27 使用标准库：文本查询程序
//created by youyu xu
#ifndef EX_12_27_H
#define EX_12_27_H
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include<algorithm>
using namespace std;
class QueryResult;
class TextQuery
{
public:
	using line_on = vector<string>::size_type;
	TextQuery (ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	//每个单词到它行数的映射
	map<string, shared_ptr<set<line_on>>> wm;
};

class QueryResult {
	friend ostream& print(ostream&, const QueryResult&);
public:
QueryResult(string s,shared_ptr<set<TextQuery::line_on>>p,shared_ptr<vector<string>> f):
    sought(s),lines(p),file(f){ }
private:
	string sought; //查询单词
	shared_ptr<set<TextQuery::line_on>> lines; //出现的行号
	shared_ptr<vector<string>> file;
};

TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is, text))        //对每一行
	{
		file->push_back(text);
		int n = file->size() - 1;    //当前行号
		istringstream line(text);
		string word;
		while (line >> word)        //对行内的每个单词
		{
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_on>);
			lines->insert(n);
		}
	}
}
QueryResult TextQuery::query(const string &sought) const
{
	//如果未找到sought，将返回一个指向此set的指针
	static shared_ptr<set<line_on>> nodata(new set<line_on>);
	//使用find而不是下标运算符查找单词，避免将单词添加到wm中
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr)
{
	//找到单词了打印出现次数和出现的位置
	os << qr.sought << "occurs" << qr.lines->size() << " "
		<< (qr.lines->size() > 1 ? "times" : "time") << endl;
	//打印单词出现的每一行
	for (auto i : *qr.lines)
	{
		os << "\t(line" << i + 1 << ") " << *(qr.file->begin() + i) << endl;

	}
	return os;
}
#endif // !EX_12_27_H
