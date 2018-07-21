#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;
bool is_Palindromic(string s) {
    string s_prime(s);
    reverse(s.begin(), s.end());
    return s_prime == s;
}
int main() {
    string N;
    int K, step = 0;
    cin >> N >> K;
    string num(N);
    while(step < K) {
        if(is_Palindromic(num)) break;
        step++;
        string S1(num);
        string S2(num);
        reverse(S2.begin(), S2.end());
        int carry = 0;
        for(int i = num.length() - 1; i >= 0; i--) {
            int tmp = (S1[i] - '0') + (S2[i] - '0') + carry;
            num[i] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        if(carry == 1) num = to_string(carry) + num;
    }
    cout << num << '\n' << step;
    return 0;
}