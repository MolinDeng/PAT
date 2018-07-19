#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(int x) {
    if(x < 2) return false;
    if(x == 2 || x == 3) return true;
    for(int i = 2; i*i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

int reverse(int x1, int radix) {
    int x2 = 0;
    while(x1 != 0) {
        x2 *= radix;
        x2 += x1 % radix;
        x1 /= radix;
    }
    return x2;
}
int main(int argc, char const *argv[])
{
    int x, radix;
    while(scanf("%d", &x) != EOF) {
        if(x < 0) break;
        scanf("%d", &radix);
        puts( (is_prime(reverse(x, radix)) && is_prime(x))? "Yes": "No" );
    }
    return 0;
}
