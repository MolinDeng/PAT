#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    vector<vector<int> > G(N+1);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(i);
        G[b].push_back(i);
    }
    scanf("%d", &K);
    while(K--) {
        vector<bool> Counted(M, false);
        int n, cnt = 0;
        scanf("%d", &n);
        while(n--) {
            int u;
            scanf("%d", &u);
            for(auto e : G[u]) {
                if(!Counted[e]) {
                    cnt++;
                    Counted[e] = true;
                }
            }
        }
        printf("%s\n", cnt == M ? "Yes" : "No");
    }
    return 0;
}