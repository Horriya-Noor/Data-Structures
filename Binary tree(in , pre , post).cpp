#include <iostream>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
    	data = val;
    	right=left = NULL;
	}
};
void inOrderTraversal(TreeNode* root) {
    if (root == NULL){
    	return;
	}
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
void preOrderTraversal(TreeNode* root) {
    if (root == NULL){
    	return;
	}
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
void postOrderTraversal(TreeNode* root) {
    if (root == NULL){
    	return;
	}
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
int main() {
TreeNode* root = new TreeNode(1);
root->left = new TreeNode(2);
root->left->left = new TreeNode(4);
root->left->right = new TreeNode(5);
root->right = new TreeNode(3);
root->right->left = new TreeNode(6);
root->right->right = new TreeNode(7);
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
