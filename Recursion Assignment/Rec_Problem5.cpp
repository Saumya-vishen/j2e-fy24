#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> generateFullBinaryTrees(int n) {
   
    if (n % 2 == 0 || n == 0) {
        return {};
    }

    if (n == 1) {
        return { new TreeNode(0) };
    }

    vector<TreeNode*> result;

    for (int i = 1; i < n; i += 2) {
        vector<TreeNode*> leftSubtrees = generateFullBinaryTrees(i);
        vector<TreeNode*> rightSubtrees = generateFullBinaryTrees(n - i - 1);

        for (TreeNode* left : leftSubtrees) {
            for (TreeNode* right : rightSubtrees) {
                TreeNode* root = new TreeNode(0);
                root->left = left;
                root->right = right;
                result.push_back(root);
            }
        }
    }

    return result;
}

void printBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->val << " ";
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

void deleteBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<TreeNode*> trees = generateFullBinaryTrees(n);

    cout << "All possible full binary trees with " << n << " nodes:" << endl;
    for (TreeNode* tree : trees) {
        printBinaryTree(tree);
        cout << endl;
    }

    
    for (TreeNode* tree : trees) {
        deleteBinaryTree(tree);
    }

    return 0;
}