#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Person {
    int pre;
    int minID;
    int totM;
    double totArea;
    Person() {
        pre = -1;
        minID = 10000;
        totM = totArea = 0;
    }
};
vector<Person> people(10010);
vector<bool> inCount(10010, false);
int rfind(int id) {
    if(people[id].pre < 0) return id;
    return people[id].pre = rfind(people[id].pre);
}

void _union(int a, int b) {
    int r1 = rfind(a);
    int r2 = rfind(b);
    if(r1 == r2) {
        people[r1].minID = min(people[r1].minID, min(a, b));
    }
    else {
        people[r1].pre += people[r2].pre;
        people[r2].pre = r1;
        people[r1].minID = min(min(people[r1].minID, people[r2].minID), min(a, b));
    }
}
bool cmp(int a, int b) {
    int avgArea_a = people[a].totArea / people[a].pre * (-1);
    int avgArea_b = people[b].totArea / people[b].pre * (-1);
    if(avgArea_a != avgArea_b) return avgArea_a > avgArea_b;
    else return a < b;
}
int main() {
    int N;
    vector<int> res, ids;
    scanf("%d", &N);
    while(N--) {
        int id, fid, mid, k, Me;
        double Area;
        vector<int> cids;
        scanf("%d %d %d %d", &id, &fid, &mid, &k);
        while(k--) {
            int cid;
            scanf("%d", &cid);
            cids.push_back(cid);
        }
        scanf("%d %lf", &Me, &Area);
        people[id].minID = id;
        people[id].totM = Me;
        people[id].totArea = Area;
        if(fid != -1) _union(id, fid);
        if(mid != -1) _union(id, mid);
        if(!cids.empty()) for(auto cid : cids) _union(id, cid);
        ids.push_back(id);
    }
    for(auto id : ids) {
        int root = rfind(id);
        if(id != root) {
            people[root].totM += people[id].totM;
            people[root].totArea += people[id].totArea;
        }
        if(!inCount[root]) {
            res.push_back(root);
            inCount[root] = true;
        }
    }
    printf("%lld\n", res.size());
    sort(res.begin(), res.end(), cmp);
    for(auto p : res) 
        printf("%04d %d %.3f %.3f\n", people[p].minID, people[p].pre*(-1), people[p].totM / (double)(people[p].pre*(-1)), people[p].totArea / (double)(people[p].pre*(-1)));
    return 0;
}   