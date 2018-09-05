#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, res = 0, x;
    scanf("%d", &N);
    vector<int> pos(N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &x);
        pos[x] = i;
    }
    while(pos[0] != 0) {
        swap(pos[0], pos[pos[0]]);
        res++;
    }
    for(int i = 0; i < N; i++) {
        if(pos[i] != i) {
            swap(pos[0], pos[i]);
            res++;
            while(pos[0] != 0) {
                swap(pos[0], pos[pos[0]]);
                res++;
            }// 不跳出for循环是因为当前i之前的位置都已经归位，不用再去检查了，接着往后面检查就好了
        }
        else continue;
    }
    cout << res;
    return 0;
}