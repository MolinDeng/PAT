#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long M, N;
    scanf("%lld %lld", &M, &N);
    vector<int> pre(N);
    for(long long i = 0; i < N; i++) 
        scanf("%d", &pre[i]);
    while(M--) {
        int U, V, i;
        scanf("%d %d", &U, &V);
        bool f1 = find(pre.begin(), pre.end(), U) != pre.end();
        bool f2 = find(pre.begin(), pre.end(), V) != pre.end();
        if(!f1 && !f2) {
            printf("ERROR: %d and %d are not found.\n", U, V);
            continue;
        }
        else if(!f1) {
            printf("ERROR: %d is not found.\n", U);
            continue;
        }
        else if(!f2) {
            printf("ERROR: %d is not found.\n", V);
            continue;
        }
        for(i = 0; i < N; i++) 
            if((U < pre[i] && V > pre[i]) || (U > pre[i] && V < pre[i]) || U == pre[i] || V == pre[i])
                break;
        if(U == pre[i])
            printf("%d is an ancestor of %d.\n", U, V);
        else if(V == pre[i])
            printf("%d is an ancestor of %d.\n", V, U);
        else 
            printf("LCA of %d and %d is %d.\n", U, V, pre[i]);
    }
    return 0;
}