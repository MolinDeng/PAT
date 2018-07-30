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
    int N, M;//N是iterm数，M是背包容量，物品价值和重量相等(成正比)
    scanf("%d %d", &N, &M);
    priority_queue<string> res;
    string selected(N+1, '0');
    vector<int> sizes(N+1);
    for(int i = 1 ; i <= N; i++) 
        scanf("%d",&sizes[i]);
    sort(sizes.begin()+1, sizes.end());
    vector<vector<int> > DP(N + 1, vector<int>(M + 1, 0));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(j < sizes[i]) 
                DP[i][j] = DP[i - 1][j];
            else 
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - sizes[i]] + sizes[i]);
        }
        if(DP[i][M] == M) {
            int C = M;
            for(int k = i; k >= 1 && C > 0; k--) {
                if(DP[k][C] == DP[k-1][C] && C != M) ;//C != M这个约束不具有普适性
                else {
                    selected[k] = '1';
                    C -= sizes[k];
                }
            }
            res.push(selected);
            fill(selected.begin(), selected.end(), '0');
        }
    }
    
    if(res.empty()) printf("No Solution");
    else {
        selected = res.top();
        bool found_first = false;
        for(int i = 1; i <= N; i++) {
            if(selected[i] == '1') {
                if(!found_first) {
                    printf("%d", sizes[i]);
                    found_first = true;
                }
                else printf(" %d", sizes[i]);
            }
        }
    }
    return 0;
}