#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;
bool cmp(pair<float, float> &a, pair<float, float> &b) {
    return a.second > b.second;
}
int main() {
    int N, D;
    scanf("%d %d", &N, &D);
    vector<pair<float, float> > Mooncake(N);
    for(int i = 0; i < N; i++) 
        scanf("%f", &(Mooncake[i].first)); 
    for(int i = 0; i < N; i++) {
        scanf("%f", &(Mooncake[i].second));
        Mooncake[i].second /= Mooncake[i].first;
    }
    sort(Mooncake.begin(), Mooncake.end(), cmp);
    float profit = 0;
    for(int i = 0; i < N && D > 0; i++) {
        if(Mooncake[i].first < D) {
            D -= Mooncake[i].first;
            profit += Mooncake[i].first * Mooncake[i].second;
        }
        else {
            profit += D * Mooncake[i].second;
            D = 0;
        }
    }
    printf("%.2f", profit);
    return 0;
}