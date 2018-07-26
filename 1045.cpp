#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int max_3(int a, int b, int c) {
    return max(max(a, b), c);
}
int main() {
    int N, L, M;
    scanf("%d", &M);
    scanf("%d", &N);
    vector<int> fav(N + 1, 0);
    for(int i = 1; i < N + 1; i++) 
        scanf("%d", &fav[i]);
    scanf("%d", &L);
    vector<int> colors(L + 1, 0);
    vector<vector<int> > DP(N + 1, vector<int>(L + 1, 0));

    for(int i = 1; i < L + 1; i++) 
        scanf("%d", &colors[i]);
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < L + 1; j++) {
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            if(colors[j] == fav[i])
                DP[i][j]++; 
        }
    }
    printf("%d", DP[N][L]);
    return 0;
}