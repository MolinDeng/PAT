#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int> > chain;
int cnt = 0;
double maxP = -1, P, r;
void DFS(int i, int level) {
    if(chain[i].empty()) {
        double price = P * pow(1+r/100.0, level);
        if(price > maxP) {
            cnt = 1;
            maxP = price;
        } else if(price == maxP) 
            cnt++;
    }
    else  
        for(auto j : chain[i])
            DFS(j, level + 1);
}
int main() {
    long N, root; 
    scanf("%ld %lf %lf", &N, &P, &r);
    chain.resize(N);
    for(long i = 0; i < N; i++) {
        long idx;
        scanf("%ld", &idx);
        if(idx != -1) 
            chain[idx].push_back(i);
        else root = i;
    }
    DFS(root, 0);
    printf("%.2f %d", maxP, cnt);
    return 0;
}