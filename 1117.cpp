#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int N, res = 0;
    cin >> N;
    vector<int> M(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &M[i]);
    sort(M.begin(), M.end(), greater<int>());
    while(res < N && M[res] > res + 1) res++;
    cout << res;
    return 0;
}