#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> pre, in, post;

void to_post(int left, int right, int root) {
    if(left >= right) return;
    post.push_back(pre[root]);
    long long i;
    for(i = left; i < right; i++) 
        if(pre[root] == in[i]) break;
    to_post(i + 1, right, root + i - left + 1);
    to_post(left, i, root + 1);
}
int main() {
    long long N;
    scanf("%lld", &N);
    pre.resize(N);
    in.resize(N);
    for(long long i = 0; i < N; i++) 
        scanf("%lld", &pre[i]);
    for(long long i = 0; i < N; i++) 
        scanf("%lld", &in[i]);
    to_post(0, N, 0);
    cout << post.back();
    return 0;
}