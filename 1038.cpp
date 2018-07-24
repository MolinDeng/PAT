#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(const string a, const string b) {
    return a + b < b + a;
}
int main() {
    int N;
    scanf("%d", &N);
    vector<string> segs;
    while(N--) {
        string s;
        cin >> s;
        segs.push_back(s);
    }
    sort(segs.begin(), segs.end(), cmp);
    if(segs.empty()) printf("0");
    else {
        string res;
        for(auto s : segs)
            res = res + s;
        int i;
        for(i = 0; i < res.length(); i++) 
            if(res[i] != '0') 
                break;
        
        if(i == res.length()) cout << "0";
        else printf("%s", res.c_str() + i);
    }
    return 0;
}