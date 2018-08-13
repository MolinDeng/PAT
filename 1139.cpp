#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Person {
    int gender;
    vector<int> ff, mf; 
};
vector<Person> v(10000);
vector<vector<bool> > isFriend(10000, vector<bool>(10000, false));
int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    while(M--) {
        char aid[10], bid[10];
        scanf("%s %s", aid, bid);
        int a = abs(stoi(aid)), b = abs(stoi(bid));
        if(aid[0] == '-') v[a].gender = 0;
        else v[a].gender = 1;
        if(bid[0] == '-') v[b].gender = 0;
        else v[b].gender = 1;
        isFriend[a][b] = isFriend[b][a] = true;
        if(v[b].gender == 0) v[a].ff.push_back(b);
        else v[a].mf.push_back(b);
        if(v[a].gender == 0) v[b].ff.push_back(a);
        else v[b].mf.push_back(a);
    }
    scanf("%d", &K);
    while(K--) {
        int a, b;
        scanf("%d %d", &a, &b);
        a = abs(a); b = abs(b);
        vector<int> af, bf;
        vector<pair<int, int> > res;
        af = v[a].gender == 1 ? v[a].mf : v[a].ff;
        bf = v[b].gender == 1 ? v[b].mf : v[b].ff;
        for(int i = 0; i < af.size(); i++) {
            for(int j = 0; j < bf.size(); j++) {
                if(isFriend[af[i]][bf[j]] && af[i] != b && bf[j] != a) res.push_back(make_pair(af[i], bf[j]));
            }
        }
        sort(res.begin(), res.end());
        cout << res.size() << endl;
        for(auto p : res) 
            printf("%04d %04d\n", p.first, p.second);
    }
    return 0;
}