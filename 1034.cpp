#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> weights;
map<string, string> gang_set;
map<string, int> totweights;
map<string, vector<string> > res;
string gfind(string s) {
    if(gang_set.find(s) == gang_set.end()) gang_set[s] = "-1";
    if(atoi(gang_set[s].c_str()) < 0) return s;
    return gang_set[s] = gfind(gang_set[s]);
}
void union_by_size(string root1, string root2) {
    root1 = gfind(root1); root2 = gfind(root2);
    if(root1 == root2) return;
    int n1 = atoi(gang_set[root1].c_str());
    int n2 = atoi(gang_set[root2].c_str());
    totweights[root1] += totweights[root2];
    totweights.erase(root2);
    gang_set[root2] = root1;
    gang_set[root1] = to_string(n1+n2);
}
bool cmp(string a, string b) {
    return weights[a] < weights[b];
}
int main() {
    int threshold, N, cnt = 0;
    scanf("%d %d", &N, &threshold);
    while(N--) {
        char a[3], b[3];
        int L;
        scanf("%s %s %d", a, b, &L);
        weights[a] += L;
        weights[b] += L;
        union_by_size(a, b);
        totweights[gfind(a)] += L;
    }
    for(auto iter = gang_set.begin(); iter != gang_set.end(); iter++) {
        string root = gfind(iter->first);
        if(atoi(gang_set[root].c_str()) < -2 && totweights[root] > threshold) {
            res[root].push_back(iter->first);
        }
    }
    if(res.size() == 0) printf("0");
    else {
        vector<string> result;
        printf("%d\n", res.size());
        for(auto iter = res.begin(); iter != res.end(); iter++) {
            result.push_back(*max_element(iter->second.begin(), iter->second.end(), cmp));
        }
        sort(result.begin(), result.end());
        for(auto r : result) 
            printf("%s %d\n", r.c_str(), -atoi(gang_set[gfind(r)].c_str()));
    }
    return 0;
}