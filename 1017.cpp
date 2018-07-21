#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define OPEN_TIME 8*3600
#define CLOSE_TIME 17*3600

using namespace std;

struct Customer {
    int arr_time;
    int start_time = 0;
    int leave_time = 0;
    int process_time;
    int wait_time = 0;
    bool operator < (const Customer b) const {
        return leave_time > b.leave_time;
    }
    Customer(int h, int m, int s, int pt): arr_time(h*3600+m*60+s), process_time(pt*60) {}
};

bool arr_time_cmp(const Customer &a, const Customer &b) {
    return a.arr_time < b.arr_time;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    vector<Customer> cus;
    priority_queue<Customer> Cqueue;
    while(N--) {
        int h, m, s, pt;
        scanf("%d:%d:%d %d", &h, &m, &s, &pt);
        if(h*3600+m*60+s > CLOSE_TIME) continue;
        Customer c(h, m, s, pt);
        cus.push_back(c);
    }
    sort(cus.begin(), cus.end(), arr_time_cmp);
    for(int i = 0; i < cus.size() && i < K; i++) {
        if(cus[i].arr_time < OPEN_TIME) {
            cus[i].wait_time = OPEN_TIME - cus[i].arr_time;
            cus[i].start_time = OPEN_TIME;
        }
        else {
            cus[i].wait_time = 0;
            cus[i].start_time = cus[i].arr_time;
        }
        cus[i].leave_time = cus[i].start_time + cus[i].process_time;
        Cqueue.push(cus[i]);
    }
    for(int i = K; i < cus.size(); i++) {
        Customer out = Cqueue.top();
        Cqueue.pop();
        if(cus[i].arr_time < out.leave_time) {
            cus[i].start_time = out.leave_time;
            cus[i].wait_time = cus[i].start_time - cus[i].arr_time;
        }
        else {
            cus[i].start_time = cus[i].arr_time;
            cus[i].wait_time = 0;
        }
        cus[i].leave_time = cus[i].start_time + cus[i].process_time;
        Cqueue.push(cus[i]);
    }
    if(cus.size() == 0) printf("0.0");
    else {
        float tot_wait_time = 0;
        for(auto c : cus)
            tot_wait_time += c.wait_time;
        printf("%.1f\n", tot_wait_time / 60.0 / cus.size());
    }
    return 0;
}