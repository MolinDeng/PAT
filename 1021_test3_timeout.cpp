#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <functional>

using namespace std;

int N, max_dep = -1;
vector<int> depth;
vector<bool> visited;
map<int, vector<int> > Edge;

void DFS(int t, int dep, int src) {
    depth[t] = max(dep, depth[t]);
    max_dep = max(depth[t], max_dep);
    visited[src] = true;
    for(auto vertex : Edge[src]) 
        if(!visited[vertex]) DFS(t, dep + 1, vertex);
}

int main() {
    scanf("%d", &N);
    depth.resize(N + 1, -1);
    visited.resize(N + 1, false);
    visited[0] = true;
    for(int i = 1; i < N; i++) {
        int s, d;
        scanf("%d %d", &s, &d);
        Edge[s].push_back(d);
        Edge[d].push_back(s);
    }
    int cnt = 1;
    bool error = false;
    for(int i = 1; i < N + 1; i++) {
        DFS(i, 0, i);
        if(binary_search(visited.begin() + 1, visited.end(), false)) {
            for(int j = 2; j < N + 1; j++) {
                if(!visited[j]) {
                    DFS(j, 0, j);
                    cnt++;
                }
            }
            error = true;
            break;
        }
        fill(visited.begin() + 1, visited.end(), false);
    }
    if(error) printf("Error: %d components", cnt);
    else {
        for(int i = 1; i < N + 1; i++)
            if(depth[i] == max_dep) 
                printf("%d\n", i);
    }   
    return 0;
}