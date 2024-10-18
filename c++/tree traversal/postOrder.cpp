#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to perform post-order traversal
void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    postOrderTraversal(root->left);

    // Traverse the right subtree
    postOrderTraversal(root->right);

    // Visit the current node
    std::cout << root->val << " ";
}

// Function to delete the binary tree and free memory
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    // Recursively delete left and right subtrees
    deleteTree(root->left);
    deleteTree(root->right);

    // Delete the current node
    delete root;
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Perform post-order traversal
    std::cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;

    // Clean up memory
    deleteTree(root);

    return 0;
}
