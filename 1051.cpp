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
        bool unfit = false;
        for(int i = 0; i < N; i++) 
            scanf("%d", &seq[i]);
        int max_size = 0, size;
        for(int i = 0; i < N; i++) {
            size = 1;
            bool flag = false;
            int pre = seq[i];
            for(int j = i + 1; j < N; j++) {
                if(seq[j] < seq[i]) {
                    if(seq[j] > pre) {
                        unfit = true;
                        break;
                    }
                    pre = seq[j];   
                }
                if(!flag && seq[j] < seq[j - 1]) 
                    size++; 
                else flag = true;
            }
            
            max_size = max(max_size, size);
            if(max_size > M) {
                unfit = true;
                break;
            }
            if(unfit) break;
        }
        printf("%s\n", unfit ? "NO" : "YES");
    }
    return 0;
}