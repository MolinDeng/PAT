#include <cstdio>
#include <iostream>
#include <climits>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>

using namespace std;

int main(int argc, char const *argv[])
{
    
    string N1, N2;
    long long tag, N1_d = 0, N2_d = 0, res = -1;
    int radix_tag;
    cin >> N1 >> N2 >> tag >> radix_tag;
    if(tag == 2) {swap(N1, N2);}

    for(int i = 0; i < N1.length(); i++)
        N1_d += (isalpha(N1[i]) ? N1[i] - 87 : N1[i] - '0') * pow(radix_tag, N1.length() - 1 - i);

    char r = *max_element(N2.c_str(), N2.c_str() + N2.length());
    
    long long left = (isalpha(r) ? r - 87 : r == '0' ? 1 : r - '0') + 1;
    long long right = N1_d + 1;
    while(left <= right) {
        long long mid = (left + right) / 2;
        N2_d = 0;
        for(int i = N2.length() - 1; i >= 0; i--) {
            N2_d += (isalpha(N2[i]) ? N2[i] - 87 : N2[i] - '0') * pow(mid, N2.length() - 1 - i);
            if(N2_d > N1_d || N2_d < 0) break;
        }
        if(N1_d == N2_d) {res = mid; right--;}
        else if(N2_d > N1_d || N2_d < 0) right = mid - 1;
        else if(N2_d < N1_d) left = mid + 1;
    }
    if(res == -1) cout << "Impossible";
    else cout << res;
    // test point 7 out of time
    // long long target_radix = (isalpha(r) ? r - 87 : r == '0' ? 1 : r - '0') + 1;
    // for( ; ; target_radix++) {
    //     N2_d = 0;
    //     for(int i = 0; i < N2.length(); i++)
    //         N2_d += (isalpha(N2[i]) ? N2[i] - 87 : N2[i] - '0') * pow(target_radix, N2.length() - 1 - i);
    //     //cout << N2_d << endl;
    //     if(N2_d > N1_d) {cout << "Impossible"; break;}
    //     else if(N2_d == N1_d) {cout << target_radix; break;}
    // }
    
    return 0;
}
