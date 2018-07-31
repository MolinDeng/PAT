#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;
vector<vector<int> > e;
double res = 0, P, r;

void DFS(int level, int src) {
    if(e[src][0] <= 0) 
        res += e[src][0] * (-1) * pow(1+r/100, level) * P;
    else {
        for(auto id : e[src]) {
            DFS(level + 1, id);
        }
    }
}

int main() {
    int N;
    scanf("%d %lf %lf", &N, &P, &r);
    e.resize(N);
    for(int i = 0; i < N; i++) {
        int cnt;
        scanf("%d", &cnt);
        if(cnt == 0) {
            int num;
            scanf("%d", &num);
            e[i].push_back(-1*num);
        }
        else 
            while(cnt--) {
                int id;
                scanf("%d", &id);
                e[i].push_back(id);
            }
    }
    DFS(0, 0);
    printf("%.1f", res);
    return 0;
}