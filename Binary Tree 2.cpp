#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <limits>

using namespace std;

// --- Node Structure ---
struct Node {
    string data;
    Node *left;
    Node *right;

    Node(const string& val) : data(val), left(nullptr), right(nullptr) {}
};

// --- Helper Functions ---

// Checks if a single character string is an operator
bool isOperator(const string& str) {
    return str.length() == 1 && (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/');
}

// Determines operator precedence for infix to postfix conversion
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Cleans up memory by deleting the tree nodes
void delete_Tree(Node* root) {
    if (root == nullptr) return;
    delete_Tree(root->left);
    delete_Tree(root->right);
    delete root;
}

// --- Conversion: Infix to Postfix (Handles single-character operands) ---
string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> s;

    for (char token : infix) {
        if (isspace(token)) continue;

        // Assumes operands are single alphanumeric characters (letters or digits)
        if (isalnum(token)) {
            postfix += token;
        } 
        else if (token == '(') {
            s.push(token);
        } 
        else if (token == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // Pop '('
        } 
        else if (isOperator(string(1, token))) {
            while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(token)) {
                postfix += s.top();
                s.pop();
            }
            s.push(token);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// --- Tree Construction: Postfix to Expression Tree ---
Node* buildExpressionTree(const string& postfix) {
    stack<Node*> s;

    for (char token : postfix) {
        string str_token(1, token);

        if (!isOperator(str_token)) {
            Node* operand = new Node(str_token);
            s.push(operand);
        } else {
            Node* op = new Node(str_token);
            
            if (s.empty()) return nullptr; 
            op->right = s.top(); s.pop(); 
            
            if (s.empty()) return nullptr; 
            op->left = s.top(); s.pop();
            
            s.push(op);
        }
    }
    return s.empty() ? nullptr : s.top();
}

// --- Traversal Functions ---

// 1. Infix Traversal (Left->Root->Right) - Displays Infix Expression
void inorder(Node* root) {
    if (root == nullptr) return;

    if (isOperator(root->data)) {
        cout << "(";
    }
    
    inorder(root->left);
    cout << root->data;
    inorder(root->right); 

    if (isOperator(root->data)) {
        cout << ")";
    }
}

// 2. Prefix Traversal (Root->Left->Right) - Displays Prefix Expression
void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data; 
    preorder(root->left); 
    preorder(root->right); 
}

// 3. Postfix Traversal (Left->Right->Root) - Displays Postfix Expression
void postorder(Node* root) {
    if (root == nullptr) return;

    postorder(root->left); 
    postorder(root->right); 
    cout << root->data; 
}

// --- Evaluation Function (Only works for numeric operands) ---
double evaluateTree(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    // Leaf node: Attempt to convert to double. If it fails (i.e., it's a letter), return 0.
    if (!isOperator(root->data)) {
        if (isdigit(root->data[0])) { // Simple check to see if it starts with a digit
            try {
                return stod(root->data);
            } catch (...) {
                // Not a valid number string, treat as unknown variable with value 0
                return 0; 
            }
        }
        // If it's an algebraic symbol (a, b, c, etc.), we cannot solve it numerically.
        return 0; 
    }

    double left_val = evaluateTree(root->left);
    double right_val = evaluateTree(root->right);

    char op = root->data[0];

    switch (op) {
        case '+': return left_val + right_val;
        case '-': return left_val - right_val;
        case '*': return left_val * right_val;
        case '/': 
            if (right_val == 0) {
                cerr << "\nError: Division by zero. Result is 0 for this case.\n";
                return 0;
            }
            return left_val / right_val;
        default: return 0;
    }
}

// --- Unified Expression Processing Function ---
void processExpression(const string& infix) {
    string postfix_expression = infixToPostfix(infix);
    Node* root = nullptr;

    if (postfix_expression.empty()) {
        cout << "Invalid or empty expression provided.\n";
        return;
    }
    
    root = buildExpressionTree(postfix_expression);

    if (root == nullptr) {
        cout << "Error: Could not construct the binary tree. Check expression format.\n";
        return;
    }

    cout << "\n--- Traversal Results (Expression Notations) ---\n";

    cout << "1. Infix (Left->Root->Right): ";
    inorder(root);
    cout << "\n";

    cout << "2. Prefix (Root->Left->Right): ";
    preorder(root);
    cout << "\n";

    cout << "3. Postfix (Left->Right->Root): ";
    postorder(root);
    cout << "\n";
    
    // Check if the expression contains any algebraic variables (letters)
    bool is_purely_numeric = true;
    for(char c : postfix_expression) {
        if (isalpha(c)) {
            is_purely_numeric = false;
            break;
        }
    }

    if (is_purely_numeric) {
        double result = evaluateTree(root);
        cout << "\n--- Calculation Result ---\n";
        cout << "The solved answer is: " << result << "\n";
    } else {
        cout << "\n--- Calculation Skipped ---\n";
        cout << "The expression contains algebraic variables (e.g., a, b, c) and cannot be solved numerically.\n";
    }

    delete_Tree(root);
}

// --- Main Function (Simplified to take immediate input) ---
int main() {
    string input;

    cout << "============================================\n";
    cout << " Expression Tree Converter and Solver\n";
    cout << "============================================\n";
    cout << "Enter the Infix expression (e.g., (1+2)*3 or (a+b)*c):\n> ";
    
    // Get the entire line of input
    getline(cin, input);
    
    processExpression(input);

    return 0;
}