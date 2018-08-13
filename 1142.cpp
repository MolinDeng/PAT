#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool e[210][210] = {false};
int main() {
    int Nv, Ne, K;
    scanf("%d %d", &Nv, &Ne);
    while(Ne--) {
        int a, b;
        scanf("%d %d", &a, &b);
        e[a][b] = e[b][a] = true;
    }
    scanf("%d", &K);
    while(K--) {
        int N;
        bool isMax = true, isC = true;
        vector<bool> counted(Nv+1, false);
        scanf("%d", &N);
        vector<int> Clique;
        while(N--) {
            int u;
            scanf("%d", &u);
            if(!isC) continue;
            for(auto v : Clique) {
                if(!e[u][v]) {
                    isC = false;
                    break;
                }
            }
            Clique.push_back(u);
            counted[u] = true;
        }
        if(!isC) cout << "Not a Clique" << endl;
        else {
            for(int u = 1; u <= Nv; u++) {
                if(!counted[u]) {
                    bool flag = true;
                    for(auto v : Clique) {
                        if(!e[u][v]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        isMax = false;
                        break;
                    }
                }
            }
            cout << (isMax ? "Yes" : "Not Maximal") << endl;
        }
    }
    return 0;
}