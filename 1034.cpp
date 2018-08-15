#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <map>
#define INF INT_MAX
using namespace std;

vector<vector<int> > e(2010, vector<int>(2010, INF));
vector<int> IDS, T(2010, 0), visited(2010, 0);
map<string, bool> seen;
map<int, string> i2s;
map<string, int> s2i;
int tot_T, maxT, maxID, cnt, idxN = 0;

int alloc_idx(string s) {
    s2i[s] = idxN;
    i2s[idxN] = s;
    return idxN++;
}
void DFS(int u) {
    if(visited[u]) return;
    visited[u] = true;
    cnt++;
    if(T[u] > maxT) {
        maxID = u; 
        maxT = T[u];
    }
    for(auto v : IDS) {
        if(e[u][v] < INF) {
            tot_T += e[u][v];
            DFS(v);
        }
    }
}
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    while(N--) {
        char a[5], b[5];
        int t, ai, bi;
        scanf("%s%s%d", a, b, &t);
        if(!seen[a]) {
            ai = alloc_idx(a);
            IDS.push_back(ai);
            seen[a] = true;
        }
        else ai = s2i[a];
        if(!seen[b]) {
            bi = alloc_idx(b);
            IDS.push_back(bi);
            seen[b] = true;
        }
        else bi = s2i[b];
        e[ai][bi] = t;
        T[ai] += t;
        T[bi] += t;

    }
    vector<pair<string, int> > res;
    for(auto u : IDS) {
        tot_T = 0; maxT = -1; maxID = -1; cnt = 0;
        if(!visited[u]) {
            DFS(u);
            if(tot_T > K && cnt > 2) 
                res.push_back(make_pair(i2s[maxID], cnt));
        }
    }
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for(auto id : res) 
        printf("%s %d\n", id.first.c_str(), id.second);
    return 0;
}