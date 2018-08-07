#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int M, N, S;
    scanf("%d %d %d", &M, &N, &S);
    vector<string> name(M + 1);
    map<string, bool> picked;
    for(int i = 1; i < M + 1; i++) {
        cin >> name[i];
        picked[name[i]] = false;
    }
    vector<int> res;
    if(S > M) {
        printf("Keep going...");
        return 0;
    }
    for(int i = S; i <= M;) {
        if(!picked[name[i]]) {
            res.push_back(i);
            picked[name[i]] = true;
            i = i + N;
        }
        else {
            i++;
        }
    }
    if(res.empty()) printf("Keep going...");
    else {
        for(auto i : res) printf("%s\n", name[i].c_str());
    }
    return 0;
}