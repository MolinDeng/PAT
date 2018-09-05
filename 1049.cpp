#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    scanf("%d", &n);
    while(n / a) {
        left = n / (a*10), now = n / a % 10, right = n % a;
        if(now == 0) ans += left * a;
        else if(now == 1) ans += left * a + right + 1;
        else ans += (left + 1) * a;
        a *= 10;
    }
    printf("%d", ans);
    return 0;
}

/*
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    long long N, sum = 0, p = 1;
    cin >> N;
    while(N / p) {
        long long h = N / (p * 10);
        long long l = N % p;
        long long cur = N / p % 10;
        if(cur == 0) sum += h * p;
        else if(cur == 1) sum += h * p + l + 1;
        else sum += (h + 1) * p;
        p *= 10;
    }
    cout << sum;
    return 0;
}
*/