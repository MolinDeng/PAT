#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

#define INF  INT_MAX

using namespace std;

vector<vector<int> > Dis;
vector<vector<int> > Cos;
vector<bool> visited;
vector<int> minD;

int main(int argc, char const *argv[])
{
    int N, M, S, D;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    Dis.resize(N, vector<int>(N, INF));
    Cos.resize(N, vector<int>(N, INF));
    visited.resize(N, false);
    minD.resize(N, INF);
    vector<int> path(N, -1);
    vector<int> cost(N, INF);
    while(M--) {
        int s, d, dis, cost;
        scanf("%d %d %d %d", &s, &d, &dis, &cost);
        Dis[s][d] = Dis[d][s] = dis;
        Cos[s][d] = Cos[d][s] = cost;
    }
    minD[S] = 0;
    cost[S] = 0;
    for(int i = 0; i < N; i++) {
        int min_i = -1, min_d = INF;
        for(int j = 0; j < N; j++) {
            if(!visited[j] && minD[j] < min_d) {
                min_i = j;
                min_d = minD[j];
            }
        }
        if(min_i == -1) break;
        visited[min_i] = true;
        for(int j = 0; j < N; j++) {
            if(!visited[j] && Dis[min_i][j] != INF ) {
                if(Dis[min_i][j] + minD[min_i] < minD[j]) {
                    minD[j] = Dis[min_i][j] + minD[min_i];
                    path[j] = min_i;
                    cost[j] = cost[min_i] + Cos[min_i][j];
                }
                else if(Dis[min_i][j] + minD[min_i] == minD[j]) {
                    if(cost[min_i] + Cos[min_i][j] < cost[j]) {
                        cost[j] = cost[min_i] + Cos[min_i][j];
                        path[j] = min_i;
                    }
                }
            }
        }
    }
    int i = D;
    vector<int> vpath; vpath.push_back(D);
    while(path[i] != -1) {
        vpath.push_back(path[i]);
        i = path[i];
    }
    for(auto v = vpath.rbegin(); v != vpath.rend(); v++) 
        printf("%d ", *v);
    printf("%d %d", minD[D], cost[D]);
    return 0;
}

