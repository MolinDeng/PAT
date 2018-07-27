#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node {
    long addr;
    long key;
    long next;
    bool operator <(const Node& b) const {
        return key > b.key;
    }
    Node(long a, long k, long n): addr(a), key(k), next(n) {}
    Node() {}
};

bool cmp(const Node& a, const Node& b) {
    return a.key > b.key;
}
bool link(const Node& a, const Node& b) {
    return a.next == b.addr;
}
int main() {
    long N, start;
    scanf("%ld %ld", &N, &start);
    map<long, Node> LL;
    for(long i = 0; i < N; i++) {
        long addr, key, next;
        scanf("%ld %ld %ld", &addr, &key, &next);
        LL.insert(pair<long, Node>(addr, Node(addr, key, next)));
    }
    priority_queue<Node> res; 
    for(long i = start; i != -1; i = LL[i].next) 
        res.push(LL[i]);
    if(!res.empty()) printf("%lld %05ld\n", res.size(), res.top().addr);
    else printf("0 -1\n");
    while(!res.empty()) {
        printf("%05ld %ld ", res.top().addr, res.top().key);
        res.pop();
        if(res.empty()) printf("-1\n");
        else printf("%05ld\n", res.top().addr);
    }
    return 0;
}