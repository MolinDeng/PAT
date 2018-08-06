#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    double res = 0;
    vector<double> seg(N);
    for(int i = 0; i < N; i++)
        scanf("%lf", &seg[i]);
    sort(seg.begin(), seg.end());
    for(int i = 0; i< N; i++) {
        if(i == 0) res = seg[0];
        else res = (res + seg[i]) / 2.0;
    }
    printf("%d", (int)res);
    return 0;
}