#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>

#define INF INT_MAX

using namespace std;

// int main() { // test3 timeout
//     long long N, totalD = 0, M, minD;
//     scanf("%lld", &N);
//     vector<long long> dis(N);
//     for(int i  = 0; i < N; i++) {
//         scanf("%lld", &dis[i]);
//         totalD += dis[i];
//     }   
//     scanf("%lld", &M);
//     while(M--) {
//         minD = 0;
//         long long a, b;
//         scanf("%lld %lld", &a, &b);
//         a--; b--;
//         long long big = (a > b ? a : b);
//         long long small = a + b - big;
//         if(big - small <= N / 2)
//             for(int i = small; i != big; i++) minD += dis[i];
//         else 
//             for(int i = big; i != small; i = (i+1) % N) minD += dis[i];
//         minD = min(minD, totalD - minD);
//         printf("%lld\n", minD);
//     }
//     return 0;
// }
int main() {
    long long N, totalD = 0, M, minD, d;
    scanf("%lld", &N);
    //vector<vector<long long> > dis(N,vector<long long>(N, 0));
    vector<long long> dis(N, 0);
    for(long long i  = 0; i < N - 1; i++) {
        scanf("%lld", &d);
        totalD += d;
        long long j = (i + 1) % N;
        // dis[i][j] = dis[j][i] = d;
        // dis[0][j] = dis[0][i] + dis[i][j];
        dis[j] = dis[i] + d;
    }   
    scanf("%lld", &d); totalD += d;

    scanf("%lld", &M);
    while(M--) {
        minD = 0;
        long long a, b;
        scanf("%lld %lld", &a, &b);
        a--; b--;
        minD = abs(dis[a] - dis[b]);
        minD = min(minD, totalD - minD);
        printf("%lld\n", minD);
    }
    return 0;
}