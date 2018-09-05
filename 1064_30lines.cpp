#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> level(2020, -1), v;
void to_level(int idx, int left, int right) {
    if(left >= right) return;
    int cnt = right - left;
    int low, upper = 1;
    while(upper <= cnt) upper *= 2;
    low = upper / 2 -1; upper--;
    int mid = (low + upper) / 2, root;
    if(cnt <= mid) root = left + low / 2 + (cnt - low);
    else  root = left + upper / 2;
    level[idx] = v[root];
    to_level(2*idx + 1, left, root);
    to_level(2*idx + 2, root+1, right);
}
int main() {
    int N; scanf("%d", &N);
    v.resize(N);
    for(int i = 0; i < N; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    to_level(0, 0, N);
    for(int i = 0; i < N; printf("%d", level[i]), i++) 
        if(i != 0) printf(" ");
    return 0;
}