#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

struct BST {
    Node* root;
    
    BST() {
        root = NULL;
    }
    
    Node* insertRec(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data) node->left = insertRec(node->left, val);
        else node->right = insertRec(node->right, val);
        return node;
    }
    
    void insert(int val) {
        root = insertRec(root, val);
    }

    Node* searchRec(Node* node, int val) {
        if (!node || node->data == val) return node;
        if (val < node->data) return searchRec(node->left, val);
        return searchRec(node->right, val);
    }

    Node* searchIter(Node* node, int val) {
        while (node) {
            if (node->data == val) return node;
            node = (val < node->data) ? node->left : node->right;
        }
        return NULL;
    }

    Node* treeMinimum(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

Node* treeMaximum(Node* node) {
    while (node && node->right)
        node = node->right;
    return node;
}

    void inorderSuccessor(int val) {
    Node* x = search(root, val);
    if (!x) return;

    if (x->right != NULL) {
        cout << treeMinimum(x->right)->data << endl;
        return;
    }

    Node* y = root;
    Node* succ = NULL;
    while (true) {
        if (x->data < y->data) {
            succ = y;
            y = y->left;
        } else if (x->data > y->data) {
            y = y->right;
        } else break;
    }
    if (succ) cout << succ->data << endl;
}

void inorderPredecessor(int val) {
    Node* x = search(root, val);
    if (!x) return;

    if (x->left != NULL) {
        cout << treeMaximum(x->left)->data << endl;
        return;
    }

    Node* y = root;
    Node* pred = NULL;
    while (true) {
        if (x->data > y->data) {
            pred = y;
            y = y->right;
        } else if (x->data < y->data) {
            y = y->left;
        } else break;
    }
    if (pred) cout << pred->data << endl;
}

};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.inorderSuccessor(50);   
    tree.inorderPredecessor(50); 
}
