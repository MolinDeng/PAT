#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

bool pre[1010][1010] = {false};
int main() {
    int M, N, K;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        pre[b][a] = true;
    }
    scanf("%d", &K);
    vector<bool> disabled(N+1, false);
    vector<int> res;
    for(int k = 0; k < K; k++) {    
        fill(disabled.begin(), disabled.end(), false);
        bool flag = false;
        for(int i = 0; i < N; i++) {
            int u;
            scanf("%d", &u);
            if(flag) continue;
            for(int j = 1; j <= N; j++) {
                if(!disabled[j] && pre[u][j]) {
                    flag = true;
                    break;
                }
            }
            disabled[u] = true;
        }
        if(flag) res.push_back(k);
    }
    for(int i = 0; i < res.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", res[i]);
    }
    return 0;
}