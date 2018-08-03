#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int addr;
    int key;
    int nxt;
};
vector<bool> seen(10010, false);
vector<Node> LL(100010);
int main() {
    int start, N;
    scanf("%d %d", &start, &N);
    while(N--) {
        int addr, key, nxt;
        scanf("%d %d %d", &addr, &key, &nxt);
        LL[addr] = {addr, key, nxt};
    }
    int i = start;
    vector<Node> DD;
    while(i != -1) {
        int key = abs(LL[i].key);
        if(!seen[key]) {
            if(i != start) printf("%05d\n%05d %d ", LL[i].addr, LL[i].addr, LL[i].key);
            else printf("%05d %d ", LL[i].addr, LL[i].key);
            seen[key] = true;
        } else {
            DD.push_back(LL[i]);
        }
        i = LL[i].nxt;
    }
    cout << -1 << endl;
    if(!DD.empty()) {
        for(int i = 0; i < DD.size() - 1; i++) 
            printf("%05d %d %05d\n", DD[i].addr, DD[i].key, DD[i+1].addr);
        printf("%05d %d -1", DD.back().addr, DD.back().key);
    }
    
    return 0;
}