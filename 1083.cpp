#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Stu {
    string name, ID;
    int grade;
    Stu(string _n, string _id, int g): name(_n), ID(_id), grade(g) {}
    bool operator < (const Stu &b) const{
        return grade < b.grade;
    }
};
int main() {
    int N;
    scanf("%d", &N);
    priority_queue<Stu> ranklist;
    while(N--) {
        char name[10], ID[10];
        int grade;
        scanf("%s %s %d", name, ID, &grade);
        ranklist.push(Stu(name, ID, grade));
    }
    int low, high, cnt = 0;
    scanf("%d %d", &low, &high);
    while(!ranklist.empty()) {
        if(ranklist.top().grade < low) break;
        if(ranklist.top().grade <= high && ranklist.top().grade >= low) {
            printf("%s %s\n", ranklist.top().name.c_str(), ranklist.top().ID.c_str());
            cnt++;
        }
        ranklist.pop();
    }
    if(cnt == 0) printf("NONE");
    return 0;
}