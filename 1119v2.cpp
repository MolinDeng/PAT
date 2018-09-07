#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

vector<int> pre, post, in;
bool Unique = false;
void transfer(int preLeft, int preRight, int postLeft, int postRight) {// 默认当作左孩子
    if(postLeft == postRight) {
        in.push_back(post[postLeft]);
        return;
    }
    int root = pre[preLeft], child = pre[preLeft + 1], i;
    for(i = postLeft; i < postRight; i++) if(post[i] == child) break;
    bool flag = false;
    if(postRight - i == 1) 
        Unique = flag = true;
    transfer(preLeft + 1, preLeft + 1 + (i - postLeft), postLeft, i);
    in.push_back(root);
    if(!flag) 
        transfer(preLeft + 1 + (i - postLeft) + 1, preRight, i + 1, postRight - 1); 
}
int main() {
    int N;
    scanf("%d", &N);
    pre.resize(N);
    post.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &pre[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &post[i]);
    transfer(0, N-1, 0, N-1);
    printf("%s\n", !Unique ? "Yes" : "No");
    for(int i = 0; i < N; i++) {
        if(i != 0) printf(" ");
        printf("%d", in[i]);
    }
    printf("\n");
    return 0;
}