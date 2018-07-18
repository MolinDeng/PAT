#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > Map;
vector<bool> visited;

void DFS(int src) {
    visited[src] = true;
    for(auto city : Map[src]) 
        if(!visited[city]) 
            DFS(city);  
}

int main(int argc, char const *argv[])
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    visited.resize(N, false);
    Map.resize(N, vector<int>());

    while(M--) {
        int i, j;
        scanf("%d %d", &i, &j);
        Map[--i].push_back(--j);
        Map[j].push_back(i);
    }
    while(K--) {
        fill(visited.begin(), visited.end(), false);
        int city_lost, sub_cnt = 0;
        scanf("%d", &city_lost);
        visited[--city_lost] = true;
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                DFS(i);
                sub_cnt++;
            }
        } 
        printf("%d\n", sub_cnt - 1);
    }
    return 0;
}
