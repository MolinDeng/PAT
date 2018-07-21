#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// long long reverse_num(long long x1, long long radix) {
//     long long x2 = 0;
//     while(x1) {
//         x2 *= radix;
//         x2 += x1 % radix;
//         x1 /= radix;
//     }
//     return x2;
// }

// int main() {
//     long long x, radix;
//     scanf("%lld %lld", &x, &radix);
//     if(x == 0 || x < radix) 
//         printf("Yes\n%lld", x);
//     else {
//         long long rx = reverse_num(x, radix);
//         if(x == rx) printf("Yes\n");
//         else printf("No\n");
//         while(rx) {
//             printf("%lld", rx % radix);
//             if(rx / radix != 0) printf(" ");
//             rx /= radix;
//         }
//     }
//     return 0;
// }

int main() {
    long long N, R;
    scanf("%lld %lld", &N, &R);
    if(N == 0 || N <= R) printf("Yes\n%lld", N);
    else {
        bool yes = false;
        vector<long long> vec;
        while(N) {
            vec.push_back(N % R);
            N /= R;
        }
        for(int i = 0; i < vec.size() / 2; i++) {
            if(vec[i] != vec[vec.size() - 1 - i]) {
                printf("No\n");
                yes = true;
                break;
            }
        }
        if(!yes) printf("Yes\n");
        for(auto v = vec.rbegin(); v != vec.rend(); v++) {
            printf("%lld", *v);
            if(v + 1 != vec.rend()) printf(" ");
        }
    }
    return 0;

}