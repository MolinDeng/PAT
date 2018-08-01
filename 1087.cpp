#include <cstdio>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#define INF INT_MAX

using namespace std;

vector<vector<int> > E(220, vector<int>(220, INF));
vector<int> D(220, INF);
vector<int> H(220, 0);
vector<vector<int> > path(220);
vector<int> path_cnt(220, 0);
vector<bool> visited(220, false);

// int str2idx(char *str) {
//     return (str[0]-'A')+(str[1]-'A')*26+(str[2]-'A')*26*26;
// }
vector<int> res_path;
vector<int> tmp_path;
float tmpH = 0, tmpAvg = 0, resAvg = 0, resH = 0;
void DFS(int city) {
    tmp_path.push_back(city);
    tmpH += H[city];
    if(city == 0) {
        tmpAvg = 1.0 * tmpH / (tmp_path.size()-1);
        if(tmpH > resH) {
            res_path = tmp_path;
            resH = tmpH;
            resAvg = tmpAvg;
        } else if(tmpH == resH && tmpAvg > resAvg) {
            res_path = tmp_path;
            resAvg = tmpAvg;
        }
    }
    for(auto pre : path[city]) DFS(pre);
    tmp_path.pop_back();
    tmpH -= H[city];
}
int main() { // Dijkstra算法+路径保存+DFS搜索最优路径
    int N, K, end; 
    char str[4];
    scanf("%d %d %s", &N, &K, str);
    vector<string> city_name;
    city_name.push_back(str);
    H[0] = 0;
    for(int i = 1; i <= N-1; i++) {
        int h;
        scanf("%s %d", str, &h);
        city_name.push_back(str);
        H[i] = h;
        if(strcmp(str, "ROM") == 0) end = i;
    }
    while(K--) {
        char a[4], b[4];
        int d;
        scanf("%s %s %d", a, b, &d);
        int ai = find(city_name.begin(), city_name.end(), a) - city_name.begin();
        int bi = find(city_name.begin(), city_name.end(), b) - city_name.begin();
        E[ai][bi] = E[bi][ai] = d;
    }
    D[0] = 0;
    path_cnt[0] = 1;
    for(int i = 0; i < N; i++) {
        int u = -1, min = INF;
        for(int j = 0; j < N; j++) {
            if(!visited[j] && D[j] < min) {
                u = j;
                min = D[j];
            }
        }
        if(u == -1) break;
        visited[u] = true;
        for(int v = 0; v < N; v++) {
            if(!visited[v] && E[u][v] != INF) {
                if(E[u][v] + D[u] < D[v]) {
                    D[v] = E[u][v] + D[u];
                    path[v].clear();
                    path[v].push_back(u);
                    path_cnt[v] = path_cnt[u];
                }
                else if(E[u][v] + D[u] == D[v]) {
                    path[v].push_back(u);
                    path_cnt[v] += path_cnt[u];
                }
            }
        }
    }
    DFS(end);
    cout <<path_cnt[end]<<" "<<D[end] <<" "<<(int)resH<<" "<< (int)resAvg << endl;
    for(auto ri = res_path.rbegin(); ri != res_path.rend(); ri++) {
        if(ri != res_path.rbegin()) printf("->");
        printf("%s", city_name[*ri].c_str());
    }
    return 0;
}