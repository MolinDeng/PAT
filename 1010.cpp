#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

long long to_decimal(string s, long long radix) {
    long long d = 0;
    for(int i = 0; i < s.length(); i++) {
        d *= radix;
        d += isdigit(s[i]) ? s[i] - '0' : s[i] - 'a' + 10;
    }
    return d;
}
int main() {
    string a, b;
    int tag;
    long long radix;
    cin >> a >> b >> tag >> radix;
    if(tag == 2) swap(a, b);
    long long target = to_decimal(a, radix), res = -1;
    char maxc = *max_element(b.begin(), b.end());
    long long left = max(1, isdigit(maxc) ? maxc - '0': maxc - 'a' + 10) + 1, right = target + 1;
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long d = 0;
        for(int i = 0; i < b.length(); i++) {
            d *= mid;
            d += isdigit(b[i]) ? b[i] - '0' : b[i] - 'a' + 10;
            if(d > target || d < 0) break;
        }
        if(d == target) {
            res = mid;
            right--;
        }
        else if(d > target || d < 0)
            right = mid - 1;
        else if(d < target)
            left = mid + 1; 
    }
    if(res == -1) cout << "Impossible" << endl;
    else cout << res;
    return 0;
}