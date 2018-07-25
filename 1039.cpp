#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;

// map<string, set<int> > courses;

// int main() {
//     int N, K;
//     scanf("%d %d", &N, &K);
//     while(K--) {
//         int cid, num;
//         scanf("%d %d", &cid, &num);
//         while(num--) {
//             char name[4];
//             scanf("%s", name);
//             courses[name].insert(cid);
//         }
//     }
//     while(N--) {
//         char name[4];
//         scanf("%s", name);
//         printf("%s %d", name, courses[name].size());
//         if(!courses[name].empty()) for(auto c : courses[name]) printf(" %d", c);
//         printf("\n");
//     }
//     return 0;
// }


int idmap(char *name) {
    int id = 0;
    for(int i = 0; i < 3; i++)
        id = 26 * id + (name[i] - 'A');
    id = id * 10 + (name[3] - '0');
    return id;
}
vector<int>  courses[1000000];

int main() {
    long N, K;
    scanf("%ld %ld", &N, &K);
    for(int i = 0; i < K; i++) {
        int cid, num;
        scanf("%d %d", &cid, &num);
        for(int i = 0; i < num; i++) {
            char name[4];
            scanf("%s", name);
            courses[idmap(name)].push_back(cid);
        }
    }
    while(N--) {
        char name[4];
        scanf("%s", name);
        int id = idmap(name);
        printf("%s %d", name, courses[id].size());
        if(!courses[id].empty()) {
            sort(courses[id].begin(), courses[id].end());
            for(auto c : courses[id]) printf(" %d", c);
        }
        printf("\n");
    }
    return 0;
}