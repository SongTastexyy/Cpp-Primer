//
//  ex13_28.h
//  Exercise 13.28
#ifndef EX13_28_H
#define EX13_28_H
#include <string>
using namespace std;
class TreeNode {
public:
	TreeNode():value(string()),count(new int(1)),left(nullptr),right(nullptr) { }
	TreeNode(const TreeNode &rhs) :value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
	TreeNode& operator=(const TreeNode &rhs)
	{
		++*rhs.count;
		if (--*count == 0)
		{
			delete left;
			delete right;
			delete count;
		}
		value = rhs.value;
		left = rhs.left;
		right = rhs.right;
		count = rhs.count;
		return *this;
	}
	~TreeNode() {
		if (--*count == 0) {
			delete left;
			delete right;
			delete count;
		}
	}
private:
	string value;
	int    *count;
	TreeNode *left;
	TreeNode *right;
};

class BinStrTree {
public:
	BinStrTree():root(new TreeNode()) { }
	BinStrTree(const BinStrTree &bst):root(new TreeNode(*bst.root)) { }
	BinStrTree& operator=(const BinStrTree &bst) {
		TreeNode *new_root = new TreeNode(*bst.root);
		delete root;
		root = new_root;
		return *this;
	}
	~BinStrTree() { delete root; }
private:
	TreeNode *root;
};
#endif
