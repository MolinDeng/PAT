#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int> > Weibo(1010); 
vector<bool> visited(1010, false);
int main(int argc, char const *argv[])
{
    int N, L;
    scanf("%d %d", &N, &L);   
    for(int i = 1; i <= N; i++) {
        int num;
        scanf("%d", &num);
        while(num--) {
            int id;
            scanf("%d", &id);
            Weibo[id].push_back(i);
        }
    }
    int qnum;
    scanf("%d", &qnum);
    while(qnum--) {
        int sid, f_cnt = 0, res = 0;
        fill(visited.begin(), visited.end(), false);
        scanf("%d", &sid);
        if(Weibo[sid].empty()) printf("0\n");
        else {
            queue<int> S;
            S.push(sid);
            visited[sid] = true;
            while(f_cnt != L) {
                int in_cnt = S.size();
                for(int i = 0; i < in_cnt; i++) {
                    int out = S.front();
                    for(auto id : Weibo[out]) {
                        if(!visited[id]) {
                            S.push(id);
                            visited[id] = true;
                        }
                    }
                    S.pop();
                }
                res += S.size();
                f_cnt++;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}