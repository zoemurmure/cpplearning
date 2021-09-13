#ifndef TREENODE_H
#define TREENODE_H
class BinStrTree;
class TreeNode {
    friend class BinStrTree;
public:
    TreeNode(std::string &v="", int c=0):
        value(v), count(c), left(nullptr), right(nullptr) { }
    TreeNode(const TreeNode&);
    TreeNode& operator= (const TreeNode&);
    ~TreeNode();
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode::TreeNode(const TreeNode &tn):
    value(tn.value), count(tn.count), left(nullptr), right(nullptr) {
    if (tn.left) {
        left = new TreeNode(*tn.left);
    } 
    if (tn.right) {
        right = new TreeNode(*tn.right);
    }
}

TreeNode& TreeNode::operator= (const TreeNode *rhs) {
    value = rhs.value;
    count = rhs.count;
    TreeNode *temp = nullptr;
    if (rhs.left) {
        temp = new TreeNode(rhs.left);
    }
    delete left;
    left = temp;

    temp = nullptr;
    if (rhs.right) {
        temp = new TreeNode(rhs.right);
    }
    delete right;
    right = temp;
    return *this;
}

TreeNode::~TreeNode() {
    delete left;
    delete right;
}
#endif