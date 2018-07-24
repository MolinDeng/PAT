// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <map>
// #include <queue>
// #include <functional>

// using namespace std;

// struct Female {
//     string name;
//     string ID;
//     int grade;
//     Female(string _name, string _ID, int _grade): name(_name), ID(_ID), grade(_grade) {}
//     bool operator<(const Female& b) const{
//         return grade < b.grade;
//     }
// };
// struct Male {
//     string name;
//     string ID;
//     int grade;
//     Male(string _name, string _ID, int _grade): name(_name), ID(_ID), grade(_grade) {}
//     bool operator<(const Male& b) const{
//         return grade > b.grade;
//     }
// };

// // struct cmp {
// //     bool reverse;
// // public:
// //     cmp(const bool& _r = false) { reverse = _r; }
// //     bool operator ()(const Student& a, const Student& b) const {
// //         if(reverse) return a.grade > b.grade;// low grade first out
// //         return a.grade < b.grade;// high grade first out
// //     }
// // };
// priority_queue<Female> Fqueue;
// priority_queue<Male> Mqueue;

// int main() {
//     int N;
//     scanf("%d", &N);
//     while(N--) {
//         char name[10], gender, ID[10];
//         int grade;
//         scanf("%s %c %s %d", name, &gender, ID, &grade);
//         if(gender == 'M') Mqueue.push(Male(name, ID, grade));
//         else Fqueue.push(Female(name, ID, grade));
//     }
//     bool flag = false;
//     if(Fqueue.empty()) {printf("Absent\n"); flag = true;}
//     else printf("%s %s\n", Fqueue.top().name.c_str(), Fqueue.top().ID.c_str());
//     if(Mqueue.empty()) {printf("Absent\n"); flag = true;}
//     else printf("%s %s\n", Mqueue.top().name.c_str(), Mqueue.top().ID.c_str());
//     if(flag) printf("NA");
//     else printf("%d", Fqueue.top().grade - Mqueue.top().grade);
//     return 0;
// }

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <functional>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int f_grade = -1, m_grade = 101;
    string f_res, m_res;
    while(N--) {
        string name, ID;
        char gender;
        int grade;
        cin >> name >> gender >> ID >> grade;
        if(gender == 'M') {
            if(grade < m_grade) {
                m_grade = grade;
                m_res = name + " " + ID;
            }
        }
        else {
            if(grade > f_grade) {
                f_grade = grade;
                f_res = name + " " + ID;
            }
        }
    }
    if(f_grade == -1) printf("Absent\n");
    else printf("%s\n", f_res.c_str());
    if(m_grade == 101) printf("Absent\n");
    else printf("%s\n", m_res.c_str());
    if(f_grade != -1 && m_grade != 101) printf("%d", f_grade-m_grade);
    else printf("NA");
    return 0;
}