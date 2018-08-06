#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<bool> seen(1000, false);
int main() {
    int N;
    scanf("%d", &N);
    getchar();
    vector<int> res;
    char c;
    int tmp = 0;
    while((c = getchar()) != '\n') {
        if(c == ' ') {
            if(!seen[tmp]) {
                res.push_back(tmp);
                seen[tmp] = true;
            }
            tmp = 0;
        }
        else {
            tmp += c - '0';
        }
    }
    if(!seen[tmp]) res.push_back(tmp);
    sort(res.begin(), res.end());
    printf("%lld\n", res.size());
    for(int i = 0; i < res.size(); i++) {
        if(i != 0) printf(" ");
        printf("%d", res[i]);
    }
    return 0;
}