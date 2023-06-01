#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> st;
    TreeNode* curr = root;
    int count = 0;

    while (curr != nullptr || !st.empty()) {
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        count++;

        if (count == k)
            return curr->val;

        curr = curr->right;
    }

    return -1; 
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 1;
    int kthSmallestValue = kthSmallest(root, k);
    std::cout << "Kth Smallest Element: " << kthSmallestValue << std::endl;  // Output: 1

    return 0;
}