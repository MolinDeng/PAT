#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pre, level(10000, 0);

void to_level(int left, int right, int idx) {
    if(left >= right) return;
    else if(right - left == 1) {
        level[idx] = pre[left];
    }
    int root = pre[left], i = left+1;
    level[idx] = root;
    for(; i < right; i++) if(abs(pre[i]) > abs(root)) break;
    to_level(left+1, i, 2*idx + 1);
    to_level(i, right, 2*idx + 2);
}
bool judge1(int idx) {
    if(level[idx] == 0) return true;
    int l = 2*idx + 1, r = 2*idx + 2;
    if(level[idx] < 0 && (level[l] < 0 || level[r] < 0)) return false;
    return judge1(l) && judge1(r);
}
int DFS(int idx) {
    if(level[idx] == 0) return 0;
    int lh = 0, rh = 0;
    lh = DFS(2*idx+1);
    rh = DFS(2*idx+2);
    return max(lh, rh) + (level[idx] > 0 ? 1 : 0);
}
bool judge2(int idx) {
    if(level[idx] == 0) return true;
    int lh, rh;
    lh = DFS(2*idx+1);
    rh = DFS(2*idx+2);
    if(lh != rh) return false;
    return judge2(2*idx+1) && judge2(2*idx+2);
}
int main() {
    int K, N;
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &N);
        pre.resize(N);
        fill(level.begin(), level.end(), 0);
        for(int i = 0; i < N; i++)
            scanf("%d", &pre[i]);
        if(pre[0] < 0) cout << "No\n";
        else {
            to_level(0, N, 0);
            if(judge1(0) && judge2(0)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}