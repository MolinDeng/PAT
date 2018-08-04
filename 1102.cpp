#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int key;
    int left;
    int right;
};
vector<Node> Tree;
vector<int> res_in, res_level;
void inorder(int idx) {
    if(Tree[idx].left == -1 && Tree[idx].right == -1) {
        res_in.push_back(Tree[idx].key);
        return;
    }
    if(Tree[idx].left != -1) inorder(Tree[idx].left);
    res_in.push_back(Tree[idx].key);
    if(Tree[idx].right != -1) inorder(Tree[idx].right); 
}
void levelorder(int root) {
    queue<int> Q;
    Q.push(Tree[root].key);
    while(!Q.empty()) {
        int cnt = Q.size();
        for(int i = 0; i < cnt; i++) {
            int out = Q.front();
            res_level.push_back(Tree[out].key);
            if(Tree[out].left != -1) Q.push(Tree[out].left);
            if(Tree[out].right != -1) Q.push(Tree[out].right);
            Q.pop();
        }
    }
}
int main() {
    int N, root;
    scanf("%d", &N);
    Tree.resize(N);
    vector<bool> isroot(N, true);
    for(int i = 0; i < N; i++) {
        char lc[2], rc[2];
        scanf("%s %s", lc, rc);
        Tree[i] = {i, rc[0] == '-'? -1 : rc[0] - '0', lc[0] == '-'? -1 : lc[0] - '0'};
        if(lc[0] != '-') isroot[lc[0] - '0'] = false;
        if(rc[0] != '-') isroot[rc[0] - '0'] = false;
    }
    for(int i = 0; i < N; i++)
        if(isroot[i]) {
            root = i;
            break;
        }
    levelorder(root);
    inorder(root);
    for(int i = 0; i < N; i++) {
        if(i != 0) printf(" ");
        printf("%d", res_level[i]);
    }
    printf("\n");
    for(int i = 0; i < N; i++) {
        if(i != 0) printf(" ");
        printf("%d", res_in[i]);
    }
    printf("\n");
    
    return 0;
}