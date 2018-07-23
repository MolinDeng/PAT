#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

int main() {
    string str;
    cin >> str;
    int N = str.length();
    int n1, n2;
    for(int i = 0; i < N * 2; i += 2) {
        if((N + 2 + i) % 3 == 0) {
            n2 = (N + 2 + i) / 3;
            break;
        }
    }
    n1 = (N + 2 - n2) / 2;
    string s1(str.begin(), str.begin() + n1 - 1);
    string s2(str.begin() + n1 - 1, str.begin() + n1 + n2 - 1);
    string s3(str.begin() + n1 + n2 - 1, str.end());
    reverse(s3.begin(), s3.end());
    for(int i = 0; i < n1; i++) {
        if(i == n1 - 1) {
            printf("%s", s2.c_str());
            break;
        }
        int bk = n2 - 2;
        printf("%c", s1[i]);
        while(bk--) printf(" ");
        printf("%c\n", s3[i]);
    }
    return 0;
}