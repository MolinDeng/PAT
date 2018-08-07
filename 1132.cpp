#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    while(N--) {
        string str;
        cin >> str;
        if(stoll(str) % (stoll(string(str.begin(), str.begin()+str.length()/2)) * stoll(string(str.begin()+str.length()/2, str.end()))))
            cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}