#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

int main() {
    string A;
    cin >> A;
    string B(A.rbegin(), A.rend());
    if(A == B) {
        cout << A << " is a palindromic number.";
        return 0;
    }
    int cnt = 10;
    while(cnt--) {
        string C;
        int carry = 0;
        for(int i = A.length() - 1; i >= 0; i--) {
            int sum = A[i] - '0' + B[i] - '0' + carry;
            carry = sum / 10;
            int r = sum % 10;
            C.insert(C.begin(), r + '0');
        }
        if(carry != 0) C.insert(C.begin(), carry + '0');
        printf("%s + %s = %s\n", A.c_str(), B.c_str(), C.c_str());
        A = C;
        B.assign(C.rbegin(), C.rend());
        if(A == B) break;
    }
    if(A == B) cout << A << " is a palindromic number.";
    else cout << "Not found in 10 iterations.";
    return 0;
}