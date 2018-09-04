#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int K;
    scanf("%d", &K);
    vector<int> v(K);
    for(int i = 0; i < K; i++)
        scanf("%d", &v[i]);
    int tmp_i = 0, resi = 0, resj = K-1, sum = 0, maxSum = -1;
    for(int i = 0; i < K; i++) {
        sum += v[i];
        if(sum > maxSum) {
            maxSum = sum;
            resi = tmp_i;
            resj = i;
        }
        if(sum < 0) {
            sum = 0;
            tmp_i = i+1;
        }
    }
    cout << (maxSum < 0 ? 0 : maxSum) << " " << v[resi] << " " << v[resj];
    return 0;
}