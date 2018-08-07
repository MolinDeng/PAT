#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int main() {
    int K, N;
    scanf("%d", &K);
    while(K--) {
        scanf("%d", &N);
        vector<int> config(N+1);
        vector<vector<bool> > disabled(N+1, vector<bool>(N+1, false)); 
        vector<bool> gap(2*N+1, false);
        bool flag = false;
        for(int i = 1; i <= N; i++) {
            scanf("%d", &config[i]);
            if(!flag) {
                if(disabled[config[i]][i] || gap[config[i] - i + N]) flag = true;
                else {
                    fill(disabled[config[i]].begin(), disabled[config[i]].end(), true);
                    gap[config[i] - i + N] = true;
                }
            }
        }
        printf("%s\n", flag ? "NO" : "YES");
    }
    return 0;
}