#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> level(200, 0);
vector<vector<int> > tree(101);
int max_d = -1;
void DFS(int d, int fid) {
    max_d = max(max_d, d);
    if(tree[fid].empty()) 
        level[d]++;  
    for(auto cid : tree[fid]) 
        DFS(d + 1, cid);
}
int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    while(M--) {
        int fid, k, cid;
        scanf("%d %d", &fid, &k);
        while(k--) {
            scanf("%d", &cid);
            tree[fid].push_back(cid);
        }
    }
    DFS(0, 1);
    for(int i = 0 ; i <= max_d; i++) {
        if(i != 0) printf(" ");
        printf("%d", level[i]);
    }
    return 0;
}