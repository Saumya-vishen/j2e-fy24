#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;

    TreeNode* merged = new TreeNode(root1->val + root2->val);
    merged->left = mergeTrees(root1->left, root2->left);
    merged->right = mergeTrees(root1->right, root2->right);

    return merged;
}

void printInorder(TreeNode* root) {
    if (root == nullptr)
        return;

    printInorder(root->left);
    std::cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    TreeNode* mergedTree = mergeTrees(root1, root2);
    printInorder(mergedTree);  
    return 0;
}