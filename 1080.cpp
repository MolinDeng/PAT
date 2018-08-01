#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <climits>
#include <cmath>
#include <cstdlib>

#define MAX_N 40010
using namespace std;



struct Stu {
    int GE, GI, ID;
    vector<int> Choice;
    int get_tot() const{
        return GE+GI;
    }
    bool operator ==(const Stu &b) const {
        return get_tot() == b.get_tot() && GE == b.GE;
    }
};
vector<Stu> student(MAX_N);
bool cmp(const Stu &a, const Stu &b) {
    if(a.get_tot() != b.get_tot()) 
        return a.get_tot() > b.get_tot();
    else return a.GE > b.GE;
}
bool cmpID(const int a, const int b) {
    return student[a].ID < student[b].ID;
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    vector<int> Quota(M);
    vector<vector<int> > Accepted(M, vector<int>());
    for(int i = 0; i < M; i++) 
        scanf("%d", &Quota[i]);
    for(int i = 0; i < N; i++) {
        student[i].ID = i;
        scanf("%d %d", &student[i].GE, &student[i].GI);
        for(int j = 0; j < K; j++) {
            int schID;
            scanf("%d", &schID);
            student[i].Choice.push_back(schID);
        }
    }
    sort(student.begin(), student.begin()+N, cmp);

    for(int i = 0; i < N; i++) {
        bool flag = false;
        for(int j = 0; j < K; j++) {
            int schID = student[i].Choice[j];
            if(Accepted[schID].size() < Quota[schID]) {
                Accepted[schID].push_back(i);
                flag = true;
            }
            else if(!Accepted[schID].empty()){
                int pre_stuID = Accepted[schID].back();
                if(student[i] == student[pre_stuID]) {
                    Accepted[schID].push_back(i);
                    flag = true;
                }
            }
            if(flag) break;
        }
    }
    for(int i = 0; i < M; i++) {
        if(!Accepted[i].empty()) {
            sort(Accepted[i].begin(), Accepted[i].end(), cmpID);
            for(int j = 0; j < Accepted[i].size(); j++) {
                if(j != 0) printf(" ");
                printf("%d", student[Accepted[i][j]].ID);
            }
        }
        printf("\n");
    }
    return 0;
}