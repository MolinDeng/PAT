#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

struct Node {
    string id;
    int loc, loc_rank, rank;
    int grade;
};

bool cmp(const Node &a, const Node &b) {
    if(a.grade != b.grade) return a.grade > b.grade;
    else return a.id < b.id;
}

int main() {
    int N, K;
    scanf("%d", &N);
    vector<Node> ranklist;
    vector<Node> tmp;
    for(int i = 1; i <= N; i++) {
        scanf("%d", &K);
        while(K--) {
            string id; int grade;
            cin >> id >> grade;
            tmp.push_back({id, i, 0, 0, grade});
        }
        sort(tmp.begin(), tmp.end(), cmp);
        int pre_grade = -1, pre_rank = 0;
        for(int i = 0; i < tmp.size(); i++) {
            if(tmp[i].grade == pre_grade)
                tmp[i].loc_rank = pre_rank;
            else tmp[i].loc_rank = i + 1;
            pre_grade = tmp[i].grade;
            pre_rank = tmp[i].loc_rank;
        }
        ranklist.insert(ranklist.end(), tmp.begin(), tmp.end());
        tmp.clear();
    }
    sort(ranklist.begin(), ranklist.end(), cmp);
    int pre_grade = -1, pre_rank = 0;
    for(int i = 0; i < ranklist.size(); i++) {
        if(ranklist[i].grade == pre_grade)
            ranklist[i].rank = pre_rank;
        else ranklist[i].rank = i + 1;
        pre_grade = ranklist[i].grade;
        pre_rank = ranklist[i].rank;
    }
    cout << ranklist.size() << endl;
    for(auto i : ranklist) 
        printf("%s %d %d %d\n", i.id.c_str(), i.rank, i.loc, i.loc_rank);
    return 0;
}