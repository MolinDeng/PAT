#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> birds(10000, -1);
int find(int bid) {
    if(birds[bid] < 0) return bid;
    return birds[bid] = find(birds[bid]);
}
void Union(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);
    if(r1 != r2) {
        birds[r2] = r1;
    }
}
int main() {
    int N, bcnt = -1, tcnt = 0, Q;
    scanf("%d", &N);    
    while(N--) {
        int K, r;
        scanf("%d %d", &K, &r); K--;
        bcnt = max(bcnt, r);
        while(K--) {
            int bid;
            scanf("%d", &bid);
            bcnt = max(bcnt, bid);
            Union(r, bid);
        }
    }
    for(int i = 1; i <= bcnt; i++) {
        if(birds[i] < 0) tcnt++;
    }
    cout << tcnt << " " << bcnt << endl;
    scanf("%d", &Q);
    while(Q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        if(find(a) == find(b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}