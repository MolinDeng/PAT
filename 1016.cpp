#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Record {
    int month, day, hour, minute;
    bool state;
    int timestamp;
    Record(int mo, int d, int h, int mi, bool _state): 
        month(mo), day(d), hour(h), minute(mi), state(_state) {
            timestamp = day * 24 * 60 + hour * 60  + minute;
        }
    bool operator < (const Record &b) const {
        return timestamp < b.timestamp;
    }
};

vector<int> cents_per_min(24);
int N;
map<string, vector<Record> > records;

int get_cost(int n) {
    int hours = n / 60;
    int minutes = n % 60;
    int cost = 0, i;
    for(i = 0; i < hours; i++)
        cost += cents_per_min[i % 24] * 60;
    cost += cents_per_min[i % 24] * minutes;
    return cost;
}

bool cmp(const Record &a, const Record &b) {
    return a.timestamp < b.timestamp;
}

int main() {
    for(int i = 0; i < 24; i++) 
        scanf("%d", &cents_per_min[i]);
    scanf("%d", &N);
    while(N--) {
        char customer[20], state[10];
        int month, day, hour, minute;
        scanf("%s %d:%d:%d:%d %s", customer, &month, &day, &hour, &minute, state);
        Record record(month, day, hour, minute, state[1] == 'n');
        records[customer].push_back(record);
    }
    for(auto iter = records.begin(); iter != records.end(); iter++) {
        sort(iter->second.begin(), iter->second.end(), cmp);
        bool found = false;
        int tot_cost = 0;
        for(int i = 0; i < iter->second.size() - 1; i++) {
            if(iter->second[i].state && !iter->second[i+1].state) {
                if(!found) {
                    printf("%s %02d\n", iter->first.c_str(), iter->second[i].month);
                    found = true;
                }
                int time_cost = iter->second[i+1].timestamp - iter->second[i].timestamp;
                int cost = get_cost(iter->second[i+1].timestamp) - get_cost(iter->second[i].timestamp);
                tot_cost += cost;
                printf("%02d:%02d:%02d %02d:%02d:%02d ", iter->second[i].day, iter->second[i].hour, iter->second[i].minute, iter->second[i+1].day, iter->second[i+1].hour, iter->second[i+1].minute);
                printf("%d $%0.2f\n", time_cost, (float)cost / 100.0);
            }
        }
        if(found) printf("Total amount: $%0.2f\n", (float)tot_cost / 100.0);
    }
    return 0;
}