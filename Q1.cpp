#include <bits/stdc++.h>;
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    Node* root;
    
    bst() {
        root = NULL;
    }
    
    void insert(int val) {
        root = insertRec(root, val);
    }
    
    Node* insertRec(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else {
            node->right = insertRec(node->right, val);
        }
        return node;
    }
    void inorder() {
        inorderRec(root) ;
    }
    void inorderRec(Node* node) {
        if (node != NULL) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }
    void preorder() {
        preorderRec(root);
    }
    void preorderRec(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }
    void postorder() {
        postorderRec(root);
    }
    void postorderRec(Node* node) {
        if (node != NULL) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";      
        }
    };

};

int main() {
    bst tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.preorder();
    cout << endl;
    tree.inorder();
    cout << endl;
    tree.postorder();
    cout << endl;
}