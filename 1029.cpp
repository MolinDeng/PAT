#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    long long N, size = 0;
    scanf("%lld", &N);
    size += N;
    queue<int> a, b;
    while(N--) {
        int i;
        scanf("%d", &i);
        a.push(i);
    }
    a.push(INT_MAX);
    scanf("%lld", &N);
    size += N;
    int cnt = 0;
    while(N--) {
        int i;
        scanf("%d", &i);
        i = min(i, INT_MAX);
        b.push(i);
        if(cnt == (size - 1) / 2 ) {
            printf("%d", min(a.front(), b.front()));
            return 0;
        }
        if(a.front() < b.front()) {
            a.pop();
        } else {
            b.pop();
        }
        cnt++;
    }
    b.push(INT_MAX);
    for(; cnt < (size - 1) / 2; cnt++) {
        if(a.front() < b.front())    
            a.pop();
        else                         
            b.pop();
    }
    printf("%d", min(a.front(), b.front()));
    return 0;
}