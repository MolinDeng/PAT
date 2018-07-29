#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define RANGE 500000
using namespace std;

long N;
vector<bool> prime_tab(RANGE, true);
vector<long> res;

bool is_prime(long x) {
    if(x < 2) return false;
    if(x == 2 || x == 3) return true;
    for(long i = 2; i*i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int main() {    
    for(long i = 2; i*i < RANGE; i++) 
        for(long j = 2; j*i <= RANGE; j++) 
                prime_tab[j*i] = false;
    fill(prime_tab.begin(), prime_tab.begin() + 2, false);
    scanf("%ld", &N);
    printf("%ld=", N);
    if(N == 1) printf("1");
    for(int i = 2; N > 1; i++) {
        if(!prime_tab[i]) continue;
        int cnt = 0;
        while(N % i == 0) {
            cnt++;
            N /= i;
        }
        if(cnt == 0) continue;
        else if(cnt == 1) printf("%d", i);
        else printf("%d^%d", i, cnt);
        if(N != 1) printf("*");
    }
    return 0;
}