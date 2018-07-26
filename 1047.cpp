#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;
//第一份
int main(int argc, char const *argv[])
{
    long N, K;
    scanf("%ld %ld", &N, &K);
    vector<set<string> > courses(K);
    while(N--) {
        char name[4];
        long C;
        scanf("%s %ld", name, &C);
        while(C--) {
            int id;
            scanf("%d", &id);
            courses[--id].insert(name);
        }
    }
    for(int i = 0; i < K; i++) {
        printf("%d %lld\n", i+1, courses[i].size());
        for(auto s : courses[i]) printf("%s\n", s.c_str());
    }
    return 0;
}
// 第二份
char name[40001][5];
bool cmp(const int a, const int b) {
    return string(name[a]) < string(name[b]);
}
bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
int main(int argc, char const *argv[])
{
    long N, K;
    scanf("%ld %ld", &N, &K);
    vector<vector<int> > courses(K);
    for(int i = 0; i < N; i++) {
        long C;
        scanf("%s %ld", name[i], &C);
        while(C--) {
            int id;
            scanf("%d", &id);
            courses[--id].push_back(i);
        }
    }
    for(int i = 0; i < K; i++) {
        printf("%d %lld\n", i+1, courses[i].size());
        sort(courses[i].begin(), courses[i].end(), cmp);
        for(auto s : courses[i]) printf("%s\n", name[s]);
    }
    return 0;
}
