#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;
bool cmp(const string &a, const string &b) {
    return a < b;
}
int main(int argc, char const *argv[])
{
    long N, K;
    scanf("%ld %ld", &N, &K);
    vector<vector<string> > courses(K);
    while(N--) {
        char name[4];
        long C;
        scanf("%s %ld", name, &C);
        while(C--) {
            int id;
            scanf("%d", &id);
            courses[--id].push_back(name);
        }
    }
    for(int i = 0; i < K; i++) {
        printf("%d %lld\n", i+1, courses[i].size());
        sort(courses[i].begin(), courses[i].end(), cmp);
        for(auto s : courses[i]) printf("%s\n", s.c_str());
    }
    return 0;
}