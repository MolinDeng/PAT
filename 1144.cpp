#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

int main() {
    long long N;
    scanf("%lld", &N);
    vector<int> v;
    map<int, bool> seen;
    while(N--) {
        int i;
        scanf("%d", &i);
        if(i <= 0) continue;
        if(!seen[i]) {
            v.push_back(i);
            seen[i] = true;
        }
    }
    if(v.empty()) {
        cout << "1";
        return 0;
    }
    sort(v.begin(), v.end());
    int i;
    for(i = 0; i+1 < v.size(); i++) 
        if(v[i+1] - v[i] != 1) break;
    cout << v[i]+1;
    return 0;
}