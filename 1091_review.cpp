#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct Pos {
    int i, j, k;
};
int J[6] = {0, 0, 1, -1, 0, 0};
int K[6] = {0, 0, 0, 0, 1, -1};
int I[6] = {1, -1, 0, 0, 0, 0};
int M, N, L, T, tot = 0;
queue<Pos> Q;
vector<vector<vector<int> > > P, visited;

bool islegal(Pos &p) {
    return (p.i >= 0 && p.i < L && p.j >= 0 && p.j < M && p.k >= 0 && p.k < N && P[p.i][p.j][p.k] && !visited[p.i][p.j][p.k]);
}

void BFS(int i, int j, int k) {
    Q.push(Pos({i, j, k}));
    visited[i][j][k] = 1;
    int tmp = 1;
    while(!Q.empty()) {
        Pos p = Q.front();
        Q.pop();
        for(int idx = 0; idx < 6; idx++) {
            p.i += I[idx]; p.j += J[idx]; p.k += K[idx];
            if(islegal(p)) {
                tmp++;
                Q.push(p);
                visited[p.i][p.j][p.k] = 1;
            }
            p.i -= I[idx]; p.j -= J[idx]; p.k -= K[idx];
        }
    }
    if(tmp >= T) tot += tmp;
}
int main() {
    scanf("%d%d%d%d", &M, &N, &L, &T);
    P.resize(L, vector<vector<int> >(M, vector<int>(N)));
    visited.resize(L, vector<vector<int> >(M, vector<int>(N, 0)));
    for(int i = 0 ;i < L; i++) 
        for(int j = 0; j < M; j++)
            for(int k = 0; k < N; k++)
                scanf("%d", &P[i][j][k]);
    for(int i = 0 ;i < L; i++) 
        for(int j = 0; j < M; j++)
            for(int k = 0; k < N; k++)
                if(P[i][j][k] && !visited[i][j][k]) BFS(i, j, k);
    cout << tot;
    return 0;
}