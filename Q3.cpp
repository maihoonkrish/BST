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
        if (val < node->data)
            node->left = insertRec(node->left, val);
        else if (val > node->data)
            node->right = insertRec(node->right, val);
        return node;
    }

    void insert(int val) {
        root = insertRec(root, val);
    }

    Node* treeMinimum(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* deleteRec(Node* node, int val) {
        if (!node) return NULL;
        if (val < node->data)
            node->left = deleteRec(node->left, val);
        else if (val > node->data)
            node->right = deleteRec(node->right, val);
        else {
            if (!node->left && !node->right) {
                delete node;
                return NULL;
            } else if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* succ = treeMinimum(node->right);
                node->data = succ->data;
                node->right = deleteRec(node->right, succ->data);
            }
        }
        return node;
    }

    void deleteNode(int val) {
        root = deleteRec(root, val);
    }

    int maxDepth(Node* node) {
        if (!node) return 0;
        return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }

    int minDepth(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        if (!node->left) return 1 + minDepth(node->right);
        if (!node->right) return 1 + minDepth(node->left);
        return 1 + min(minDepth(node->left), minDepth(node->right));
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << tree.maxDepth(tree.root) << endl;
    cout << tree.minDepth(tree.root) << endl;

    tree.deleteNode(20);
    tree.deleteNode(30);
    tree.deleteNode(50);

    cout << tree.maxDepth(tree.root) << endl;
}
