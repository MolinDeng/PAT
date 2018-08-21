#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <climits>
#define INF INT_MAX 
using namespace std;

int main() {
    vector<bool> visited(500, false);
    vector<vector<int> > e(500, vector<int>(500, INF));
    vector<int> d(500, INF), pathCnt(500, 0), c(500, 0), maxC(500, 0);
    int N, M, C1, C2, L;
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    for(int i = 0; i < N; i++) 
        scanf("%d", &c[i]);
    while(M--) {
        int c1, c2;
        scanf("%d%d%d", &c1, &c2, &L);
        e[c1][c2] = e[c2][c1] = L;
    }
    d[C1] = 0;
    pathCnt[C1] = 1;
    maxC[C1] = c[C1];
    for(int i = 0; i < N; i++) {
        int u = -1, min = INF;
        for(int j = 0; j < N; j++) {
            if(!visited[j] && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if(u == -1) break;
        visited[u] = true;
        for(int v = 0; v < N; v++) {
            if(!visited[v] && e[u][v] != INF) {
                if(d[u] + e[u][v] < d[v]) {
                    d[v] = d[u] + e[u][v];
                    pathCnt[v] = pathCnt[u];
                    maxC[v] = c[v] + maxC[u];
                }
                else if(d[u] + e[u][v] == d[v]) {
                    pathCnt[v] += pathCnt[u];
                    if(maxC[u] + c[v] > maxC[v]) {
                        maxC[v] = maxC[u] + c[v];
                    }
                }
            }
        }
    }
    cout << pathCnt[C2] << " " << maxC[C2];
    return 0;
}