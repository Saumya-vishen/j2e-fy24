#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int getHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    int heightDiff = std::abs(leftHeight - rightHeight);

    if (heightDiff > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    bool result = isBalanced(root);
    std::cout << "The tree is " << (result ? "balanced" : "not balanced") << std::endl;

    
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}