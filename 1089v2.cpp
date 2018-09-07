#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Merge1(vector<int> &A, int len) {
    for(int i = 0; i < A.size(); i += len) 
        sort(A.begin() + i, A.begin() + (i + len > A.size() ? A.size() : i + len));
}
int main() {
    int N;
    scanf("%d", &N);
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    int pre = -1, pos = 0;
    bool flag = false, isIsert = true;
    for(int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
        if(!flag && B[i] < pre) {
            pos = i;
            flag = true;
        }
        if(flag && B[i] != A[i]) 
            isIsert = false;
        pre = B[i];
    }
    if(isIsert) {
        sort(B.begin(), B.begin() + pos + 1);
        cout << "Insertion Sort" << endl;
        for(int i = 0; i < N; i++) {
            if(i != 0) printf(" ");
            printf("%d", B[i]);
        }
    }
    else {
        int len = 2;
        while(A != B) {
            Merge1(A, len);
            len *= 2;
        }
        Merge1(A, len);
        cout << "Merge Sort" << endl;
        for(int i = 0; i < N; i++) {
            if(i != 0) printf(" ");
            printf("%d", A[i]);
        }
    }
    return 0;
}