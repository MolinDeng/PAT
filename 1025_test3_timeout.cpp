#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>

using namespace std;

map<string, pair<int, int> > PAT;
map<string, pair<int, int> > Prank;// all rank, local rank
vector<string> tmp;
vector<string> ALL_ID;

bool cmp(string a, string b) {
    if(PAT[a].second == PAT[b].second) return a < b;
    else return PAT[a].second > PAT[b].second;
}

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d", &N);
    for(int i = 1; i < N + 1; i++) {
        scanf("%d", &K);
        tmp.clear();
        while(K--) {
            string ID; int grade;
            cin >> ID >> grade;
            PAT[ID].first = i;
            PAT[ID].second = grade;
            tmp.push_back(ID);
            ALL_ID.push_back(ID);
        }
        sort(tmp.begin(), tmp.end(), cmp);
        int pre_grade = PAT[tmp[0]].second, pre_rank = 1;
        for(int i = 0; i < tmp.size(); i++) {
            if(PAT[tmp[i]].second == pre_grade) 
                Prank[tmp[i]].second = pre_rank;
            else Prank[tmp[i]].second = i + 1;
            pre_rank = Prank[tmp[i]].second;
            pre_grade = PAT[tmp[i]].second;
        }
    }
    sort(ALL_ID.begin(), ALL_ID.end(), cmp);
    int pre_grade = PAT[ALL_ID[0]].second, pre_rank = 1;
    for(int i = 0; i < ALL_ID.size(); i++) {
        if(PAT[ALL_ID[i]].second == pre_grade) 
            Prank[ALL_ID[i]].first = pre_rank;
        else Prank[ALL_ID[i]].first = i + 1;
        pre_rank = Prank[ALL_ID[i]].first;
        pre_grade = PAT[ALL_ID[i]].second;
    }    
    printf("%d\n", ALL_ID.size());
    for(auto id : ALL_ID) 
        cout << id << " " << Prank[id].first << " " << PAT[id].first << " " << Prank[id].second << endl;
    return 0;
}
