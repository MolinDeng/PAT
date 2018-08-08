#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#define INF INT_MAX
using namespace std;

struct Node {
    vector<int> line;
    vector<int> to;
};
struct Result {
    int line, S, D;
};
vector<Node> smap(10000);
vector<bool> visited(10000, false);

int main() {
    int N, K;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        int M, pre_s;
        scanf("%d", &M);
        for(int j = 0; j < M; j++) {
            int sid;
            scanf("%d", &sid);
            if(smap[sid].line.empty() || smap[sid].line.back() != i) 
                smap[sid].line.push_back(i);
            if(j != 0) {
                smap[sid].to.push_back(pre_s);
                smap[pre_s].to.push_back(sid);
            }
            pre_s = sid;
        }  
    }
    scanf("%d", &K);
    vector<int> stopcnt(10000, INF);
    vector<int> iscnt(10000, INF);
    vector<int> path(10000, -1);
    while(K--) {
        int S, D;
        scanf("%d %d", &S, &D);
        fill(stopcnt.begin(), stopcnt.end(), INF);
        fill(iscnt.begin(), iscnt.end(), INF);
        fill(path.begin(), path.end(), -1);
        fill(visited.begin(), visited.end(), false);
        stopcnt[S] = iscnt[S] = 0;
        queue<int> Q;
        Q.push(S);
        bool flag = false;
        while(!Q.empty()) {
            int cnt = Q.size();
            for(int i = 0; i < cnt; i++) {
                int from = Q.front();
                Q.pop();
                visited[from] = true;
                for(auto to : smap[from].to) {
                    Q.push(to);
                    if(to == D) flag = true;
                    if(!visited[to]) {
                        if(stopcnt[from] + 1 < stopcnt[to]) {
                            path[to] = from;
                            stopcnt[to] = stopcnt[from] + 1;
                            iscnt[to] = iscnt[from] + (smap[to].to.size() > 2 ? 1 : 0);
                        }
                        else if(stopcnt[from] + 1 == stopcnt[to] && iscnt[from] < iscnt[to]) {
                            path[to] = from;
                            iscnt[to] = iscnt[from] + (smap[to].to.size() > 2 ? 1 : 0);
                        }
                    }
                }
            }
            if(flag) break;
        }
        vector<int> res_is;
        vector<Result> res;
        for(int i = path[D]; i != S; i = path[i]) {
            if(smap[i].line.size() > 1) res_is.insert(res_is.begin(), i);
        }
        res_is.insert(res_is.begin(), S);
        res_is.push_back(D);
        cout << stopcnt[D] << endl;
        for(int i = 0; i < res_is.size() - 1; i++) {
            int ln;
            for(auto linea : smap[res_is[i]].line) {
                bool flag = false;
                for(auto lineb : smap[res_is[i+1]].line) {
                    if(linea == lineb) {
                        ln = linea; break;
                        flag = true;
                    }
                }
                if(flag) break;
            }
            if(res.empty() || res.back().line != ln) res.push_back(Result{ln, res_is[i], res_is[i+1]});
        }
        if(res.size() == 1) {
            printf("Take Line#%d from %04d to %04d.\n", res[0].line, res[0].S, D);
        }
        else {
            for(int i = 0; i < res.size(); i++) {
                if(i == res.size() - 1) 
                    printf("Take Line#%d from %04d to %04d.\n", res[i].line, res[i].S, D);
                else 
                    printf("Take Line#%d from %04d to %04d.\n", res[i].line, res[i].S, res[i+1].S);
            }
        }
    }
    return 0;
}