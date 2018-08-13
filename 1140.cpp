#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    char D;
    int N;
    scanf("%c %d", &D, &N); N--;
    string A;
    A.push_back(D);
    A.push_back('\n');
    while(N--) {
        string B;
        char tmp_c = A[0];
        int cnt = 0;
        for(int i = 0; i < A.length(); i++) {
            if(A[i] == tmp_c) cnt++;
            else {
                B.push_back(tmp_c);
                B.push_back(cnt+'0');
                cnt = 1;
                tmp_c = A[i];
            }
        }
        A = B;
        A.push_back('\n');
    }
    cout << A;
    return 0;
}