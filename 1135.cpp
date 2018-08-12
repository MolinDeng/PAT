#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

bool cmp(const int a, const int b) {
    return abs(a) < abs(b);
}
vector<int> pre, in, level(10000, 0);
void to_level(int left, int right, int root, int idx) {
    if(left >= right) return;
    level[idx] = pre[root];
    int i;
    for(i = left; i < right; i++) 
        if(in[i] == pre[root]) break;
    to_level(left, i, root+1, 2*idx+1);
    to_level(i+1, right, root+i-left+1, 2*idx+2);
}
bool judge1(int idx, bool father_red) {
    if(level[idx] == 0) return true;
    if(father_red && level[idx] < 0) return false;
    return judge1(2*idx+1, level[idx] < 0) && judge1(2*idx+2, level[idx] < 0);
}
int getbcnt(int idx) {
    if(level[idx] == 0) return 0;
    int l = getbcnt(2*idx+1);
    int r = getbcnt(2*idx+2);
    return level[idx] > 0 ? max(l, r) + 1 : max(l, r);
}
bool judge2(int idx) {
    if(level[idx] == 0) return true;
    int l = getbcnt(2*idx+1);
    int r = getbcnt(2*idx+2);
    if(l != r) return false;
    return judge2(2*idx+1) && judge2(2*idx+2);
}
int main() {
    int K, N;
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &N);
        pre.resize(N);
        in.resize(N);
        fill(level.begin(), level.end(), 0);
        for(int i = 0; i < N; i++)
            scanf("%d", &pre[i]);
        in.assign(pre.begin(), pre.end());
        sort(in.begin(), in.end(), cmp);
        if(pre[0] < 0) cout << "No" << endl;
        else {
            to_level(0, N, 0, 0);
            if(!judge1(0, false) || !judge2(0)) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    return 0;
}