#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    vector<int> seq(N);
    while(K--) {
        stack<int> SS;
        int curr = 0;
        for(int i = 0; i < N; i++) 
            scanf("%d", &seq[i]);
        for(int i = 1; i <= N; i++) {
            SS.push(i);
            if(SS.size() > M)  break;
            while(!SS.empty() && SS.top() == seq[curr]) {
                SS.pop();
                curr++;
            }
        }
        printf("%s\n", curr == N? "YES" : "NO");
        // printf("%s\n", SS.empty() ? "YES" : "NO");
    }
    return 0;
}