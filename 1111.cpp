#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <climits>

#define INF INT_MAX
using namespace std;
vector<vector<int> > matT, matD;
vector<bool> visitedD, visitedT;
int main() {
    int N, M, S, D;
    scanf("%d %d", &N, &M);
    visitedT.resize(N, false);
    visitedD.resize(N, false);
    matT.resize(N, vector<int>(N, INF));
    matD.resize(N, vector<int>(N, INF));
    while(M--) {
        int v1, v2, ow, len, t;
        scanf("%d %d %d %d %d", &v1, &v2, &ow, &len, &t);
        matD[v1][v2] = len;
        matT[v1][v2] = t;
        if(ow == 0) {
            matD[v2][v1] = len;
            matT[v2][v1] = t;
        }
    }
    scanf("%d %d", &S, &D);
    vector<int> pathD(N, -1), pathT(N, -1), Tcnt(N, 0), Icnt(N, 0), minD(N, INF), minT(N, INF), resT, resD; 
    minD[S] = minT[S] = 0; Icnt[S] = 1;
    for(int i = 0; i < N; i++) {
        int u_t = -1, u_d = -1, min_t = INF, min_d = INF;
        for(int j = 0; j < N; j++) {
            if(!visitedT[j] && min_t > minT[j]) {
                min_t = minT[j];
                u_t = j;
            }
            if(!visitedD[j] && min_d > minD[j]) {
                min_d = minD[j];
                u_d = j;
            }
        }
        if(u_t == -1 && u_d == -1) break;
        if(u_d != -1) visitedD[u_d] = true;
        if(u_t != -1) visitedT[u_t] = true;
        for(int v = 0; v < N; v++) {
            if(u_d != -1 && !visitedD[v] && matD[u_d][v] != INF) {
                if(minD[u_d] + matD[u_d][v] < minD[v]) {
                    minD[v] = minD[u_d] + matD[u_d][v];
                    Tcnt[v] = Tcnt[u_d] + matT[u_d][v];
                    pathD[v] = u_d;
                }
                else if(minD[u_d] + matD[u_d][v] == minD[v]) {
                    if(Tcnt[u_d] + matT[u_d][v] < Tcnt[v]) {
                        Tcnt[v] = Tcnt[u_d] + matT[u_d][v];
                        pathD[v] = u_d;
                    }
                }
            }
            if(u_t != -1 && !visitedT[v] && matT[u_t][v] != INF) {
                if(minT[u_t] + matT[u_t][v] < minT[v]) {
                    minT[v] = minT[u_t] + matT[u_t][v];
                    Icnt[v] = Icnt[u_t] + 1;
                    pathT[v] = u_t;
                }
                else if(minT[u_t] + matT[u_t][v] == minT[v]) {
                    if(Icnt[u_t] + 1 < Icnt[v]) {
                        Icnt[v] = Icnt[u_t] + 1;
                        pathT[v] = u_t;
                    }
                }
            }
        }
    }
    int i = D;
    while(i != -1) {
        resD.insert(resD.begin(), i);
        i = pathD[i];
    }
    i = D;
    while( i != -1) {
        resT.insert(resT.begin(), i);
        i = pathT[i];
    }
    if(resT == resD) {
        printf("Distance = %d; Time = %d: ", minD[D], minT[D]);
        for(int i = 0; i < resD.size(); i++) {
            if( i != 0) printf(" -> ");
            printf("%d", resD[i]);
        }
    } 
    else {
        printf("Distance = %d: ", minD[D]);
        for(int i = 0; i < resD.size(); i++) {
            if( i != 0) printf(" -> ");
            printf("%d", resD[i]);
        }
        printf("\n");
        printf("Time = %d: ", minT[D]);
        for(int i = 0; i < resT.size(); i++) {
            if( i != 0) printf(" -> ");
            printf("%d", resT[i]);
        }
    }
    return 0;
}