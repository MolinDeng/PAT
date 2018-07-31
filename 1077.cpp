#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<string> lines(N);
    getchar();
    for(int i = 0; i< N; i++) 
        getline(cin, lines[i]);
    string res;
    while(true) {
        bool flag = false;
        for(int i  = 1; i < N; i++) {
            if(lines[i].back() != lines[0].back() || lines[i].empty() || lines[0].empty()) {
                flag = true;
                break;
            }
            lines[i].pop_back();
        }
        if(flag) break;
        res.insert(res.begin(), lines[0].back());
        lines[0].pop_back();
    }
    if(res.empty()) cout << "nai";
    else cout << res;
    return 0;
}