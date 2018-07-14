#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

typedef pair<int, float> term;// first exp second coe

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

    vector<term> res;

    while(!P1.empty() && !P2.empty()) {
        if(P1[0].first == P2[0].first) {
            float coe = P1[0].second + P2[0].second;
            if (coe != 0)
                res.push_back(term(P1[0].first, coe));
            P1.erase(P1.begin());
            P2.erase(P2.begin());
        }
        else if(P1[0].first < P2[0].first) {
            res.push_back(term(P2[0].first, P2[0].second));
            P2.erase(P2.begin());
        }
        else if(P1[0].first > P2[0].first) {
            res.push_back(term(P1[0].first, P1[0].second));
            P1.erase(P1.begin());    
        }
    }
    if(!P1.empty()) res.insert(res.end(), P1.begin(), P1.end());
    if(!P2.empty()) res.insert(res.end(), P2.begin(), P2.end());
    printf("%d", res.size());
    for(auto p : res) 
        printf(" %d %0.1f", p.first, p.second);
    return 0;
}
