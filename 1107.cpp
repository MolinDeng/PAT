#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(const int a, const int b) {
    return a > b;
}
vector<int> hobby(1010, -1);
vector<int> C;
int find(int x) {
    if(C[x] < 0) return x;
    return C[x] = find(C[x]);
}
void union_by_size(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);
    if(r1 == r2) return;
    C[r1] += C[r2];
    C[r2] = r1;
}
int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    C.resize(N+1, -1);
    for(int i = 1; i <= N; i++) {
        int cnt;
        scanf("%d:", &cnt);
        while(cnt--) {
            int hid;
            scanf("%d", &hid);
            if(hobby[hid] != -1) {
                union_by_size(i, hobby[hid]);
            }
            hobby[hid] = i;
        }
    }
    vector<int> res;
    for(int i = 1; i <= N; i++) 
        if(C[i] < 0) 
            res.push_back(-C[i]);
    sort(res.begin(), res.end(), cmp);
    printf("%lld\n", res.size());
    for(int i =0 ;i < res.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", res[i]);
    }
    return 0;
}
