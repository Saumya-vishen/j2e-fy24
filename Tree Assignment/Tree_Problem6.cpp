#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr) {
    if (root == nullptr)
        return true;

    if (minNode != nullptr && root->val <= minNode->val)
        return false;

    if (maxNode != nullptr && root->val >= maxNode->val)
        return false;

    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

int main() {
   
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    bool isValid = isValidBST(root);
    std::cout << (isValid ? "Valid BST" : "Not a valid BST") << std::endl;  // Output: Valid BST

    
    return 0;
}