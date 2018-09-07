#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> tmp, res, vfactor;
int N, K, P, maxsum = -1;
void KP(int num, int depth, int sum) {
    if(depth == K) {
        if(num == 0) {
            if(sum > maxsum) {
                res = tmp;
                maxsum = sum;
            }
        }
        return;
    }
    for(int i = tmp.empty() ? floor(pow(num, 1.0/P)) : tmp.back(); vfactor[i] >= 1; i--) {
        tmp.push_back(i);
        if(num >= vfactor[i]) KP(num - vfactor[i], depth + 1, sum+i);
        tmp.pop_back();
    }
}
int main() {
    scanf("%d %d %d", &N, &K, &P);
    for(int i = 1, tmp = 0; tmp <= N; tmp = pow(i, P), i++) 
        vfactor.push_back(tmp);
    KP(N, 0, 0);
    if(res.empty()) cout << "Impossible";
    else {
        printf("%d = ", N);
        for(int i = 0; i < K; i++) {
            if(i != 0) printf(" + ");
            printf("%d^%d", res[i], P);
        }
    }
    return 0;
}