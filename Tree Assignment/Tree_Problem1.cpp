#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
   
    if (p == nullptr && q == nullptr) {
        return true;
    }
    
    if (p == nullptr || q == nullptr || p->val != q->val) {
        return false;
    }
    
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = isSameTree(p, q);
    std::cout << "The trees are " << (result ? "same" : "different") << std::endl;

    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    return 0;
}