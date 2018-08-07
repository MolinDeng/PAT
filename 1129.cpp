#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<long long> times;
bool cmp(const long long &a, const long long &b) {
    if(times[a] != times[b]) return times[a] > times[b];
    else return a < b;
}
int main() {
    long long N, K;
    scanf("%lld %lld", &N, &K);
    vector<long long> tops;
    times.resize(N+1,0);
    vector<bool> Counted(N+1, false); 
    long long query;
    for(long long i = 0; i < N; i++) {
        scanf("%lld", &query);
        if(i != 0) {
            printf("%lld:", query);
            sort(tops.begin(), tops.end(), cmp);
            for(int i = 0; i < (tops.size() < K ? tops.size() : K); i++) 
                printf(" %lld", tops[i]);
            printf("\n");
        }
        times[query]++;
        if(find(tops.begin(), tops.end(), query) == tops.end()) {
            if(tops.size() < K + 1) tops.push_back(query);
            else tops[K] = query;
        }
    }
    return 0;
}