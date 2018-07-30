#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {return a > b;}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<int> > DP(N + 1, vector<int>(M + 1, 0));
    vector<int> res;
    vector<int> w(N + 1, 0);
    for(int i = 1; i <= N; i++)
        scanf("%d", &w[i]);
    sort(w.begin()+1, w.end(), cmp);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(j < w[i]) DP[i][j] = DP[i-1][j];
            else DP[i][j] = max(DP[i-1][j], DP[i-1][j-w[i]]+w[i]);
        }
    }
    // for(auto i : DP) {
    //     for(auto j : i) cout << j << " ";
    //     cout << endl;
    // }
    if(DP[N][M] != M) cout << "No Solution";
    else {
        int i = N, C = M;
        // while(C > 0) {
        //     if(DP[i][C] == DP[i-1][C-w[i]]+w[i]) {
        //         res.push_back(w[i]);
        //         C -= w[i];
        //     }
        //     i--;
        // }
        for( ; C > 0; i--) {
            if(DP[i][C] == DP[i-1][C-w[i]]+w[i]) {
                res.push_back(w[i]);
                C -= w[i];
            }
        }
        for(int i = 0; i < res.size(); i++) {
            if(i != 0) cout << " ";
            cout << res[i];
        }
    }
    return 0;
}