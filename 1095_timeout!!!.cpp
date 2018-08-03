#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_set>

using namespace std;

struct Record {
    string ID;
    int timestamp;
    int hh, mm, ss;
    bool state;// T for in, F for out
    Record(string id, int _hh, int _mm, int _ss, bool _s):
        ID(id), hh(_hh), mm(_mm), ss(_ss), state(_s) {
            timestamp = 3600*hh + 60*mm + ss;
        }
};
vector<Record> records;
bool cmp1(const Record &a, const Record &b) {
    return a.timestamp < b.timestamp;
}
int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        char id[10], state[5];
        int hh, mm, ss;
        scanf("%s %d:%d:%d %s", id, &hh, &mm, &ss, state);
        records.push_back(Record(id, hh, mm, ss, state[0] == 'i'));
    }
    sort(records.begin(), records.end(), cmp1);
    map<string, int> Ptime;
    vector<string> res;
    vector<bool> counted(N, false);
    while(K--) {
        fill(counted.begin(), counted.end(), false);
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int t = 3600*hh + 60*mm + ss, cnt = 0;;
        for(int i = 0; i < N && records[i].timestamp <= t; i++) {
            string id = records[i].ID;
            if(records[i].state == true && !counted[i]) {
                cnt++; counted[i] = false;
                for(int j = i + 1; j < N; j++) {
                    if(records[j].ID == id) {
                        if(records[j].state == true) {
                            if(records[j].timestamp > t) {
                                cnt--;
                            }
                            else {
                                counted[j] = true;
                                continue;
                            }
                        }
                        else {
                            if(records[j].timestamp <= t) {
                                cnt--;
                            }
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    int maxlen = -1;
    vector<bool> done(N, false);
    for(int i = 0; i < N; i++) {
        string id = records[i].ID;
        if(records[i].state == true) {
            int in = records[i].timestamp;
            for(int j = i+1; j < N; j++) {
                if(records[j].ID == id) {
                    if(records[j].state == false) {
                        if(!done[j]) {
                            Ptime[id] += records[j].timestamp-in;
                            done[j] = true;
                        }
                        break;
                    }
                    else {
                        in = records[j].timestamp;
                    }
                }
            }
            if(Ptime[id] > maxlen) {
                res.clear();
                maxlen = Ptime[id];
                res.push_back(id);
            }
            else if(Ptime[id] == maxlen) {
                res.push_back(id);
            }
        }
    }
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++) {
        printf("%s ", res[i].c_str());
    }
    printf("%02d:%02d:%02d", maxlen/3600, maxlen%3600/60, maxlen%3600%60);
    return 0;
}