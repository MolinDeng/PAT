#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int N, K, P, max_sum = -1;
vector<int> res, tmp, fac;
void DFS(int n, int level, int sum) {
    if(level == K) {
        if(n == 0) {
            if(sum > max_sum) {
                res = tmp;
                max_sum = sum;
            }
        }  
        return;
    }
    int i;
    if(!tmp.empty()) i = tmp.back();
    else i = floor(pow(N, 1.0 / P));
    for( ; i > 0; i--) {
        if(n - fac[i] >= 0) {
            tmp.push_back(i);
            DFS(n - fac[i], level + 1, sum + i);
            tmp.pop_back();
        }
    }
}
int main() {
    scanf("%d%d%d", &N, &K, &P);
    fac.resize(N);
    for(int i = 0, t = 0; t <= N; i++, t = pow(i, P)) fac[i] = t;
    DFS(N, 0, 0);
    if(res.empty()) cout << "Impossible";
    else {
        printf("%d =", N);
        for(int i = 0;i < res.size(); i++) {
            if(i != 0) printf(" +");
            printf(" %d^%d", res[i], P);
        } 
    }
    return 0;
}