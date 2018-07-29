#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;
unordered_set<long long> sets[51], tmp;
int main() {
    int M, N, K, a, b;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        long long elem;
        scanf("%d", &M);
        while(M--) {
            scanf("%lld", &elem);
            sets[i].insert(elem);
        }
    }
    scanf("%d", &K);
    while(K--) {
        // tmp.clear();
        // scanf("%d %d", &a, &b);
        // tmp.insert(sets[a].begin(), sets[a].end());
        // tmp.insert(sets[b].begin(), sets[b].end());
        // printf("%.1f%%\n", (float)(sets[a].size() + sets[b].size() - tmp.size()) / tmp.size() * 100);
        scanf("%d %d", &a, &b);
        int nc = 0, nt = sets[b].size();
        for(auto iter  = sets[a].begin(); iter != sets[a].end(); iter++) {
            if(sets[b].find(*iter) != sets[b].end()) 
                nc++;
            else nt++;
        }
        printf("%.1f%%\n", (float)nc / nt * 100);
    }
    return 0;
}