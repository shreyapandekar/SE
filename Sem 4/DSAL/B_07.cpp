/*Construct an expression tree from the given prefix expression eg. +--a*bc/def and 
traverse it using postordertraversal(non recursive) and then delete the entire tree.*/ 

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* newNode(char data) {
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
// Function to construct the expression tree from the prefix expression
Node* constructTree(string prefix) {
    stack<Node*> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];

        if (isalnum(c)) {
            st.push(newNode(c));
        }
        else {
            Node* node = newNode(c);
            node->left = st.top();
            st.pop();
            node->right = st.top();
            st.pop();
            st.push(node);
        }
    }
    return st.top();
}
// Function to perform postorder traversal of the expression tree
void postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data;
    }
}

//Function to delete the entire expression tree
void deleteTree(Node* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

int main() {
    //string prefix;
    //cout<<"Enter the string:-";
    //cin>>prefix;
    string prefix = "+--a*bc/def";
    Node* root = constructTree(prefix);
    cout << "Postorder traversal of the expression tree: ";
    postorder(root);
    //deleteTree(root);
    return 0;
}