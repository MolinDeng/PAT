#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

map<int, int> queue_map;
struct Window {
    int M;
    pair<int, int> pop_time;
    queue<int> Queue;
    Window(int capacity): M(capacity), pop_time(8,0) {}
};

bool cmp(Window a, Window b) {return a.pop_time < b.pop_time;}
int main(int argc, char const *argv[])
{
    int N, M, K, Q;
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    vector<Window> Windows(N, Window(M));
    queue<int> oqueue;
    vector<int> pro_times(K);
    for(int i =0; i < K; i++) 
        scanf("%d", &pro_times[i]);
    
    for(int i = 0, j = 0; i < K; i++, j = (j+1)%N ) {
        if(i < N*M) {
            Windows[j].Queue.push(i);
            queue_map[i] = j;
        }
        else oqueue.push(i);
    }
    
    for(int j = 0; j < N; j++) {
        if(!Windows[j].Queue.empty()) {
            Windows[j].pop_time.first += pro_times[Windows[j].Queue.front()] / 60;
            Windows[j].pop_time.second += pro_times[Windows[j].Queue.front()] % 60;
            Windows[j].pop_time.first += Windows[j].pop_time.second / 60;
            Windows[j].pop_time.second %= 60; 
        }
    }
    
    while(Q--) {
        int cID;
        scanf("%d", &cID); cID--;
        vector<Window> W_copy(Windows);
        queue<int> out_queue(oqueue);
        if(cID < N*M) {
            int w_num = queue_map[cID];
            while(!W_copy[w_num].Queue.empty()) {
                if(cID == W_copy[w_num].Queue.front()) {
                    if(W_copy[w_num].pop_time > pair<int, int>(17,0)) 
                        printf("Sorry\n");
                    else printf("%02d:%02d\n", W_copy[w_num].pop_time.first, W_copy[w_num].pop_time.second);
                    break;
                }
                W_copy[w_num].Queue.pop();
                if(!W_copy[w_num].Queue.empty()) {
                    W_copy[w_num].pop_time.first += pro_times[W_copy[w_num].Queue.front()] / 60;
                    W_copy[w_num].pop_time.second += pro_times[W_copy[w_num].Queue.front()] % 60;
                    W_copy[w_num].pop_time.first += W_copy[w_num].pop_time.second / 60;
                    W_copy[w_num].pop_time.second %= 60; 
                }
            }
        }
        else {
            int w_num;
            while(true) {
                int w_in = min_element(W_copy.begin(), W_copy.end(), cmp) - W_copy.begin();
                W_copy[w_in].Queue.pop();
                W_copy[w_in].Queue.push(out_queue.front());
                W_copy[w_in].pop_time.first += pro_times[W_copy[w_in].Queue.front()] / 60;
                W_copy[w_in].pop_time.second += pro_times[W_copy[w_in].Queue.front()] % 60;
                W_copy[w_in].pop_time.first += W_copy[w_in].pop_time.second / 60;
                W_copy[w_in].pop_time.second %= 60; 
                if(cID == out_queue.front()) {
                    w_num = w_in;
                    break;
                }
                else out_queue.pop();
            }
            while(!W_copy[w_num].Queue.empty()) {
                if(cID == W_copy[w_num].Queue.front()) {
                    if(W_copy[w_num].pop_time > pair<int, int>(17,0)) 
                        printf("Sorry\n");
                    else printf("%02d:%02d\n", W_copy[w_num].pop_time.first, W_copy[w_num].pop_time.second);
                    break;
                }
                W_copy[w_num].Queue.pop();
                if(!W_copy[w_num].Queue.empty()) {
                    W_copy[w_num].pop_time.first += pro_times[W_copy[w_num].Queue.front()] / 60;
                    W_copy[w_num].pop_time.second += pro_times[W_copy[w_num].Queue.front()] % 60;
                    W_copy[w_num].pop_time.first += W_copy[w_num].pop_time.second / 60;
                    W_copy[w_num].pop_time.second %= 60;  
                }
            }
        }
    }
    return 0;
}
