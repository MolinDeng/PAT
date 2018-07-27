#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

map<long long, long long> record;
int main() {
    int M, N;
    long long res, max_seen = -1;
    scanf("%d %d", &M, &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            long long color;
            scanf("%lld", &color);
            record[color]++;
            if(record[color] > max_seen) {
                max_seen = record[color];
                res = color;
            }
        }
    }
    cout << res;
    return 0;
}