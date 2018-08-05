#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int left;
    int right;
};
int main()
{
    int N, root = 0;
    scanf("%d", &N);
    vector<Node> Tree(N);
    vector<bool> isroot(N, true);
    for(int i = 0; i < N; i++) {
        char ls[5], rs[5];
        scanf("%s %s", ls, rs);
        int li = ls[0] == '-' ? -1 : stoi(ls);
        int ri = rs[0] == '-' ? -1 : stoi(rs);
        Tree[i] = {li, ri};
        if(li != -1) isroot[li] = false;
        if(ri != -1) isroot[ri] = false;  
    }
    for(int i = 0; i < N; i++) {
        if(isroot[i]) {
            root = i;
            break;
        }
    }
    vector<int> res;
    res.push_back(root);
    int i = 0;
    for( ; res[i] != -1; i++) {
        res.push_back(Tree[res[i]].left);
        res.push_back(Tree[res[i]].right);
    }
    if(i != N) printf("NO %d", root);
    else printf("YES %d", res[N-1]);
    return 0;
}
