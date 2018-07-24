#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s1;
    getline(cin, s1);
    string s2(s1.rbegin(), s1.rend());
    int N = s1.length(), maxlen = -1;
    vector<vector<int> > DP(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(/*i == 0 || j == 0 || */s1[i] != s2[j]) DP[i][j] = 0;
            else if(s1[i] == s2[j]) 
                DP[i][j] = DP[(i == 0 ? 0 : i - 1)][(j == 0 ? 0 : j - 1)] + 1;
            if(DP[i][j] > maxlen) 
                maxlen = DP[i][j];
        }
    }
    cout << maxlen;
    return 0;
}