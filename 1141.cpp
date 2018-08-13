#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <functional>

using namespace std;

struct DATA {
    string name;
    long tws;
    long Ns;
};
unordered_map<string, pair<double, long> > TWS;
bool cmp(DATA &a, DATA &b) {
    if(a.tws != b.tws) return a.tws > b.tws;
    else if(a.Ns != b.Ns) return a.Ns < b.Ns;
    else return a.name < b.name;
}
int main() {
    long N;
    scanf("%ld", &N);
    while(N--) {
        char id[10], sname[10];
        long grade;
        scanf("%s %ld %s", id, &grade, sname);
        transform(sname, sname+strlen(sname), sname, ::tolower);
        TWS[sname].first += (id[0] == 'B' ? grade / 1.5 : (id[0] == 'A' ? grade : grade * 1.5));
        TWS[sname].second++;
    }
    vector<DATA> ranklist;
    for(auto iter = TWS.begin(); iter != TWS.end(); iter++)
        ranklist.push_back({iter->first, (long)iter->second.first, iter->second.second});
    sort(ranklist.begin(), ranklist.end(), cmp);
    long pre_TWS = -1, pre_rank = -1;
    cout << ranklist.size() << endl;
    for(long i = 0; i < ranklist.size(); i++) {
        if(ranklist[i].tws != pre_TWS) {
            printf("%ld ", i+1);
            pre_rank = i+1;
        }
        else printf("%ld ", pre_rank);
        printf("%s %ld %ld\n", ranklist[i].name.c_str(), ranklist[i].tws, ranklist[i].Ns);
        pre_TWS = ranklist[i].tws;
    }
    return 0;
}