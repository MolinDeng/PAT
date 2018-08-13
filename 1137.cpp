#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

struct Grade {
    int Gp, Gm, Gf, G;
    Grade(){
        Gp = Gm = Gf = G = -1;
    }
};
map<string, Grade> list;
bool cmp(string a, string b) {
    if(list[a].G != list[b].G) return list[a].G > list[b].G;
    else return a < b;
}
int main() {
    int M, N, P;
    vector<string> res;
    scanf("%d %d %d", &P, &M, &N);
    while(P--) {
        char id[21];
        int grade;
        scanf("%s %d", id, &grade);
        list[id].Gp = grade;
    }
    while(M--) {
        char id[21];
        int grade;
        scanf("%s %d", id, &grade);
        list[id].Gm = grade;
    }
    while(N--) {
        char id[21];
        int grade;
        scanf("%s %d", id, &grade);
        list[id].Gf = grade;
        list[id].G = (list[id].Gm > list[id].Gf ? (int)(0.4 * list[id].Gm + 0.6 * list[id].Gf + 0.5) : list[id].Gf);
    }
    for(auto iter = list.begin(); iter != list.end(); iter++) {
        if(iter->second.Gp >= 200 && iter->second.G >= 60)
            res.push_back(iter->first);
    }
    sort(res.begin(), res.end(), cmp);
    for(auto id : res) 
        printf("%s %d %d %d %d\n", id.c_str(), list[id].Gp, list[id].Gm, list[id].Gf, list[id].G);
    return 0;
}
