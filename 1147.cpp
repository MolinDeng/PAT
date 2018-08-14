#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
vector<int> level(10000, INT_MIN), post;
int N;
bool check(int idx, bool flag) { //flag true for max heap, false for min heap
    if(level[2*idx+1] == INT_MIN) return true;
    int l = 2*idx+1, r = 2*idx+2;
    if(level[r] == INT_MIN) 
        return (flag ? level[l] <= level[idx] : level[l] >= level[idx]) && check(l, flag);
    else 
        return (flag ? level[l] <= level[idx] && level[r] <= level[idx] : 
                       level[l] >= level[idx] && level[r] >= level[idx]) 
                && check(l, flag) && check(r, flag);
}
void to_post(int idx) {
    if(level[idx] == INT_MIN) return;// idx >= N
    to_post(2*idx+1);
    to_post(2*idx+2);
    post.push_back(level[idx]);
}
int main() {
    int M;
    scanf("%d %d", &M, &N);
    while(M--) {
        post.clear();
        fill(level.begin(), level.end(), INT_MIN);
        for(int i = 0; i < N; i++) scanf("%d", &level[i]);
        bool flag = check(0, level[1] <= level[0]);
        if(!flag) cout << "Not Heap" << endl;
        else if(level[1] <= level[0]) cout << "Max Heap" << endl;
        else cout << "Min Heap" << endl;
        to_post(0);
        for(int i = 0; i < post.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", post[i]);
        }
        printf("\n");
    }
    return 0;
}