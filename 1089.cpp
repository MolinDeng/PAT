#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; scanf("%d", &A[i]), i++);
    bool flag = false;
    bool is_insert = true;
    int pre = INT_MIN, pos;
    for(int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
        if(!flag && B[i] < pre) {
            flag = true;
            pos = i;
        }
        if(flag && B[i] != A[i]) is_insert = false;
        pre = B[i];
    }
    if(is_insert) {
        sort(B.begin(), B.begin()+pos+1);
        cout << "Insertion Sort" << endl;
        for(int i = 0; i < N; i++) {
            if(i != 0) printf(" ");
            printf("%d", B[i]);
        }
    }
    else {
        /*也可以模拟排序
        int len = 1;
        while(A != B) {
            len *= 2;
            for(int i = 0; i < N; i+=len) 
                sort(A.begin()+i, A.begin()+(i+len >= N ? N : i+len));
        }
        len*=2;*/
        //判断长度tricky的方法
        int len = 2;
        flag = true;
        for(len = 2; flag; len*=2) {
            for(int i = len; i < N; i += 2*len) {
                if(B[i-1] > B[i]) {
                    flag = false;
                    break;
                }
            }
        }
        for(int i = 0; i < N; i+=len) 
            sort(B.begin()+i, B.begin()+(i+len >= N ? N : i+len));
        cout << "Merge Sort" << endl;
        for(int i = 0; i < N; i++) {
            if(i != 0) printf(" ");
            printf("%d", B[i]);
        }
    }
    return 0;
}