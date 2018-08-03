#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Rcd {
    string id;
    int timestamp;
    int flag;
    Rcd(string _id, int tt, int _flag): id(_id), timestamp(tt), flag(_flag) {}
};
bool cmp1(const Rcd &a, const Rcd &b) {
    if(a.id != b.id) return a.id < b.id;
    else return a.timestamp < b.timestamp;
}
bool cmp2(const Rcd &a, const Rcd &b) {
    return a.timestamp < b.timestamp;
}
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<Rcd> records, car;
    for(int i = 0; i < N; i++) {
        char id[10], state[5];
        int hh, mm, ss;
        scanf("%s %d:%d:%d %s", id, &hh, &mm, &ss, state);
        records.push_back(Rcd(id, 3600*hh+60*mm+ss, state[0] == 'i' ? 1 : -1));
    }
    sort(records.begin(), records.end(), cmp1);
    map<string, int> Ptime;
    int maxlen = -1;
    vector<string> res;
    for(int i = 0; i < N-1; i++) {
        if(records[i].id == records[i+1].id && records[i].flag == 1 && records[i+1].flag == -1) {
            car.push_back(records[i]);
            car.push_back(records[i+1]);
            Ptime[records[i].id] += (records[i+1].timestamp - records[i].timestamp);
            if(Ptime[records[i].id] > maxlen) {
                maxlen = Ptime[records[i].id];
                res.clear();
                res.push_back(records[i].id);
            } else if(Ptime[records[i].id] == maxlen)
                res.push_back(records[i].id);
        }
    }
    sort(car.begin(), car.end(), cmp2);
    vector<int> carcnt(car.size(), 0);
    for(int i = 0; i < car.size(); i++) 
        carcnt[i] = carcnt[i == 0 ? 0 : i-1] + car[i].flag; 
    int index = 0;
    while(K--) {
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int t = 3600*hh + 60*mm + ss, cnt = 0;
        for( ; index < car.size(); index++) {
            if(car[index].timestamp > t) {
                printf("%d\n", carcnt[index-1]);
                break;
            }
            else if(index == car.size() - 1) 
                printf("%d\n", carcnt[index]);
        }   
    }
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++) {
        printf("%s ", res[i].c_str());
    }
    printf("%02d:%02d:%02d", maxlen/3600, maxlen%3600/60, maxlen%3600%60);
    return 0;
}