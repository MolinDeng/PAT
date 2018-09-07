#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define INF INT_MAX
using namespace std;

vector<vector<int> > E, path;
vector<int> C, res, tmp;
int rsend = INF, rcredit = INF, Cmax;
void DFS(int Sp) {
    tmp.push_back(Sp);
    if(Sp == 0) {
        int send = 0, credit = 0;
        for(int i = tmp.size() - 2; i >= 0; i--) {
            int delta = Cmax / 2 - C[tmp[i]];
            if(delta < 0) credit += abs(delta);
            else if(credit > delta) 
                credit -= delta;
            else {
                send += (delta-credit);
                credit = 0; 
            }
        }
        if(send < rsend || (send == rsend && credit < rcredit)) {
            res = tmp;
            rsend = send;
            rcredit = credit;
        }
    }
    for(auto u : path[Sp]) DFS(u);
    tmp.pop_back();
    /* // also ac
    for(auto u = path[Sp]) {
        DFS(u);
        tmp.pop_back();
    }
    */
}
int main() {
    int N, Sp, M;
    scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
    E.resize(N+1, vector<int>(N+1, INF));
    C.resize(N+1);
    for(int i = 1; i <= N; i++)
        scanf("%d", &C[i]);
    while(M--) {
        int a, b, t;
        scanf("%d %d %d", &a, &b, &t);
        E[a][b] = E[b][a] = t;
    }
    vector<int> D(N+1, INF), visited(N+1, false);
    path.resize(N+1);
    D[0] = 0; C[0] = Cmax / 2;
    for(int i = 0; i <= N; i++) {
        int u = -1, min = INF;
        for(int j = 0; j <= N; j++) {
            if(!visited[j] && D[j] < min) {
                u = j;
                min = D[j];
            }
        }
        if(u == -1) break;
        visited[u] = true;
        for(int v = 0; v <= N; v++) {
            if(!visited[v] && E[u][v] < INF) {
                if(D[u] + E[u][v] < D[v]) {
                    D[v] = D[u] + E[u][v];
                    path[v].clear();
                    path[v].push_back(u);
                }
                else if(D[u] + E[u][v] == D[v])
                    path[v].push_back(u);
            }
        }
    }
    DFS(Sp);
    printf("%d ", rsend);
    for(int i = res.size() - 1; i >= 0; i--) {
        printf("%d", res[i]);
        printf("%s", i == 0 ? " " : "->");
    }
    printf("%d", rcredit);
    return 0;
}