#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int N;
    double P, r;
    scanf("%d %lf %lf", &N, &P, &r);
    vector<vector<int> > chain(N);
    for(int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        while(num--) {
            int idx;
            scanf("%d", &idx);
            chain[i].push_back(idx);
        }
    }
    queue<int> Q;
    Q.push(0);
    bool flag = false;
    double res = 0;
    int p = 0, res_cnt = 0;
    while(!Q.empty()) {
        if(flag) break;
        int cnt = Q.size();
        for(int i = 0; i < cnt; i++) {
            int out = Q.front();
            if(chain[out].empty()) {
                flag = true;
                res_cnt++;
                res = P * pow(1+r/100.0, p);
            }
            for(auto idx : chain[out])  Q.push(idx);
            Q.pop();
        }
        p++;
    }   
    printf("%.4f %d", res, res_cnt);
    return 0;
}