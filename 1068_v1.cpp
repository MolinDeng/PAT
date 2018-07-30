#include <cstdio>
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

bool cmp(int a, int b) {return a > b;}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> DP(M + 1, 0);
    vector<vector<bool> > choice(N + 1, vector<bool>(M + 1, false));
    vector<int> weight(N + 1, 0);
    for(int i = 1; i <= N; i++)
        scanf("%d", &weight[i]);
    sort(weight.begin()+1, weight.end(), cmp);
    for(int i = 1; i <= N; i++) {
        for(int j = M; j >= weight[i]; j--) {
            if(DP[j] <= DP[j - weight[i]] + weight[i]) {
                DP[j] = DP[j - weight[i]] + weight[i];
                choice[i][j] = true;
            }
        }
    }
    if(DP[M] != M) cout << "No Solution";
    else {
        vector<int> res;
        int i = N, C = M;
        while(C > 0) {
            if(choice[i][C]) {
                res.push_back(weight[i]);
                C -= weight[i];
            }
            i--;
        }
        for(int i = 0; i < res.size(); i++) {
            if(i != 0) cout << " ";
            cout << res[i];
        }
    }
    return 0;
}

/*
8 9
5 9 8 7 2 3 4 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 1 1 0 0 0
0 0 0 0 1 0 0 0 0 1
0 0 0 1 0 0 0 1 1 0
0 0 1 0 0 1 1 1 0 1
0 1 0 1 1 1 1 1 1 1

0 0 0 0 0 0 0 0 0 9
0 0 0 0 0 0 0 0 8 9
0 0 0 0 0 0 0 7 8 9
0 0 0 0 0 5 5 7 8 9
0 0 0 0 4 5 5 7 8 9
0 0 0 3 4 5 5 7 8 9
0 0 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9
*/