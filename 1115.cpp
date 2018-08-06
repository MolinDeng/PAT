#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node(int _key): key(_key) {
        left = right = NULL;
    }
};

Node* Insert(Node *root, int key) {
    if(root == NULL) {
        root = new Node(key);
    }
    else {
        if(key > root->key) root->right = Insert(root->right, key);
        else root->left = Insert(root->left, key);
    }
    return root;
}
int main() {
    int N;
    scanf("%d", &N);
    Node *Tree = NULL;
    while(N--) {
        int key;
        scanf("%d", &key);
        Tree = Insert(Tree, key);
    }
    vector<int> res;
    queue<Node*> Q;
    Q.push(Tree);
    while(!Q.empty()) {
        int cnt = Q.size();
        res.push_back(cnt);
        for(int i = 0; i < cnt; i++) {
            Node *node = Q.front();
            Q.pop();
            if(node->left != NULL) Q.push(node->left);
            if(node->right != NULL) Q.push(node->right);
        }
    }
    printf("%d + %d = %d", res[res.size()-1], res[res.size()-2], res[res.size()-1]+res[res.size()-2]);
    return 0;
}