#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

int main() {
    string keys, res, line;
    vector<bool> isbroken(256, true);
    int k, cnt = 0;
    scanf("%d", &k);
    getchar();
    getline(cin, line);
    for(int i = 0; i < line.length(); ) { 
        if(line.length() - i < k) {
            isbroken[toascii(line[i])] = false;
            i++;
            continue;
        }
        bool flag = false;
        for(int j = 1; j <= k-1; j++) {
            if(line[i] != line[i+j]) {
                flag = true;
                break;
            }
        }
        if(!flag) i += k;   
        else {
            if(i == line.length() - k) {
                for(int j = 1; j <= k-1; j++) 
                    isbroken[toascii(line[i+j])] = false;
            }
            isbroken[toascii(line[i])] = false;
            i++;
        }
    }
    vector<bool> flag(256, false);
    for(int i = 0; i < line.length(); ) {
        if(isbroken[toascii(line[i])]) {
            res.push_back(line[i]);
            if(!flag[toascii(line[i])]) {
                keys.push_back(line[i]);
                flag[toascii(line[i])] = true;
            }
            i += k;
        }
        else {
            res.push_back(line[i]);
            i++;
        }
    }
    cout << keys << endl << res;
    return 0;
}