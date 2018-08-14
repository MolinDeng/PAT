#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;
bool is_pirme(int S) {
    if(S <= 1) return false;
    else if(S == 2 || S == 3) return true;
    else {
        for(int i = 2; i*i <= S; i++)
            if(S % i == 0) return false;
    }
    return true;
}
int main() {
    int N, M, size, x, res = 0, key;
    scanf("%d %d %d", &size, &N, &M);
    while(!is_pirme(size)) size++;
    vector<long> hmap(size, -1);
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        scanf("%d", &x);
        for(int j = 0; j < size; j++) {
            int idx = (x + j*j) % size;
            if(hmap[idx] == -1) {
                hmap[idx] = x;
                break;
            }
            if(j == size - 1) 
                printf("%d cannot be inserted.\n", x);
        }
    }
    for(int m = 0; m < M; m++) {
        scanf("%d", &key);
        int cnt = 1;
        for(int i = 0; i < size; i++) {
            int idx = (key + i*i) % size;
            if(hmap[idx] == key || hmap[idx] == -1) break;
            cnt++;
        }
        cout << cnt << endl;
        res += cnt;
    }
    printf("%.1f", (double)res / M);
    return 0;
}