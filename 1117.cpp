#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int N, res;
    cin >> N;
    vector<int> M(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &M[i]);
    sort(M.begin(), M.end(), greater<int>());
    for(int i = min(M[0], N); i >= 0; i--) {
        if(M[i-1] > i) {
            res = i;
            break;
        }
    }
    cout << res;
    return 0;
}