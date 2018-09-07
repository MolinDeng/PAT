#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long N, p;
    scanf("%lld %lld", &N, &p);
    vector<long long> v(N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &v[i]);
    }
    sort(v.begin(), v.end());
    int res = -1;
    for(int i = 0; i < N; i++) {
        int left = i, right = N - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(v[mid] <= v[i] * p) left = mid + 1;
            else right = mid;
        }
        res = max(res, left - i);
    }
    cout << res;
    return 0;
}