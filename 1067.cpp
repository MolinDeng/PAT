#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <utility>
#include <cstdlib>

using namespace std;
vector<int> seq;
vector<int> pos;
int main() {
    int N, res = 0, i, j, pre_k = 0, cnt = 0;
    scanf("%d", &N);
    seq.resize(N);
    pos.resize(N);
    for(i = 0; i < N; i++) {
        scanf("%d", &seq[i]);
        pos[seq[i]] = i;
        if(seq[i] != i) cnt++;
    }
    while(cnt != 0) {
        if(pos[0] == 0) {
            int k;
            for(k = pre_k; k < N; k++) {
                if(pos[k] != k) {
                    i = 0;
                    j = pos[k];
                    //swap(seq[i], seq[j]);
                    pos[0] = j;
                    pos[k] = 0;
                    res++;
                    pre_k = k;
                    break;
                }
            }
            if(k == N) break;
        }
        else {
            i = pos[0];
            j = pos[i];
            //swap(seq[i], seq[j]);
            pos[0] = j;
            pos[i] = i;
            res++;
            cnt--;
        }  
        // for(auto iter : seq) cout << iter << " ";
        // cout << endl;
    }
    cout << res;
    return 0;
}