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
    vector<vector<int> > dist(N, vector<int>(N));
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++)
            dist[i][j] = INF;
    for(int i = 0; i < M; i++) {
        int s, d, l;
        scanf("%d %d %d", &s, &d, &l);
        dist[s][d] = dist[d][s] = l;
    }

    vector<bool> visited(N, false);
    s_dist.resize(N, INT_MAX);
    s_dist[C1] = 0;
    priority_queue<int, vector<int>, mycmp> pq;
    vector<bool> in_queue(N, false);
    vector<int> path_cnt(N, 1);
    vector<int> team_cnt(teams);
    //vector<vector<int> > path(N, vector<int>());

    pq.push(C1);
    while(!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        visited[curr] = true;
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
