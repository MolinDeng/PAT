#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    long long N, size = 0, cnt = 0;
    int val;
    scanf("%lld", &N);
    size += N;
    queue<int> a, b;
    for(int i = 0; i < N; i++) {
        scanf("%d", &val);
        a.push(val);
    }
    a.push(INT_MAX);
    scanf("%lld", &N);
    size += N;
    while(N--) {
        scanf("%d", &val);
        b.push(val);
        if(cnt == (size - 1) / 2) {
            printf("%d", min(a.front(), b.front()));
            return 0;
        }
        if(b.front() > a.front()) a.pop();
        else b.pop();
        cnt++;
    }
    b.push(INT_MAX);
    for(; cnt < (size - 1) / 2; cnt++) {
        if(a.front() < b.front()) a.pop();
        else b.pop();
    }
    printf("%d", min(a.front(), b.front()));
    return 0;
}