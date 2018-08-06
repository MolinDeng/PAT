#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    vector<vector<int> > e(N+1, vector<int>(N+1, 0));
    while(M--) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a][b] = e[b][a] = 1;
    }
    scanf("%d", &K);
    while(K--) {
        int n, pre_v;
        bool flag = false;
        scanf("%d", &n);
        vector<int> v(n);
        vector<int> seen(N+1, 0);
        for(int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
            seen[v[i]]++;
            if(seen[v[i]] > 2) flag = true;
            if(i != 0) {
                if(e[pre_v][v[i]] == 0) flag = true;
            }
            pre_v = v[i];
        }
        if(!flag && (n != N + 1 || v[n-1] != v[0])) flag = true;
        if(flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}