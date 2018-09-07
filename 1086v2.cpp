#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 
#include <stack>
using namespace std;

vector<int> in, pre, post;
stack<int> S;
void to_post(int root, int left, int right) {
    if(left >= right) return;
    int i = left;
    for(i = left; i < right; i++) 
        if(pre[root] == in[i]) break;
    to_post(root+1, left, i);
    to_post(root + (i - left + 1), i + 1, right);
    post.push_back(pre[root]);
}
int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < 2*N; i++) {
        string op;
        cin >> op;
        if(op[1] == 'u') {
            int k;
            scanf("%d", &k);
            pre.push_back(k);
            S.push(k);
        }
        else{
            in.push_back(S.top());
            S.pop();
        }
    }
    to_post(0, 0, N);
    for(int i = 0; i < post.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", post[i]);
    }
    return 0;
}