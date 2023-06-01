#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val)
        return root;

    if (val < root->val)
        return searchBST(root->left, val);

    return searchBST(root->right, val);
}

int main() {
    
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;
    TreeNode* result = searchBST(root, val);

    if (result != nullptr)
        std::cout << "Subtree rooted at node with value " << val << " exists." << std::endl;
    else
        std::cout << "Subtree rooted at node with value " << val << " does not exist." << std::endl;

    return 0;
}