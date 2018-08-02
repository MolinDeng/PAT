#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;
struct Coord {
    int k, i, j;
    Coord(int _k, int _i, int _j): k(_k), i(_i), j(_j) {}
};
int Z[6] = {0, 0, 1, 0, 0, -1};
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
vector<vector<vector<int> > > mat;
vector<vector<vector<bool> > > visited;
stack<Coord> S;
int M, N, L, T, res = 0; 
bool legal_step(int k, int i, int j) {
    if(k < 0 || k >= L || i < 0 || i >= M || j < 0 || j >= N) return false;
    if(mat[k][i][j] == 0 || visited[k][i][j]) return false;
    return true;
}
int BFS(int k, int i, int j) {
    int cnt = 0;
    S.push(Coord(k, i, j));
    visited[k][i][j] = true;
    while(!S.empty()) {
        Coord out = S.top();
        S.pop();
        cnt++;
        for(int p = 0; p < 6; p++) {
            int kk = out.k + Z[p];
            int ii = out.i + X[p];
            int jj = out.j + Y[p];
            if(legal_step(kk, ii, jj)) {
                visited[kk][ii][jj] = true;
                S.push(Coord(kk, ii, jj));
            }
        }
    }
    return cnt >= T ? cnt : 0;
}
int main() {    
    scanf("%d %d %d %d", &M, &N, &L, &T);
    mat.resize(L, vector<vector<int> >(M, vector<int>(N)));
    visited.resize(L, vector<vector<bool> >(M, vector<bool>(N, false)));
    for(int k = 0; k < L; k++) 
        for(int i = 0; i < M; i++) 
            for(int j = 0; j < N; j++) 
                scanf("%d", &mat[k][i][j]);
    for(int k = 0; k < L; k++) {
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited[k][i][j] && mat[k][i][j] == 1) {
                    res += BFS(k, i, j);
                }
            }
        }
    }
    cout << res;
    return 0;
}