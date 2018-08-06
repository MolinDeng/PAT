#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool is_prime(int x) {
    if(x <= 1) return false;
    else if(x == 2 || x == 3) return true;
    for(int i = 2; i*i <= x; i++) 
        if(x % i == 0) return false;
    return true;
}
int main() {
    int N, K;
    scanf("%d", &N);
    vector<int> ranklist(N+1);
    vector<bool> checked(10000, false);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &ranklist[i]);
    } 
    scanf("%d", &K);
    while(K--) {
        int qid;
        scanf("%d", &qid);
        if(find(ranklist.begin(), ranklist.end(), qid) == ranklist.end()) 
            printf("%04d: Are you kidding?\n", qid);
        else if(checked[qid])
            printf("%04d: Checked\n", qid);
        else if(ranklist[1] == qid) 
            printf("%04d: Mystery Award\n", qid);
        else if(is_prime(find(ranklist.begin(), ranklist.end(), qid) - ranklist.begin()))
            printf("%04d: Minion\n", qid);
        else 
            printf("%04d: Chocolate\n", qid);
        checked[qid] = true;
    }
    return 0;
}