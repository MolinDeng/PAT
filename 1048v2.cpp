#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<int> v(N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    for(int i = 0; i < N && v[i] <= M/2 + 1;  i++) {
        int tar = M - v[i];
        int left = i + 1, right = N - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(v[mid] < tar) left = mid + 1;
            else right = mid;
        }
        if(v[left] == tar) {
            cout << v[i] << " " << v[left];
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}