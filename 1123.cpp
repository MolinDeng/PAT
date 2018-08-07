#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
};
Node* RR(Node *root) {
    Node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}
Node* LL(Node *root) {
    Node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
Node *RL(Node *root) {
    root->right = LL(root->right);
    return RR(root);
}
Node *LR(Node *root) {
    root->left = RR(root->left);
    return LL(root);
}
int get_height(Node *root) {
    if(root == NULL) return 0;
    return max(get_height(root->left), get_height(root->right)) + 1;
}
Node* Insert(Node *root, int key){
    if(root == NULL) {
        root = new Node();
        root->key = key;
        root->left = root->right = NULL;
    }
    else if(key < root->key){
        root->left = Insert(root->left, key);
        if(get_height(root->left) - get_height(root->right) == 2) 
            root =  key < root->left->key ? LL(root) : LR(root);
    }
    else {
        root->right = Insert(root->right, key);
        if(get_height(root->right) - get_height(root->left) == 2)
            root = key < root->right->key ? RL(root) : RR(root);
    }
    return root;
}

int main() {
    int N;
    Node *Tree = NULL;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int key;
        scanf("%d",&key);
        Tree = Insert(Tree, key);
    }
    vector<Node*> Q, res;
    Q.push_back(Tree);
    res.push_back(Tree);
    bool flag = false;
    int i = 0, j = 0;
    for( ; Q[i] != NULL; i++) {
        Q.push_back(Q[i]->left);
        Q.push_back(Q[i]->right);
    }
    while(res.size() != N) {
        Node *front = res[j++];
        if(front->left != NULL) res.push_back(front->left);
        if(front->right != NULL) res.push_back(front->right);
    }
    for(int k = 0; k < res.size(); k++) {
        if(k != 0) printf(" ");
        printf("%d", res[k]->key);
    }
    printf("\n%s", i == N ? "YES" : "NO");
    return 0;
}