#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> post, in, level(100000, -1);

void to_level_zz(int left, int right, int root, int index) {
    if(left >= right) return;
    if(right - left == 1) {
        level[index] = post[root];
        return;
    }
    level[index] = post[root];
    int i = 0;
    for( ; i < right; i++) {
        if(in[i] == post[root]) break;
    }
    to_level_zz(left, i, root - (right - i), 2*index+1);
    to_level_zz(i+1, right, root-1, 2*index+2);
}
int main() {
    int N;
    scanf("%d", &N);    
    post.resize(N);
    in.resize(N);
    for(int i = 0 ; i < N; i++) 
        scanf("%d", &in[i]);
    for(int i = 0 ; i < N; i++) 
        scanf("%d", &post[i]);
    to_level_zz(0, N, N-1, 0);
    bool direction = false;
    int cnt = 0, low = 0, high = 1, k = 1;
    while(cnt != N) {
        if(!direction) {
            for(int j = high - 1; j >= low; j--) {
                if(level[j] != -1) {
                    if(j != 0) printf(" ");
                    cnt++;
                    printf("%d", level[j]);
                }
            }
            direction = !direction;
            low = high;
            high += pow(2, k++);
        }
        else {
            for(int j = low; j < high; j++) {
                if(level[j] != -1) {
                    if(j != 0) printf(" ");
                    cnt++;
                    printf("%d", level[j]);
                }
            }
            direction = !direction;
            low = high;
            high += pow(2, k++);
        }
    }
    return 0;
}