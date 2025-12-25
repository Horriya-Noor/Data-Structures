# include<iostream>
using namespace std;

// Node structure
struct Node {
    char data;
    Node* left;
    Node* right;
    
    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

// Inorder traversal (Left -> Root -> Right)
void inorder(Node* root) {
    if(root) {
        if(root->left) cout << "(";
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
        if(root->right) cout << ")";
    }
}

// Preorder traversal (Root -> Left -> Right)
void preorder(Node* root) {
    if(root) {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left -> Right -> Root)
void postorder(Node* root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

int main() {
    cout << "Enter root operator: ";
    char rootOp;
    cin >> rootOp;
    
    Node* root = new Node(rootOp);
    
    cout << "Enter left child (operand/operator): ";
    char leftVal;
    cin >> leftVal;
    root->left = new Node(leftVal);
    
    cout << "Enter right child (operand/operator): ";
    char rightVal;
    cin >> rightVal;
    root->right = new Node(rightVal);
    
    cout << "\nInfix Expression: ";
    inorder(root);
    
    cout << "\nPrefix Expression: ";
    preorder(root);
    
    cout << "\nPostfix Expression: ";
    postorder(root);
    
    return 0;
}