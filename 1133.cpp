#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Node {
    long addr;
    long data;
    long nxt;
};
vector<Node> LL(100000);
int main() {
    long N, start, K;
    scanf("%ld %ld %ld", &start, &N, &K);
    while(N--) {
        long addr, data, nxt;
        scanf("%ld %ld %ld", &addr, &data, &nxt);
        LL[addr] = {addr, data, nxt};
    }
    vector<Node> res1;
    vector<Node> res2;
    vector<Node> res3;
    for(long addr = start; addr != -1; addr = LL[addr].nxt) {
        if(LL[addr].data < 0) res1.push_back(LL[addr]);
        else if(LL[addr].data > K) res3.push_back(LL[addr]);
        else res2.push_back(LL[addr]);
    }
    res1.insert(res1.end(), res2.begin(), res2.end());
    res1.insert(res1.end(), res3.begin(), res3.end());
    for(int i = 0; i < res1.size(); i++) {
        if(i != 0) printf(" %05ld\n%05ld %ld", res1[i].addr, res1[i].addr, res1[i].data);
        else printf("%05ld %ld", res1[i].addr, res1[i].data);
    }
    printf(" -1");
    
    return 0;
}