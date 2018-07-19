#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <climits>

#define INF INT_MAX

using namespace std;

vector<int> s_dist;

struct mycmp {
    bool operator()(int i, int j) {
        return s_dist[i] > s_dist[j];
    }
};

int main(int argc, char const *argv[])
{
    int N, M, C1, C2;
    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    vector<int> teams(N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &teams[i]);
    vector<vector<int> > dist(N, vector<int>(N, INF));
    for(int i = 0; i < M; i++) {
        int s, d, l;
        scanf("%d %d %d", &s, &d, &l);
        dist[s][d] = dist[d][s] = l;
    }

    vector<bool> visited(N, false);
    s_dist.resize(N, INF);
    s_dist[C1] = 0;
    priority_queue<int, vector<int>, mycmp> pq;
    vector<bool> in_queue(N, false);
    vector<int> path_cnt(N);
    vector<int> team_cnt(N);
    //vector<vector<int> > path(N, vector<int>());

    pq.push(C1); in_queue[C1] = true;
    path_cnt[C1] = 1;
    team_cnt[C1] = teams[C1];
    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        visited[curr] = true;
        in_queue[curr] = false;
        for(int i = 0; i < N; i++) {
            if(dist[curr][i] != INF && !visited[i]) {
                if(!in_queue[i]) {
                    pq.push(i);
                    in_queue[i] = true;
                }
                if(s_dist[curr] + dist[curr][i] < s_dist[i]) {
                    s_dist[i] = s_dist[curr] + dist[curr][i];
                    team_cnt[i] = team_cnt[curr] + teams[i];
                    path_cnt[i] = path_cnt[curr];
                    // path[i].clear();
                    // path[i].push_back(curr);
                }
                else if(s_dist[curr] + dist[curr][i] == s_dist[i]) {
                    if(team_cnt[i] < teams[i] + team_cnt[curr])
                        team_cnt[i] = teams[i] + team_cnt[curr];
                    path_cnt[i] += path_cnt[curr];
                    // path[i].push_back(curr);
                }
            }
        }
    }
    printf("%d %d", path_cnt[C2], team_cnt[C2]);
    return 0;
}

// #include <iostream>
// #include <algorithm>
// using namespace std;
// int n, m, c1, c2;
// int e[510][510], weight[510], dis[510], num[510], w[510];
// bool visit[510];
// const int inf = 99999999;
// int main() {
//     scanf("%d%d%d%d", &n, &m, &c1, &c2);
//     for(int i = 0; i < n; i++)
//         scanf("%d", &weight[i]);
//     fill(e[0], e[0] + 510 * 510, inf);
//     fill(dis, dis + 510, inf);
//     int a, b, c;
//     for(int i = 0; i < m; i++) {
//         scanf("%d%d%d", &a, &b, &c);
//         e[a][b] = e[b][a] = c;
//     }
//     dis[c1] = 0;
//     w[c1] = weight[c1];
//     num[c1] = 1;
//     for(int i = 0; i < n; i++) {
//         int u = -1, minn = inf;
//         for(int j = 0; j < n; j++) {
//             if(visit[j] == false && dis[j] < minn) {
//                 u = j;
//                 minn = dis[j];
//             }
//         }
//         if(u == -1) break;
//         visit[u] = true;
//         for(int v = 0; v < n; v++) {
//             if(visit[v] == false && e[u][v] != inf) {
//                 if(dis[u] + e[u][v] < dis[v]) {
//                     dis[v] = dis[u] + e[u][v];
//                     num[v] = num[u];
//                     w[v] = w[u] + weight[v];
//                 } else if(dis[u] + e[u][v] == dis[v]) {
//                     num[v] = num[v] + num[u];
//                     if(w[u] + weight[v] > w[v])
//                         w[v] = w[u] + weight[v];
//                 }
//             }
//         }
//     }
//     printf("%d %d", num[c2], w[c2]);
//     return 0;
// }