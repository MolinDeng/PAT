#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

vector<int> pre, post, in;
bool flag = true;
void to_inorder(int preLeft, int preRight, int postLeft, int postRight) {
    if(preLeft == preRight) 
        in.push_back(pre[preLeft]);
    else if(pre[preLeft] == post[postRight]) {
        int i = preLeft + 1;
        while(i <= preRight && pre[i] != post[postRight - 1]) i++;
        if(i > preLeft + 1) 
            to_inorder(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
        else 
            flag = false;
        in.push_back(pre[preLeft]);
        to_inorder(i, preRight, postLeft + (i - preLeft -1), postRight - 1);
    }
}
int main() {
    int N;
    scanf("%d", &N);
    pre.resize(N);
    post.resize(N);
    for(int i = 0; i < N; i++) scanf("%d", &pre[i]);
    for(int i = 0; i < N; i++) scanf("%d", &post[i]); 
    to_inorder(0, N-1, 0, N-1);
    printf("%s\n", flag ? "Yes" : "No");
    for(int i = 0; i < in.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", in[i]);
    }
    return 0;
}