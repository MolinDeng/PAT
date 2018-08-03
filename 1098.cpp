#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &A[i]);
    bool Insertion = true, flag = false;
    int pre = INT_MIN, pos;
    for(int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
        if(!flag && B[i] < pre) {
            flag = true;
            pos = i;
        }
        else if(flag && B[i] != A[i]) Insertion = false;
        pre = B[i]; 
    }
    if(Insertion) {
        sort(B.begin(), B.begin() + pos + 1);
        printf("Insertion Sort\n");
        for(int i = 0; i < N; i++) {
            if(i != 0) printf(" ");
            printf("%d", B[i]);
        }
    }
    else {
        printf("Heap Sort\n");
        make_heap(A.begin(), A.end());
        int i = 0;
        while(A!=B) {
            pop_heap(A.begin(), A.end() - i);
            i++;
        }
        pop_heap(A.begin(), A.end() - i);
        for(int i = 0; i < N; i++) {
            if(i != 0) printf(" ");
            printf("%d", A[i]);
        }
    }
    return 0;
}