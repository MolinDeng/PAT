#include <cstdio>
#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i < N + 1; i++) {
        long long a, b, c, sum;
        scanf("%lld %lld %lld", &a, &b, &c);
        sum = a + b;
        if(a > 0 && b > 0 && sum < 0)
            printf("Case #%d: true\n", i);
        else if(a < 0 && b < 0 && sum >= 0)
            printf("Case #%d: false\n", i);
        else printf("Case #%d: %s\n", i, (a+b>c ? "true" : "false"));
    }
    return 0;
}