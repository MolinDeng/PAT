#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int H;
struct Person {
    string ID;
    int virtue;
    int talent;
    Person(string _ID, int v, int t): ID(_ID), virtue(v), talent(t) {}
    bool operator <(const Person& b) const {
        if(b.is_Sage()) {
            if(!is_Sage()) return true;
            else return (virtue+talent) == (b.virtue+b.talent)? (virtue==b.virtue? ID > b.ID : virtue<b.virtue) : ((virtue+talent)<(b.virtue+b.talent));
        } else if(b.is_Noble()) {
            if(is_Sage()) return false;
            else if(is_Noble()) return (virtue+talent) == (b.virtue+b.talent)? (virtue==b.virtue? ID > b.ID : virtue<b.virtue) : ((virtue+talent)<(b.virtue+b.talent));
            else return true;
        } else if(b.is_Fool()) {
            if(is_Sage() || is_Noble()) return false;
            else if(is_Fool()) return (virtue+talent) == (b.virtue+b.talent)? (virtue==b.virtue? ID > b.ID : virtue<b.virtue) : ((virtue+talent)<(b.virtue+b.talent));
            else return true;
        } else {
            if(is_Small()) return (virtue+talent) == (b.virtue+b.talent)? (virtue==b.virtue? ID > b.ID : virtue<b.virtue) : ((virtue+talent)<(b.virtue+b.talent));
            else return false;
        }
    }
    bool is_Sage() const {
        return (virtue >= H && talent >= H);
    }
    bool is_Noble() const {
        return (virtue >= H && talent < H);
    }
    bool is_Fool() const {
        return (virtue < H && talent < H && virtue >= talent);
    }
    bool is_Small() const {
        return !(is_Sage() || is_Noble() || is_Fool());
    }
};
int main() {
    priority_queue<Person> ranks;
    int N, L;
    scanf("%d %d %d", &N, &L, &H);
    while(N--) {
        char ID[10];
        int v, t;
        scanf("%s %d %d", ID, &v, &t);
        if(v < L || t < L) continue;
        ranks.push(Person(ID, v, t));
    }
    if(ranks.empty()) printf("0");
    else {
        printf("%d\n", ranks.size());
        while(!ranks.empty()) {
            printf("%s %d %d\n", ranks.top().ID.c_str(), ranks.top().virtue, ranks.top().talent);
            ranks.pop();
        }
    }
    return 0;
}

// bool cmp(const Person& a, const Person& b) {
//     if(b.is_Sage()) {
//         if(!a.is_Sage()) return false;
//         else return (a.virtue+a.talent) == (b.virtue+b.talent)? (a.virtue==b.virtue? a.ID < b.ID : a.virtue>b.virtue) : ((a.virtue+a.talent)>(b.virtue+b.talent));
//     } else if(b.is_Noble()) {
//         if(a.is_Sage()) return true;
//         else if(a.is_Noble()) return (a.virtue+a.talent) == (b.virtue+b.talent)? (a.virtue==b.virtue? a.ID < b.ID : a.virtue>b.virtue) : ((a.virtue+a.talent)>(b.virtue+b.talent));
//         else return false;
//     } else if(b.is_Fool()) {
//         if(a.is_Sage() || a.is_Noble()) return true;
//         else if(a.is_Fool()) return (a.virtue+a.talent) == (b.virtue+b.talent)? (a.virtue==b.virtue? a.ID < b.ID : a.virtue>b.virtue) : ((a.virtue+a.talent)>(b.virtue+b.talent));
//         else return false;
//     } else {
//         if(a.is_Small()) return (a.virtue+a.talent) == (b.virtue+b.talent)? (a.virtue==b.virtue? a.ID < b.ID : a.virtue>b.virtue) : ((a.virtue+a.talent)>(b.virtue+b.talent));
//         else return true;
//     }
// }