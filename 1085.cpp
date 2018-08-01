#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main() {
    long long N, p, max_len = -1;
    scanf("%lld %lld", &N, &p);
    vector<long long> seq(N);
    for(int i = 0; i < N; i++) 
        scanf("%lld", &seq[i]);
    sort(seq.begin(), seq.end());
    for(long long i  = 0; i < N; i++) {
        long long len = 0;
        int left = i, right = N;
        while(left < right) {
            long long mid = (left + right) / 2;
            if(seq[mid] <= seq[i] * p) left = mid + 1;
            else right = mid;
        }
        max_len = max(max_len, left - i);
    }
    cout << max_len;
    return 0;
}