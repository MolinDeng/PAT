#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

struct Player {
    int arr_time;
    int play_time;
    int serve_time;
    int leave_time;
    bool vip;
    int table_no;
    Player(int hh, int mm, int ss, int pt, bool _vip): 
        arr_time(3600*hh+60*mm+ss), play_time(60*pt), vip(_vip) {}
    Player() {}
    bool operator < (const Player &b) const {
        if(leave_time == b.leave_time) return (table_no > b.table_no) || b.vip;
        else return leave_time > b.leave_time;
    }
};

bool arr_time_cmp(Player &a, Player &b) {
    if(a.arr_time == b.arr_time) return a.vip;
    return a.arr_time < b.arr_time;
}
bool serve_time_cmp(Player &a, Player &b) {
    return a.serve_time < b.serve_time;
}

int main() {
    int N, K, M, VIP_num;
    scanf("%d", &N);
    vector<Player> players;
    vector<bool> served(N, false);
    priority_queue<Player> Pqueue;
    while(N--) {
        int hh, mm, ss, pt, vip;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &pt, &vip);
        Player p(hh, mm, ss, pt, (bool)vip);
        players.push_back(p);
    }
    scanf("%d %d", &K, &M);
    priority_queue<int, vector<int>, greater<int> > tablesq;
    priority_queue<int, vector<int>, greater<int> > vip_tablesq;
    vector<bool> tables(K + 1, false);
    vector<int> tables_serve(K + 1, 0);
    while(M--) {
        scanf("%d", &VIP_num);
        tables[VIP_num] = true;
        vip_tablesq.push(VIP_num);
    }
    for(int i = 1; i < K + 1; i++) 
        if(!tables[i]) tablesq.push(i);
    sort(players.begin(), players.end(), arr_time_cmp);
    for(int i = 0; i < players.size() && i < K; i++) {
        if(players[i].vip) {
            if(!vip_tablesq.empty()) {
                players[i].table_no = vip_tablesq.top();
                vip_tablesq.pop();
            } else {
                players[i].table_no = tablesq.top();
                tablesq.pop();
            }
        } else {
            if(!vip_tablesq.empty() && vip_tablesq.top() < tablesq.top()) {
                players[i].table_no = vip_tablesq.top();
                vip_tablesq.pop();
            } else {
                players[i].table_no = tablesq.top();
                tablesq.pop();
            }
        }
        players[i].serve_time = players[i].arr_time;
        players[i].leave_time = players[i].serve_time + players[i].play_time; 
        Pqueue.push(players[i]);
        tables_serve[players[i].table_no]++;
        served[i] = true;
    }
    for(int i = K; i < players.size();) {
        if(served[i]) { i++; continue; }
        Player out = Pqueue.top();
        bool found = false;
        int table_free = out.table_no;    
        if(out.leave_time >= 21*3600) break;
        int id = i;
        if(tables[table_free]) {
            for(int j = i; j < players.size(); j++) {
                if(players[j].vip && !served[j] && players[j].arr_time <= out.leave_time) {
                    id = j; break;
                }
            }
        } else if(players[id].vip) {
            vector<Player> tmp;
            while(!Pqueue.empty()) {
                if(Pqueue.top().vip && Pqueue.top().leave_time <= players[id].arr_time) {
                    table_free = Pqueue.top().table_no;
                    out = Pqueue.top();
                    Pqueue.pop();
                    found = true;
                    break;
                }
                tmp.push_back(Pqueue.top());
                Pqueue.pop();
            }
            for(auto t : tmp) Pqueue.push(t);
            vector<Player>().swap(tmp);
        }
        if(!found) Pqueue.pop();
        if(players[id].arr_time < out.leave_time) 
            players[id].serve_time = out.leave_time;
        else players[id].serve_time = players[id].arr_time;
        players[id].table_no = table_free;
        players[id].leave_time = players[id].serve_time + players[id].play_time;
        served[id] = true;
        Pqueue.push(players[id]);
        tables_serve[table_free]++;
        if(id == i) i++;
    }
    sort(players.begin(), players.end(), serve_time_cmp);
    for(int p = 0; p < players.size(); p++) {
        if(served[p]) {
            printf("%02d:%02d:%02d ", players[p].arr_time/3600, players[p].arr_time%3600/60, players[p].arr_time%3600%60);
            printf("%02d:%02d:%02d ", players[p].serve_time/3600, players[p].serve_time%3600/60, players[p].serve_time%3600%60);
            printf("%d\n", (players[p].serve_time-players[p].arr_time+30)/60);
        }  
    }
    for(int i = 1; i < K + 1; i++) {
        printf("%d", tables_serve[i]);
        if(i != K) printf(" ");
    }
    return 0;
}