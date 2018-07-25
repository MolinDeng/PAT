#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <sstream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    vector<long long> gsk1, gsk2;
    stringstream aa(a);
    stringstream bb(b);
    string tok;
    while(getline(aa, tok, '.')) 
        gsk1.push_back(atoll(tok.c_str()));
    while(getline(bb, tok, '.')) 
        gsk2.push_back(atoll(tok.c_str()));
    long long carry = 0;
    vector<long long> base = {LLONG_MAX, 17, 29};
    for(int i = 2; i >= 0; i--) {
        gsk2[i] += gsk1[i] + carry;
        carry = gsk2[i] / base[i];
        gsk2[i] %= base[i];
    }
    printf("%lld.%lld.%lld", gsk2[0], gsk2[1], gsk2[2]);
    return 0;
}