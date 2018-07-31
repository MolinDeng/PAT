#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 20000

using namespace std;

vector<bool> prime_tab(MAX_SIZE, true);
int main() {
    for(int i = 2; i*i < MAX_SIZE; i++) 
        for(int j = 2; j*i < MAX_SIZE; j++)
            prime_tab[j*i] = false;
    prime_tab[0] = prime_tab[1] = false; 
    int M, N, S;
    scanf("%d %d", &M, &N);
    for(S = M; S < MAX_SIZE; S++) 
        if(prime_tab[S]) break;
    vector<int> res;
    vector<bool> inserted(S, false);
    for(int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        int idx = num % S;
        if(!inserted[idx]) {
            res.push_back(idx);
            inserted[idx] = true;
        }
        else {
            bool flag = false;
            for(int i = 1; i < S; i++) {
                idx = (num + i*i) % S;
                if(!inserted[idx]) {
                    inserted[idx] = true;
                    flag = true;
                    break;
                }
            }
            res.push_back(flag ? idx : -1);
        }
    }
    for(int i = 0; i < res.size(); i++) {
        if(i != 0) printf(" ");
        if(res[i] == -1) printf("-");
        else printf("%d", res[i]);
    }
    return 0;
}