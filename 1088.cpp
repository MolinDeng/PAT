#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

string frac2str(long long a, long long b) {
    bool flag = (a < 0)^(b < 0);
    a = abs(a); b = abs(b);
    if(b == 0) return "Inf";
    else if(a == 0) return "0";
    else {
        long long f = gcd(max(a, b), min(a,b));
        a /= f; b /= f;
        long long q = a / b;
        a = a % b;
        if(a == 0) return flag ? "(-"+to_string(q)+")" : to_string(q);
        else if(q == 0) return flag ? "(-"+to_string(a)+"/"+to_string(b)+")" : to_string(a)+"/"+to_string(b);
        else 
            return flag ? "(-"+to_string(q)+" "+to_string(a)+"/"+to_string(b)+")" : to_string(q)+" "+to_string(a)+"/"+to_string(b);
    }
}
int main() {
    long long a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    string left = frac2str(a1, b1);
    string right = frac2str(a2, b2);
    cout << left+" + "+right+" = "+frac2str(a1*b2+a2*b1, b1*b2) << endl;
    cout << left+" - "+right+" = "+frac2str(a1*b2-a2*b1, b1*b2) << endl;
    cout << left+" * "+right+" = "+frac2str(a1*a2, b1*b2) << endl;
    cout << left+" / "+right+" = "+frac2str(a1*b2, b1*a2);
    return 0;
}