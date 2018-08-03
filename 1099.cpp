#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    int left, right;
    Node() {
        left = right = -1;
    }
};
vector<Node> Tree;
vector<int> nodekey;
void InsertKey(int root) {
    static int idx = 0;
    if(Tree[root].left == -1 && Tree[root].right == -1) {
        Tree[root].key = nodekey[idx++];
        return;
    }
    if(Tree[root].left != -1) InsertKey(Tree[root].left);
    Tree[root].key = nodekey[idx++];
    if(Tree[root].right != -1) InsertKey(Tree[root].right);
}
int main() {
    int N;
    scanf("%d", &N);
    Tree.resize(N);
    nodekey.resize(N);
    for(int i = 0; i < N; i++) {
        int li, ri;
        scanf("%d %d", &li, &ri);
        Tree[i].left = li == -1 ? -1 : li;
        Tree[i].right = ri == -1 ? -1 : ri;
    }
    for(int i = 0; i < N; i++) 
        scanf("%d", &nodekey[i]);
    sort(nodekey.begin(), nodekey.end());
    InsertKey(0);
    
    queue<int> Q;
    Q.push(0);
    bool flag = false;
    while(!Q.empty()) {
        if(flag) printf(" ");
        else flag = true;
        int idx = Q.front();
        printf("%d", Tree[idx].key);
        if(Tree[idx].left != -1) Q.push(Tree[idx].left);
        if(Tree[idx].right != -1) Q.push(Tree[idx].right);
        Q.pop();
    }
    return 0;
}