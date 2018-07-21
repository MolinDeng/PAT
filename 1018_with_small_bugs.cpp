#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define INF INT_MAX
using namespace std;

int main() {
    int Cmax, N, Sp, M;
    scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
    vector<vector<int> > E(N+1, vector<int>(N+1, INF));
    vector<int> V_bikes(N+1);
    for(int i = 1; i < N + 1; i++)
        scanf("%d", &V_bikes[i]);
    while(M--) {
        int s, d, e;
        scanf("%d %d %d",&s, &d, &e);
        E[s][d] = E[d][s] = e;
    }
    vector<int> s_dist(N+1, INF);
    vector<bool> visited(N+1, false);
    vector<int> path(N+1, -1);
    vector<int> send(N+1, 0), credit(N+1, 0);
    s_dist[0] = 0;
    for(int i = 0; i < N+1; i++) {
        int min_i = -1, min_cost = INF;
        for(int j = 0; j < N+1; j++) {
            if(!visited[j] && s_dist[j] < min_cost) {
                min_i = j;
                min_cost = s_dist[j];
            }
        }
        if(min_i == -1) break;
        visited[min_i] = true;
        for(int k = 0; k < N+1; k++) {
            if(!visited[k] && E[min_i][k] != INF) {
                if(s_dist[min_i] + E[min_i][k] < s_dist[k]) {
                    s_dist[k] = s_dist[min_i] + E[min_i][k];
                    path[k] = min_i;
                    int tmp = Cmax / 2 - V_bikes[k];              
                    if(tmp < 0) {
                        credit[k] = credit[min_i] + abs(tmp);
                        send[k] = send[min_i];
                    }
                    else {
                        if(tmp < credit[min_i]) {
                            credit[k] = credit[min_i] - tmp;
                            send[k] = send[min_i];
                        } else {
                            credit[k] = 0;
                            send[k] = send[min_i] + (tmp - credit[min_i]);
                        }
                    }
                }
                else if(s_dist[min_i] + E[min_i][k] == s_dist[k]) {
                    int tmp = Cmax / 2 - V_bikes[k];
                    int tmp_credit = 0;
                    int tmp_send = 0;
                    if(tmp < 0) {
                        tmp_credit  = credit[min_i] + abs(tmp);
                        tmp_send = send[min_i];
                    }
                    else {
                        if(tmp < tmp_credit){
                            tmp_credit = credit[min_i] - tmp;
                            tmp_send = send[min_i];
                        } else {
                            tmp_credit = 0;
                            tmp_send = send[min_i] + (tmp - credit[min_i]);
                        }
                    }
                    if(tmp_send < send[k] || (tmp_send == send[k] && tmp_credit < credit[k])) {
                        path[k] = min_i;
                        credit[k] = tmp_credit;
                        send[k] = tmp_send;
                    }
                }
            }
        }
    }
    vector<int> vpath;
    vpath.push_back(Sp);
    int i = Sp;
    while(path[i] != -1) {
        vpath.push_back(path[i]);
        i = path[i];
    }
    printf("%d ", send[Sp]);
    for(auto iter = vpath.rbegin(); iter != vpath.rend(); iter++) {
        printf("%d", *iter);
        if(iter + 1 == vpath.rend()) printf(" ");
        else printf("->");
    }
    printf("%d", credit[Sp]);
    return 0;
}