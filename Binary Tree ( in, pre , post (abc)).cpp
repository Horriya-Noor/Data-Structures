#include <iostream>
using namespace std;
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void preOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
void postOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}
int main() {
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');
    root->right->left = new TreeNode('F');
    root->right->right = new TreeNode('G');
    root->left->left->left = new TreeNode('H');
    root->left->left->right = new TreeNode('I');
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;
    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;
    return 0;
}

