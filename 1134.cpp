#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    vector<vector<int> > e(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    vector<vector<bool> > Covered(N, vector<bool>(N ,false));
    scanf("%d", &K);
    while(K--) {
        fill(Covered.begin(), Covered.end(), vector<bool>(N ,false));
        int Nv, cnt = 0;
        scanf("%d", &Nv);
        while(Nv--) {
            int v;
            scanf("%d", &v);
            for(auto u : e[v]) {
                if(!Covered[v][u]) {
                    Covered[v][u] = Covered[u][v] = true;
                    cnt++;
                }
            }
        }
        if(cnt == M) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}