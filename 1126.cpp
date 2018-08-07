#include <cstdlib>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int> > e;
vector<int> degree;
vector<bool> visited;
int N, M;
bool DFS(int u, int v) {
    visited[u] = true;
    if(e[u][v] == 1) return true;
    bool flag = false;
    for(int i = 1; i <= N; i++) {
        if(!visited[i] && e[u][i] == 1) 
            flag = DFS(i, v);
        if(flag) break;
    }
    return flag;
}
bool isConnected() {
    if(M < N - 1) return false;
    int u = 1;
    for(int v = 2; v <= N; v++) {
        fill(visited.begin(), visited.end(), false);
        if(!DFS(u, v)) return false;
    }
    return true;
}
int isEulerian() {
    int odd_cnt = 0;
    for(int i = 1; i < degree.size(); i++) {
        if(degree[i] % 2 != 0) odd_cnt++;
    }
    return odd_cnt == 0 ? 1 : (odd_cnt == 2 ? 0 : -1);
}
int main() {
    scanf("%d %d", &N, &M);
    e.resize(N + 1, vector<int>(N + 1, 0));
    visited.resize(N + 1, false);
    degree.resize(N + 1, 0);
    for(int i = 0 ; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a][b] = e[b][a] = 1;
        degree[a]++;
        degree[b]++;
    }
    for(int i = 1; i <= N; i++) {
        if(i != 1) printf(" ");
        printf("%d", degree[i]);
    }
    printf("\n");
    if(!isConnected()) cout << "Non-Eulerian";
    else if(isEulerian() == 1) cout << "Eulerian";
    else if(isEulerian() == 0) cout << "Semi-Eulerian";
    else cout << "Non-Eulerian";
    return 0;
}