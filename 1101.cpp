#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<long long> v(N);
    for(int i = 0; i < N; i++) 
        scanf("%lld", &v[i]);
    vector<long long> u(v.begin(), v.end());
    sort(u.begin(), u.end());
    vector<long long> res;
    long long max = -1;
    for(int i = 0; i < N; i++) {
        if(u[i] == v[i] && v[i] > max) res.push_back(v[i]);
        if(v[i] > max) max = v[i];
    }
    sort(res.begin(), res.end());
    printf("%lld\n", res.size());
    for(int i = 0; i < res.size(); i++) {
        if(i != 0) printf(" ");
        printf("%lld", res[i]);
    }
    cout << endl;
    return 0;
}