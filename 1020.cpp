#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

vector<int> post(100), in(100), level(10000, -1);

void _2level(int root, int left, int right, int index) {
    if(left > right) return;
    int i = find(in.begin(), in.end(), post[root]) - in.begin();
    level[index] = post[root];
    _2level(root - 1 - right + i, left, i - 1, 2 * index + 1);
    _2level(root - 1, i + 1, right, 2 * index + 2);
}
int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &post[i]);
    for(int i = 0; i < N; i++) scanf("%d", &in[i]);
    _2level(N-1, 0, N-1, 0);
    for(int i = 0, cnt = 0; i < level.size() && cnt < N; i++) {
        if(level[i] != -1) {
            printf("%d", level[i]);
            cnt++;
            if(cnt != N) printf(" "); 
        }
    }
    return 0;
}