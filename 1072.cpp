#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <climits>
#include <algorithm>

#define INF INT_MAX

using namespace std;
vector<vector<int> > e(1020, vector<int>(1020, INF));
vector<int> d(1020, INF);
vector<bool> visited(1020, false);
int main() {
    int N, M, K, DS;
    scanf("%d %d %d %d", &N, &M, &K, &DS);
    vector<bool> GS(M + 1, true);
    for(int i = 0; i < K; i++) {
        string s1, s2;
        int a, b, d;
        cin >> s1 >> s2 >> d;
        a = s1[0] == 'G'? N + stoi(s1.substr(1)) : stoi(s1);
        b = s2[0] == 'G'? N + stoi(s2.substr(1)) : stoi(s2);
        e[a][b] = e[b][a] = d;
    }
    int S = N + M, res;
    float min_d = -1, min_avg = INF;
    bool flag = false;
    for(int k = 1; k <= M; k++) {
        fill(d.begin(), d.end(), INF);
        fill(visited.begin(), visited.end(), false);
        int sid = N + k;
        d[sid] = 0;
        for(int i = 1; i <= S; i++) {
            int min_i = -1, min = INF;
            for(int j = 1; j <= S; j++) {
                if(!visited[j] && d[j] < min) {
                    min_i = j;
                    min = d[j];
                }
            }
            if(min_i == -1) break;
            visited[min_i] = true;
            if(min_i <= N && d[min_i] > DS) {
                GS[k] = false;
                break;
            }
            for(int j = 1; j <= S; j++) {
                if(!visited[j] && e[min_i][j] != INF && d[min_i] + e[min_i][j] < d[j]) 
                    d[j] = d[min_i] + e[min_i][j];
            }
        }
        if(GS[k]) {
            flag = true;
            float sum = 0, m_d = INF;
            for(int i = 1; i <= N; i++) {
                sum += d[i];
                m_d = d[i] < m_d ? d[i] : m_d;
            }
            float avg = sum / N;
            if(m_d > min_d) {
                res = k;
                min_d = m_d;
                min_avg = avg;
            } 
            else if(m_d == min_d && avg < min_avg) {
                res = k;
                min_d = m_d;
                min_avg = avg;
            }
        }
    }
    if(!flag) printf("No Solution");
    else printf("G%d\n%.1f %.1f", res, min_d, min_avg);//round(min_avg*10)/10
}