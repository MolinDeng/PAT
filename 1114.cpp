#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Person {
    int pre;
    int minID;
    int Me;
    double Area;
    Person() {
        pre = -1;
        minID = 10000;
        Me = Area = 0;
    }
};
vector<Person> people(10010);

int rfind(int id) {
    if(people[id].pre < 0) return id;
    return people[id].pre = rfind(people[id].pre);
}

void Union(int a, int b) {
    int r1 = rfind(a);
    int r2 = rfind(b);
    if(r1 != r2) {
        people[r1].pre += people[r2].pre;
        people[r2].pre = r1;
    }
}
bool cmp(int a, int b) {
    double avg_area_a = (double)people[a].Area / people[a].pre * (-1);
    double avg_area_b = (double)people[b].Area / people[b].pre * (-1);
    if(avg_area_a != avg_area_b) return avg_area_a > avg_area_b;
    else return a < b;
}
int main() {
    int N;
    scanf("%d", &N);
    set<int> ids;
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
        people[id].Me = Me;
        people[id].Area = Area;
        ids.insert(id);
        if(fid != -1) {
            Union(id, fid);
            ids.insert(fid);
        }
        if(mid != -1) {
            Union(id, mid);
            ids.insert(mid);
        }
        for(auto cid : cids) {
            Union(id, cid);
            ids.insert(cid);
        }
    }
    vector<int> res;
    vector<bool> inCounted(10010, false);
    for(auto iter = ids.begin(); iter != ids.end(); iter++) {
        int root = rfind(*iter);
        if(!inCounted[root]) {
            res.push_back(root);
            inCounted[root] = true;
        }
        if(root != *iter) {
            people[root].Me += people[*iter].Me;
            people[root].Area += people[*iter].Area;
        }
        people[root].minID = min(people[root].minID, *iter);
    }
    sort(res.begin(), res.end(), cmp);
    printf("%lld\n", res.size());
    for(auto id : res) 
        printf("%04d %d %.3lf %.3lf\n", people[id].minID, people[id].pre*(-1), (double)people[id].Me/people[id].pre*(-1), (double)people[id].Area/people[id].pre*(-1));
    return 0;
}   
