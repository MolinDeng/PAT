#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
#include <cstring>

using namespace std;
vector<int> res;
vector<int> nodes;
void to_level(int index, int left, int right) {
    if(left >= right) return;
    if(right - left == 1) {
        res[index] = nodes[left];
        return;
    }
    int num = right - left, offset, len = 0, tmp = num;
    // while(tmp) {
    //     len++;
    //     tmp >>= 1;
    // }
    len = log(num) / log(2) + 1;
    int low = pow(2, len - 1) - 1;
    int upper = pow(2, len) - 1;
    int bound = (low + upper) / 2;
    if(num <= bound) 
        offset = num - low / 2 - 1;//减一是数组下标要求
    else offset = upper / 2;
    int i = offset + left;
    res[index] = nodes[i];
    to_level(2 * index + 1, left, i);
    to_level(2 * index + 2, i + 1, right);
}
int main() {
    int N, key;
    scanf("%d", &N);
    res.resize(N);
    for( ; N--; nodes.push_back(key))
        scanf("%d", &key);
    sort(nodes.begin(), nodes.end());
    to_level(0, 0, nodes.size());
    for(int i = 0; i < res.size(); i++) {
        printf("%d", res[i]);
        if(i != res.size() - 1) printf(" "); 
    }
    return 0;
}