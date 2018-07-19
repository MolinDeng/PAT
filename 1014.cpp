#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Customer {
    int line_no;
    int process_time;
    int start_time = 0;
    int end_time = 0;
    bool operator <(const Customer c) const {
        if(end_time == c.end_time) return line_no > c.line_no;
        else return end_time > c.end_time;
    }
};

int main(int argc, char const *argv[])
{
    int N, M, K, Q;
    scanf("%d %d %d %d", &N,&M, &K, &Q);
    vector<Customer> cus(K);
    for(int i = 0; i < K; i++) 
        scanf("%d", &cus[i].process_time);
    priority_queue<Customer> queueline;
    vector<int> line_time(N, 0);
    for(int i = 0, j = 0; i < N * M && i < K; i++, j = (j + 1)%N) {
        cus[i].line_no = j;
        cus[i].start_time = line_time[j];
        cus[i].end_time = line_time[j] = cus[i].start_time + cus[i].process_time;
        queueline.push(cus[i]);
    }
    for(int i = N*M; i < K; i++) {
        Customer out = queueline.top();
        queueline.pop();
        cus[i].line_no = out.line_no;
        cus[i].start_time = line_time[out.line_no];
        cus[i].end_time = line_time[out.line_no] = cus[i].start_time + cus[i].process_time;
        queueline.push(cus[i]);
    }
    
    while(Q--) {
        int query_c;
        scanf("%d", &query_c); query_c--;
        int hour = cus[query_c].end_time / 60 + 8;
        int mins = cus[query_c].end_time % 60;
        if(cus[query_c].start_time >= 540) printf("Sorry\n");
        else printf("%02d:%02d\n", hour, mins);
    }
    return 0;
}
