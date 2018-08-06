#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<long long> v(N);
    long long sum = 0, sum1 = 0;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &v[i]);
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < N / 2; i++) 
        sum1 += v[i];
    printf("%d %lld", N-N/2-N/2, sum - sum1 - sum1);
    return 0;
}