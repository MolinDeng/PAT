#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
/* // timeout
typedef pair<long, long> Index;
vector<long> Dia;
vector<long> values;// store 1-i's total values
bool cmp(const Index& a, const Index& b) {
    return a.first < b.first;
}
int main() {
    long N, M, min_lost = LONG_MAX;
    scanf("%ld %ld", &N, &M);
    vector<Index> res;
    Dia.resize(N + 1);
    values.resize(N + 1, 0);
    for(long i = 1; i < N + 1; i++) {
        long dv;
        scanf("%ld", &dv);
        values[i] = values[i - 1] + dv;
        for(long j = 0; j < i; j++) {
            long v = values[i]- values[j];
            if(v >= M) {
                if(v - M < min_lost) {
                    min_lost = v -M;
                    res.clear();
                    res.push_back(Index(j + 1, i));
                } else if(v - M == min_lost) 
                    res.push_back(Index(j + 1, i));
            }
        }
    }
    sort(res.begin(), res.end(), cmp);
    for(auto r : res) printf("%ld-%ld\n", r.first, r.second);
    return 0;
}
*/

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
        int left = i, right = N;
        while(left < right) {
            int mid = (left + right) / 2;
            if(values[mid] - values[i - 1] >= M)
                right = mid;
            else left = mid + 1;
            cout << "mid " << mid << " left " << left << " right " << right << endl;
        }
        cout << "out" << endl;
        if(values[right] - values[i - 1] >= M) {
            if(values[right] - values[i - 1] - M < min_lost) {
                res.clear();
                res.push_back(Index(i, right));
                min_lost = values[right] - values[i - 1] - M;
            } else if(values[right] - values[i - 1] - M == min_lost){
                res.push_back(Index(i, right));
            }
        }
    }
    //sort(res.begin(), res.end(), cmp);
    for(auto r : res) printf("%ld-%ld\n", r.first, r.second);
    return 0;
}