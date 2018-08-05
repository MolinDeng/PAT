#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    long N;
    scanf("%ld", &N);
    double pre = 0, sum = 0;
    for(long i = 1; i <= N; i++) {
        double cur;
        scanf("%lf", &cur);
        sum += cur * i * (N - i + 1);
    }
    printf("%.2f", sum);
    return 0;
}
