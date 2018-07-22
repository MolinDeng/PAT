// using disjoint set
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <functional>
#include <set>

using namespace std;

int N, max_dep = 0, cnt;
vector<int> depth;
vector<bool> visited;
map<int, vector<int> > Edge;
vector<int> disjoint_set;
set<int> s;
vector<int> temp;

int find(int elem) {
    if(disjoint_set[elem] < 0) return elem;
    else return disjoint_set[elem] = find(disjoint_set[elem]);
}
void union_by_height(int root1, int root2) {
    if(find(root1) == find(root2)) return;
    if(disjoint_set[root1] < disjoint_set[root2]) // root 1 is deeper
        disjoint_set[root2] = root1;
    else if(disjoint_set[root1] == disjoint_set[root2]) {
        disjoint_set[root1]--;
        disjoint_set[root2] = root1;
    }
    cnt--;
}
void DFS(int i, int D) {
    if(D > max_dep) {
        temp.clear();
        temp.push_back(i);
        max_dep = D;
    } else if(D == max_dep) 
        temp.push_back(i);
    visited[i] = true;
    for(auto v : Edge[i])
        if(!visited[v]) DFS(v, D + 1);
}

int main() {
    scanf("%d", &N);
    depth.resize(N + 1, -1);
    visited.resize(N + 1, false);
    disjoint_set.resize(N + 1, -1);
    cnt = N;
    visited[0] = true;
    for(int i = 1; i < N; i++) {
        int s, d;
        scanf("%d %d", &s, &d);
        Edge[s].push_back(d);
        Edge[d].push_back(s);
        union_by_height(s, d);
    }
    bool error = (cnt == 1 ? false: true);
    if(error) printf("Error: %d components", cnt);
    else {
        DFS(1, 1);
        for(auto v : temp) s.insert(v);
        temp.clear();
        max_dep = 0;
        fill(visited.begin() + 1, visited.end(), false);
        DFS(temp[0], 1);
        for(auto v : temp) s.insert(v);
        for(auto v : s) printf("%d\n", v);
    }   
    return 0;
}

