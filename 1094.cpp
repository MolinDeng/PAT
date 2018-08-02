#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int> > Ftree(N+1);
    while(M--) {
        int root, num;
        scanf("%d %d", &root, &num);
        while(num--) {
            int cid;
            scanf("%d", &cid);
            Ftree[root].push_back(cid);
        }
    }
    queue<int> S;
    S.push(1); 
    int level = 1, resP = 1, resL = 1;
    while(!S.empty()) {
        int cnt = S.size();
        while(cnt--) {
            for(auto cid : Ftree[S.front()]) S.push(cid);
            S.pop();
        }
        level++;
        int P = S.size();
        if(P > resP) {
            resL = level;
            resP = P;
        }
    }
    cout << resP << " " << resL;
    return 0;
}