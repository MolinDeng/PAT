#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

vector<vector<int> > e;
vector<bool> visited;
vector<int> c;
set<int> res, tmp;

int Find(int x) {
    if(c[x] < 0) return x;
    return c[x] = Find(c[x]);
}

void Union(int a, int b) {
    int r1 = Find(a);
    int r2 = Find(b);
    if(r1 != r2) c[r2] = r1;
}

int maxD = 0;
void DFS(int u, int d) {
    visited[u] = true;
    if(d > maxD) {
        maxD = d;
        tmp.clear();
        tmp.insert(u);
    }
    else if(d == maxD)
        tmp.insert(u);
    for(auto v : e[u]) 
        if(!visited[v]) 
            DFS(v, d + 1);
} 
int main() {
    int N;
    scanf("%d", &N);
    e.resize(N+1);
    visited.resize(N+1, false);
    c.resize(N+1, -1);
    for(int i = 1; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
        Union(a, b);
    }
    int cnt = 0;
    for(int i = 1; i < N + 1; i++) 
        if(c[i] < 0) cnt++;
    if(cnt > 1) 
        printf("Error: %d components", cnt);
    else {
        DFS(1, 0);
        res.insert(tmp.begin(), tmp.end());
        tmp.clear();
        maxD = 0;
        fill(visited.begin(), visited.end(), false);
        DFS(*res.begin(), 0);
        res.insert(tmp.begin(), tmp.end());
        for(auto r : res) cout << r << endl;
    }
    return 0;
}