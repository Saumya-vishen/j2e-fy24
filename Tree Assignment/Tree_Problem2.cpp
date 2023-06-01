#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isMirror(TreeNode* p, TreeNode* q); 
bool isSymmetric(TreeNode* root) {
    if (root == nullptr) {
        return true; 
    }
    
    return isMirror(root->left, root->right);
}

bool isMirror(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    
    if (p == nullptr || q == nullptr || p->val != q->val) {
        return false;
    }
    
    return isMirror(p->left, q->right) && isMirror(p->right, q->left);
}

int main() {
   
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    bool result = isSymmetric(root);
    std::cout << "The tree is " << (result ? "symmetric" : "not symmetric") << std::endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}