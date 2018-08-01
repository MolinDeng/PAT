#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

typedef pair<long long ,long long> Frac;

long long gcd(long long a, long long b) { //a > b
    if(a % b == 0) return b;
    return gcd(b, a % b);
}
int main() {
    int N;
    scanf("%d", &N);
    vector<Frac> fracs(N);
    for(int i = 0;i < N; i++) 
        scanf("%lld/%lld", &fracs[i].first, &fracs[i].second);
    Frac res = fracs[0];
    for(int i = 1; i < N; i++) {
        long long M = res.second * fracs[i].second;
        long long a = res.first * fracs[i].second;
        long long b = res.second * fracs[i].first;
        res.first = (a + b == 0? 0 : a + b);
        res.second = (res.first == 0 ? 1 : M); 
    }
    long long Q = res.first / res.second;
    res.first %= res.second;
    if(res.first == 0) cout << Q;
    else {
        long long factor = gcd(res.second, res.first);
        res.first /= factor;
        res.second /= factor;
        if(Q == 0) printf("%lld/%lld", res.first, res.second);
        else printf("%lld %lld/%lld", Q, res.first, res.second);
    }
    return 0;
}
