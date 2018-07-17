#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

typedef pair<int, float> term;// first exp second coe
map<int, float> res;

int main(int argc, char const *argv[])
{
    int K1, K2;
    scanf("%d", &K1);
    vector<term> P1(K1);
    for(int i = 0; i < K1; i++)
        scanf("%d %f", &P1[i].first, &P1[i].second);
    scanf("%d", &K2);
    vector<term> P2(K2);
    for(int i = 0; i < K2; i++)
        scanf("%d %f", &P2[i].first, &P2[i].second);

    for(int i = 0; i < K1; i++)
        for(int j = 0; j < K2; j++) 
            res[P1[i].first + P2[j].first] += P1[i].second * P2[j].second;

    for(auto iter = res.begin(); iter != res.end(); iter++) 
        if(iter->second == 0)
            res.erase(iter);
    
    printf("%d", res.size());
    for(auto iter = res.rbegin(); iter != res.rend(); iter++) 
        printf(" %d %0.1f", iter->first, iter->second);
    return 0;
}
