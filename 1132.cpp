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
        long long ab = stoll(str);
        long long a = stoll(string(str.begin(), str.begin()+str.length()/2));
        long long b = stoll(string(str.begin()+str.length()/2, str.end()));
        if(a*b == 0) cout << "No" << endl;
        else if(ab % (a*b))
            cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}