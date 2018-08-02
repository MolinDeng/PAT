#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <cctype>

using namespace std;

int main() {
    string A, B;
    cin >> A;
    getchar();
    char c;
    while((c = getchar()) != '\n') {
        auto iter = find(A.begin(), A.end(), c);
        if(iter == A.end()) 
            B.push_back(c);
        else A.erase(iter);
    }
    if(B.empty()) cout << "Yes " << A.size();
    else cout << "No " << B.size();
    return 0;
}