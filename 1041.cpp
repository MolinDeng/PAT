#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> Bqueue;
vector<bool> seen(10001, false);
vector<int> cnt(10001, 0);
int main() {
    int N;
    scanf("%d", &N);
    while(N--) {
        int bet;
        scanf("%d", &bet);
        cnt[bet]++;
        if(cnt[bet] >= 2) 
            seen[bet] = true;
        if(!seen[bet]) 
            Bqueue.push(bet); 
    }
    if(Bqueue.empty()) {
        printf("None");
        return 0;
    }
    while(seen[Bqueue.front()]) {
        Bqueue.pop();
        if(Bqueue.empty()) break;
    }
    if(Bqueue.empty()) printf("None");
    else printf("%d", Bqueue.front());
    return 0;
}