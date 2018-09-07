#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<long, long> Index;
vector<long> values;// store 1-i's total values
bool cmp(const Index& a, const Index& b) {
    return a.first < b.first;
}
int main() {
    long N, M, min_lost = LONG_MAX;
    scanf("%ld %ld", &N, &M);
    vector<Index> res;
    values.resize(N + 1, 0);
    for(long i = 1; i < N + 1; i++) {
        scanf("%ld", &values[i]);
        values[i] += values[i - 1];
    }
    for(int i = 1; i < N + 1; i++) {
        int left = i, right = N + 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(values[mid] - values[i - 1] >= M)
                right = mid;
            else left = mid + 1;
        }
        /*
        int left = i, right = N;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(values[mid] - values[i - 1] >= M)
                right = mid - 1;
            else left = mid + 1;
        }
        */
        if(values[left] - values[i - 1] >= M) {
            if(values[left] - values[i - 1] - M < min_lost) {
                res.clear();
                res.push_back(Index(i, left));
                min_lost = values[left] - values[i - 1] - M;
            } else if(values[left] - values[i - 1] - M == min_lost){
                res.push_back(Index(i, left));
            }
        }
    }
    sort(res.begin(), res.end(), cmp);
    for(auto r : res) printf("%ld-%ld\n", r.first, r.second);
    return 0;
}