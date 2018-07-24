#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <climits>

using namespace std;

bool cmp(const int a, const int b) {
    if(a > 0 && b > 0) return a > b;
    else if(a < 0 && b < 0) return a < b;
}
int main() {
    long long NC, NP, sum = 0;
    vector<int> Cover0;
    vector<int> Pover0;
    vector<int> Cbelow0;
    vector<int> Pbelow0;
    scanf("%lld", &NC);
    while(NC--) {
        int coupon;
        scanf("%d", &coupon);
        if(coupon > 0) Cover0.push_back(coupon);
        else if(coupon < 0)Cbelow0.push_back(coupon); 
    }
    sort(Cover0.begin(), Cover0.end(), cmp);
    sort(Cbelow0.begin(), Cbelow0.end(), cmp);
    scanf("%lld", &NP);
    while(NP--) {
        int product;
        scanf("%d", &product);
        if(product > 0) Pover0.push_back(product);
        else if(product < 0) Pbelow0.push_back(product);
    }
    sort(Pover0.begin(), Pover0.end(), cmp);
    sort(Pbelow0.begin(), Pbelow0.end(), cmp);
    if(!Cover0.empty() && !Pover0.empty()) 
        for(int i = 0; i < Cover0.size() && i < Pover0.size(); i++) 
            sum += Cover0[i] * Pover0[i];
    if(!Cbelow0.empty() && !Pbelow0.empty()) 
        for(int i = 0; i < Cbelow0.size() && Pbelow0.size(); i++)
            sum += Cbelow0[i] * Pbelow0[i];
    printf("%lld", sum);
    return 0;
}