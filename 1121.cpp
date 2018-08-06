#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

vector<long> Map(100010, -1);
vector<bool> seen(100010, false);

int main() {
    long long N, M;
    scanf("%lld", &N);    
    while(N--) {
        long a, b;
        scanf("%ld %ld", &a, &b);
        Map[a] = b; Map[b] = a;
    }
    scanf("%lld", &M);
    vector<long> res;
    vector<long> party(M);
    for(long i = 0; i < M; i++) {
        scanf("%ld", &party[i]);
        seen[party[i]] = true;
    }
    for(long i = 0; i < M; i++) {
        if(Map[party[i]] == -1) res.push_back(party[i]);
        else if(!seen[Map[party[i]]]) res.push_back(party[i]);
    }
    sort(res.begin(), res.end());
    printf("%lld\n", res.size());
    for(long i = 0; i < res.size(); i++) {
        if(i != 0) printf(" ");
        printf("%05ld", res[i]);
    }
    return 0;
}