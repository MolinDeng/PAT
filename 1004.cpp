#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

#define MAX_N 101

using namespace std;

map<int, vector<int> > tree;
int level_cnt[MAX_N] = {0};
int max_level = -1;

void DFS(int level, int root) {
    max_level = max(level, max_level);
    if(tree[root].empty()) {
        level_cnt[level]++;
        return;
    }
    for(auto son : tree[root]) {
        DFS(level+1, son);
    }
}
int main(int argc, char const *argv[])
{
    int N, M, id, K, sid;
    scanf("%d %d", &N, &M);
    while(M--) {
        scanf("%d %d",&id ,&K);
        while(K--) {
            scanf("%d", &sid);
            tree[id].push_back(sid);
        }
    }
    DFS(0, 1);
    printf("%d", level_cnt[0]);
    for(int i = 1; i <= max_level; i++)   
        printf(" %d", level_cnt[i]);
    
    return 0;
}
