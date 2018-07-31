#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Node {
    int addr;
    int key;
    int nxt;
    Node(int a, int k, int _nxt = -1): addr(a), key(k), nxt(_nxt) {}
};
vector<Node> LL(100010, Node(-1, -1, -1));
int main() {
    int start, N, K;
    cin >> start >> N >> K;
    while(N--) {
        int addr, key, nxt;
        scanf("%d %d %d", &addr, &key, &nxt);
        LL[addr] = Node(addr, key, nxt);
    }
    int i = start, cnt = 1;
    vector<Node> buffer;
    while(i != -1) {
        buffer.push_back(LL[i]);
        if(buffer.size() == cnt * K) {    
            reverse(buffer.begin() + (cnt-1)*K, buffer.begin() + cnt*K);
            cnt++;
        }
        i = LL[i].nxt;
    }
    if(!buffer.empty()) {
        for(int i = 0; i < buffer.size(); i++) {
            printf("%05d %d ", buffer[i].addr, buffer[i].key);
            if(i == buffer.size() - 1) printf("-1");
            else printf("%05d\n", buffer[i+1].addr);
        }
    }
    return 0;
}