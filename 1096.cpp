#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(long long N) {
    for(long long i = 2; i*i <= N; i++) 
        if(N%i == 0) return false;
    return true;
}
int main() {
    long long N;
    vector<long long> res, tmp;
    cin >> N;
    if(is_prime(N)) { 
        printf("1\n%lld", N);
        return 0;
    }
    for(long i = 2; i <= floor(sqrt(N)) + 1; i++) {
        long long M = N;
        for(long j = i; j <= floor(sqrt(N)) + 1; j++) {
            if(M % j == 0) {
                tmp.push_back(j);
                M /= j;
            }
            else {
                break;
            }
        }
        if(res.size() < tmp.size()) 
            res = tmp;
        tmp.clear();
    }
    printf("%lld\n", res.size());
    for(long i = 0; i < res.size(); i++) {
        if(i != 0) printf("*");
        printf("%lld", res[i]);
    }
    return 0;
}