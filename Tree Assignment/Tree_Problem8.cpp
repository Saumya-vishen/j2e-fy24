#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* sortedArrayToBST(const std::vector<int>& nums, int start, int end) {
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, start, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, end);

    return root;
}

TreeNode* sortedArrayToBST(const std::vector<int>& nums) {
    int n = nums.size();
    return sortedArrayToBST(nums, 0, n - 1);
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    
    std::vector<int> nums = {-10, -3, 0, 5, 9};

    TreeNode* root = sortedArrayToBST(nums);

    std::cout << "Inorder Traversal of the BST: ";
    inorderTraversal(root);  
    std::cout << std::endl;

    return 0;
}