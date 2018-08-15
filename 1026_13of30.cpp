#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

struct Player {
    long long arr_time;
    long long serve_time = LLONG_MAX;
    int play_time;
    int vip;
};
struct Table {
    int cnt = 0;
    int vip = 0;
    long long end_time = 8 * 3600;
};
bool cmp1(const Player &a, const Player &b) {
    return a.arr_time < b.arr_time;
}
bool cmp2(const Player &a, const Player &b) {
    return a.serve_time < b.serve_time;
}
int main() {
    int N, M, K;
    scanf("%d", &N);
    vector<Player> players;
    for(int i = 0; i < N; i++) {
        int hh, mm, ss, pt, vip;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &pt, &vip);
        if(3600*hh+60*mm+ss >= 21*3600) continue;
        pt = min(pt, 120);
        players.push_back(Player({3600*hh+60*mm+ss, 0, pt*60, vip}));
    }
    scanf("%d %d", &K, &M);
    vector<Table> tabs(K);
    vector<int> vip_ids;
    for(int i = 0; i < M; i++) {
        int id;
        scanf("%d", &id);
        id--;
        tabs[id].vip = 1;
        vip_ids.push_back(id);
    }
    sort(players.begin(), players.end(), cmp1);
    vector<bool> served(players.size(), false);
    for(int i = 0; i < N; ) {
        if(served[i]) {
            i++;
            continue;
        }
        bool flag = false;
        if(players[i].vip == 1) {
            for(auto tid : vip_ids) { 
                if(tabs[tid].end_time <= players[i].arr_time) {
                    tabs[tid].cnt++;
                    players[i].serve_time = players[i].arr_time;
                    tabs[tid].end_time = players[i].serve_time + players[i].play_time;
                    flag = true;
                    served[i] = true;
                    break;
                }
            }
            if(!flag) {
                long long min = 21*3600;
                int idx = -1;
                for(int j = 0; j < K; j++) {
                    if(tabs[j].end_time < min) {
                        idx = j;
                        min = tabs[j].end_time;
                    }
                }
                if(idx == -1) break;
                if(tabs[idx].end_time <= players[i].arr_time) 
                    players[i].serve_time = players[i].arr_time;
                
                else 
                    players[i].serve_time = tabs[idx].end_time;
                tabs[idx].cnt++;
                tabs[idx].end_time = players[i].serve_time + players[i].play_time;
                served[i] = true;
            }
        }
        else {
            long long min = 21*3600;
            int idx = -1;
            for(int j = 0; j < K; j++) {
                if(tabs[j].end_time < min) {
                    idx = j;
                    min = tabs[j].end_time;
                }
            }
            if(idx == -1) break;
            int pid = i;
            if(tabs[idx].vip) {
                for(int j = i; j < N; j++) {
                    if(players[j].vip && players[j].arr_time <= tabs[idx].end_time) {
                        pid = j;
                        break;
                    }
                }
            }
            if(tabs[idx].end_time <= players[pid].arr_time)    
                players[pid].serve_time = players[pid].arr_time;
            else 
                players[pid].serve_time = tabs[idx].end_time;
            tabs[idx].cnt++;
            tabs[idx].end_time = players[pid].serve_time + players[pid].play_time;
            served[pid] = true;
        }
        if(served[i]) i++;
    }
    sort(players.begin(), players.end(), cmp2);
    for(auto p : players) 
        if(p.serve_time < 21*3600) 
            printf("%02lld:%02lld:%02lld %02lld:%02lld:%02lld %d\n", p.arr_time/3600, p.arr_time%3600/60, p.arr_time%3600%60, p.serve_time/3600, p.serve_time%3600/60, p.serve_time%3600%60, (int)((p.serve_time-p.arr_time)/60.0 + 0.5));
    for(int i = 0;i < K; i++) {
        if(i != 0) printf(" ");
        printf("%d", tabs[i].cnt);
    }
    return 0;
}