#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cctype>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};
Node* RR(Node *root) {
    Node *tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    return tmp;
}
Node* LL(Node *root) {
    Node *tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    return tmp;
}
Node* LR(Node *root) {
    root->left = RR(root->left);
    return LL(root);
}
Node* RL(Node *root) {
    root->right = LL(root->right);
    return RR(root);
}
int get_height(Node *root) {
    if(root == NULL) return 0;
    return max(get_height(root->left), get_height(root->right)) + 1;
}
Node* Insert(Node *root, int key) {
    if(root == NULL) {
        root = new Node();
        root->key = key;
        root->left = root->right = NULL;
    }
    else if(key < root->key) {
        root->left = Insert(root->left, key);
        if(get_height(root->left) - get_height(root->right) == 2) 
            root = key < root->left->key ? LL(root) : LR(root);
    }
    else {
        root->right = Insert(root->right, key);
        if(get_height(root->right) - get_height(root->left) == 2)
            root = key > root->right->key ? RR(root) : RL(root);
    }
    return root;
}
int main() {
    int N;
    Node *root = NULL;
    scanf("%d", &N);
    while(N--) {
        int key;
        scanf("%d", &key);
        root = Insert(root, key);
    }
    cout << root->key;
    return 0;
}