#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    string name;
    int age;
    long long w;
};
bool cmp1(const Node &a, const Node &b) {
    if(a.w != b.w) return a.w > b.w;
    else if(a.age != b.age) return a.age < b.age;
    else return a.name < b.name;
}
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<Node> v(N), v1;
    vector<int> ageCnt(205, 0);
    for(int i = 0; i < N; i++) {
        char name[10];
        int age;
        long long w;
        scanf("%s%d%lld", name, &age, &w);
        v[i] = {name, age, w};
    }
    sort(v.begin(), v.end(), cmp1);
    for(int i = 0; i < N; i++) {
        if(ageCnt[v[i].age] < 100) {
            v1.push_back(v[i]);
            ageCnt[v[i].age]++;
        }
    }
    for(int i = 1; i <= K; i++) {
        int M, Amin, Amax;
        scanf("%d %d %d", &M, &Amin, &Amax);
        printf("Case #%d:\n", i);
        if(Amin > Amax) {
            cout << "None" << endl;
            continue;
        }
        vector<Node> res;
        for(int j = 0; j < v1.size(); j++) {
            if(v1[j].age >= Amin && v1[j].age <= Amax) {
                res.push_back(v1[j]);
            }
            if(res.size() == M) break;
        }
        if(res.size() == 0) cout << "None" << endl;
        else 
            for(auto node : res) 
                printf("%s %d %lld\n", node.name.c_str(), node.age, node.w);
    }
    return 0;
}