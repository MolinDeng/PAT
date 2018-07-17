#include <cstdio>
#include <iostream>
#include <vector>

#define UP 6
#define DOWN 4
#define STAY 5

using namespace std;

int main(int argc, char const *argv[])
{
    int N, ith, tt = 0, pre_i = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &ith);
        tt += abs(ith - pre_i) * (ith > pre_i ? UP : (ith < pre_i ? DOWN : 0)) + STAY;
        pre_i = ith;
    }
    printf("%d", tt);
    return 0;
}
