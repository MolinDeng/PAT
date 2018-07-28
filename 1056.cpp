#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> mrank;
vector<int> weight;
vector<int> seq;

struct cmp {
    bool operator () (const int a, const int b) {
        return weight[a] < weight[b];
    }
};


int main() {
    int N, Ng;
    scanf("%d %d", &N, &Ng);
    mrank.resize(N);
    weight.resize(N);
    seq.resize(N);
    priority_queue<int, vector<int>, cmp> group;
    for(int i = 0; i < N; i++) 
        scanf("%d", &weight[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &seq[i]);
    if(seq.size() == 1) {printf("1"); return 0;}
    while(N != 1) {
        int cnt = 0, gcnt = 0;
        int rank = (N / Ng) + ((N % Ng) == 0 ? 0: 1) + 1;
        for(int i = 0; i < N; i++) {
            group.push(seq[i]);
            mrank[seq[i]] = rank;
            cnt++;
            if(cnt == Ng || (i == N-1 && cnt < Ng)) {
                cnt = 0;
                seq.push_back(group.top());
                priority_queue<int, vector<int>, cmp>().swap(group);
            }
        }
        seq.erase(seq.begin(), seq.begin() + N);
        N = seq.size();
    }
    mrank[seq[0]] = 1;
    for(int i = 0; i < mrank.size(); i++) {
        printf("%d", mrank[i]);
        if(i != mrank.size() - 1) printf(" ");
    }
    return 0;
}