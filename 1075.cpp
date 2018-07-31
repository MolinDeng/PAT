#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N, K, M;
struct User {
    int id;
    int grade[6];
    int perfect_solved;
    User() {
        fill(grade, grade+6, -2);
        perfect_solved = 0;
    }
    int get_tot() {
        int sum = 0;
        for(int i = 1; i <= K; i++)
            if(grade[i] >= 0)
                sum += grade[i];
        return sum;
    }
};
vector<User> users(10010, User());
vector<bool> inrank(10010, false);
vector<int> ranklist;
vector<int> fscores(6, 0);
bool cmp(const int a, const int b) {
    int tot_a = users[a].get_tot(), tot_b = users[b].get_tot();
    if(tot_a != tot_b) 
        return tot_a > tot_b;
    else if(users[a].perfect_solved != users[b].perfect_solved) 
        return users[a].perfect_solved > users[b].perfect_solved;
    else 
        return a < b;    
}
int main() {
    scanf("%d %d %d", &N, &K, &M);
    for(int i = 1; i <= K; i++) 
        scanf("%d", &fscores[i]);
    while(M--) {
        int id, pid, grade;
        scanf("%d %d %d", &id, &pid, &grade);
        users[id].id = id;
        int pre_grade = users[id].grade[pid];
        users[id].grade[pid] = max(grade, users[id].grade[pid]);
        if(pre_grade != users[id].grade[pid] && users[id].grade[pid] == fscores[pid]) users[id].perfect_solved++;
        if(!inrank[id] && users[id].grade[pid] != -1) {
            ranklist.push_back(id);
            inrank[id] = true;
        } 
    }
    sort(ranklist.begin(), ranklist.end(), cmp);
    int pre_rank = 1;
    for(int i = 0; i < ranklist.size(); i++) {
        int id = ranklist[i];
        if(i == 0) {
            printf("1 %05d %d", id, users[id].get_tot());    
            for(int j = 1; j <= K; j++) {
                if(users[id].grade[j] == -1) printf(" 0");
                else if(users[id].grade[j] == -2) printf(" -");
                else printf(" %d", users[id].grade[j]);
            }
            printf("\n");
            pre_rank = 1;
        }   
        else {
            int rank = i + 1;
            if(users[id].get_tot() == users[ranklist[i-1]].get_tot()) rank = pre_rank;
            printf("%d %05d %d", rank, id, users[id].get_tot());    
            for(int j = 1; j <= K; j++) {
                if(users[id].grade[j] == -1) printf(" 0");
                else if(users[id].grade[j] == -2) printf(" -");
                else printf(" %d", users[id].grade[j]);
            }
            printf("\n");
            pre_rank = rank;
        }
    }
    return 0;
}