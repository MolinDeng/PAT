#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
struct DATA {
    double Me;
    double Area;
};
struct Family {
    int minID = 10000;
    int cnt;
    double Mavg;
    double Aavg;
    bool flag = false;
};
vector<DATA> d(10000, {0, 0});
vector<Family> f(10000);
vector<int> c(10000, -1);

int Find(int x) {
    if(c[x] < 0) return x;
    return c[x] = Find(c[x]);
}

void Union(int a, int b) {
    int r1 = Find(a);
    int r2 = Find(b);
    if(r1 != r2) 
        c[r2] = r1;
}

bool cmp(int a, int b) {
    if(f[a].Aavg != f[b].Aavg) return f[a].Aavg > f[b].Aavg;
    else return f[a].minID < f[b].minID;
}
int main() {
    int N;
    scanf("%d", &N);
    set<int> IDS;
    while(N--) {
        int id, fid, mid, k, cid;
        double me, Area;
        scanf("%d %d %d %d", &id, &fid, &mid, &k);
        IDS.insert(id);
        while(k--) {
            scanf("%d", &cid);
            Union(id, cid);
            IDS.insert(cid);
        }
        scanf("%lf %lf", &me, &Area);
        if(fid != -1) {
            Union(id, fid);
            IDS.insert(fid);
        }
        if(mid != -1) {
            Union(id, mid);
            IDS.insert(mid);
        }
        d[id] = {me, Area};
    }
    vector<int> res;
    for(set<int>::iterator iter = IDS.begin(); iter != IDS.end(); iter++) {
        int root = Find(*iter);
        f[root].cnt++;
        f[root].minID = min(f[root].minID, *iter);
        f[root].Aavg += d[*iter].Area;
        f[root].Mavg += d[*iter].Me;
        if(!f[root].flag) res.push_back(root);
        f[root].flag = true;
    }
    for(auto i : res) {
        f[i].Aavg /= f[i].cnt;
        f[i].Mavg /= f[i].cnt;
    }
    sort(res.begin(), res.end(), cmp);
    printf("%lld\n", res.size());
    for(auto id : res) 
        printf("%04d %d %.3lf %.3lf\n", f[id].minID, f[id].cnt, f[id].Mavg, f[id].Aavg);
    return 0;
}