#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

vector<int> pre;
vector<int> in;
vector<int> post;

void convert(int left, int right) {
    if(left >= right) return;
    if(right - left == 1) {
        post.insert(post.begin(), in[left]);
        return;
    } else {
        int root = pre[left], i;
        for(i = left; i < right; i++) {
            if(in[i] == root) break;
        }
        pre.erase(pre.begin()+left);
        pre.insert(pre.begin() + i, root);
        post.insert(post.begin(), root);
        convert(i+1, right);
        convert(left, i);
    }
}
int main() {
    int N;
    scanf("%d", &N);    
    stack<int> S;
    for(int i = 0; i < 2*N; i++) {
        int x;
        char op[10];
        scanf("%s", op);
        if(op[1] == 'u') {
            scanf("%d", &x);
            pre.push_back(x);
            S.push(x);
        }
        else {
            in.push_back(S.top());
            S.pop();
        }
    }
    convert(0, N);
    for(int i = 0; i < N; i++) {
        if(i != 0) printf(" ");
        printf("%d", post[i]);
    }
    return 0;
}