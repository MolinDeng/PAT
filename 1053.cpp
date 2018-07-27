#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int N, M;
long long S;
vector<long long> weight;
vector<vector<int> > Edge;
vector<vector<long long> > res;
vector<long long> tmp;
bool cmp(const int a, const int b) {
    return weight[a] > weight[b];
}
void DFS(int node, long long sum) {
    sum += weight[node];
    tmp.push_back(weight[node]);
    if(!Edge[node].empty()) {
        if(sum >= S)  return;
    }
    else {
        if(sum == S) res.push_back(tmp);
        return;
    }
    for(int i = 0; i < Edge[node].size(); i++) {
        DFS(Edge[node][i], sum);
        tmp.pop_back();
    }
}
int main() {
    scanf("%d %d %lld", &N, &M, &S);
    weight.resize(N);
    Edge.resize(N);
    for(int i = 0; i < N; i++) scanf("%lld", &weight[i]);
    while(M--) {
        int root, K;
        scanf("%d %d", &root, &K);
        while(K--) {
            int node;
            scanf("%d", &node);
            Edge[root].push_back(node);
        }
        sort(Edge[root].begin(), Edge[root].end(), cmp);
    }
    DFS(0, 0);
    for(auto v : res) {
        for(int i = 0; i < v.size(); i++) {
            printf("%lld", v[i]);
            if(i != v.size() - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}