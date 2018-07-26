#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> pre;
vector<int> post;
vector<int> post_m;
bool flag = false;
bool flag_m = false;

void pre2post(int start, int end) {
    if(start >= end) return;
    if(end - start == 1) {
        post.insert(post.begin(), pre[start]);
        return;
    }
    int i, root = pre[start];
    post.insert(post.begin(), root);
    for(i = start + 1; i < end; i++) 
        if(pre[i] >= root) break;
    for(int j = i; j < end; j++) {
        if(pre[j] < root) {
            flag = true;
            return;
        }
    }
    pre2post(i, end);
    pre2post(start + 1, i);
}

void pre2post_m(int start, int end) {
    if(start >= end) return;
    if(end - start == 1) {
        post_m.insert(post_m.begin(), pre[start]);
        return;
    }
    int i, root = pre[start];
    post_m.insert(post_m.begin(), root);
    for(i = start + 1; i < end; i++) 
        if(pre[i] < root) break;
    for(int j = i; j < end; j++) {
        if(pre[j] >= root) {
            flag_m = true;
            return;
        }
    }
    pre2post_m(i, end);
    pre2post_m(start + 1, i);
}

int main(int argc, char const *argv[])
{   
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        int n;
        scanf("%d", &n);
        pre.push_back(n);
    }
    pre2post(0, N);
    if(!flag) {
        printf("YES\n");
        for(int i = 0; i < N; i++) {
            printf("%d", post[i]);
            if(i != N - 1) printf(" ");
        }
        return 0;
    }
    pre2post_m(0, N);
    if(!flag_m) {
        printf("YES\n");
        for(int i = 0; i < N; i++) {
            printf("%d", post_m[i]);
            if(i != N - 1) printf(" ");
        }
        return 0;
    }
    printf("NO");
    return 0;
}
