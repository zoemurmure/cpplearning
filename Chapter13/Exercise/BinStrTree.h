#ifndef BINSTRTREE_H
#define BINSTRTREE_H
#include "TreeNode.h"

class BinStrTree {
public:
    BinStrTree(const TreeNode &tn = TreeNode()):
        root(new TreeNode(tn)) { }
    BinStrTree(const BinStrTree &bt):
        root(new TreeNode(*bt.root)) { }
    BinStrTree& operator= (const BinStrTree&);
    ~BinStrTree() { delete root; }
private:
    TreeNode *root;
};

BinStrTree& BinStrTree::operator= (const BinStrTree &rhs) {
    auto temp = new TreeNode(*rhs.root);
    delte root;
    root = temp;
    return *this;
}

#endif