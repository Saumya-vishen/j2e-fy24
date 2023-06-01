#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;  
    }
    
    
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
}

int main() {
   
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    TreeNode* invertedRoot = invertTree(root);
    
    std::cout << "Inverted Tree: ";
    std::cout << invertedRoot->val << " ";
    std::cout << invertedRoot->left->val << " ";
    std::cout << invertedRoot->right->val << " ";
    std::cout << invertedRoot->left->left->val << " ";
    std::cout << invertedRoot->left->right->val << " ";
    std::cout << invertedRoot->right->left->val << " ";
    std::cout << invertedRoot->right->right->val << std::endl;

    delete invertedRoot->left->left;
    delete invertedRoot->left->right;
    delete invertedRoot->right->left;
    delete invertedRoot->right->right;
    delete invertedRoot->left;
    delete invertedRoot->right;
    delete invertedRoot;

    return 0;
}





 
