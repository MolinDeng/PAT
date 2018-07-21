#include <vector>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;
int main(int argc, char const *argv[])
{
    string num;
    cin >> num;
    string origin(num);
    sort(origin.begin(), origin.end());
    int carry = 0;
    for(int i = num.length() - 1; i >= 0; i--) {
        int tmp = (num[i] - '0') * 2;
        num[i] =  tmp % 10 + '0' + carry;
        carry = tmp / 10;
    }
    string res;
    if(carry == 1) {
        res = to_string(carry) + num;
    } else res = num;
    string res_copy(res);
    sort(res_copy.begin(), res_copy.end());
    if(res_copy == origin) 
        printf("Yes\n");
    else 
        printf("No\n");
    cout << res;
    return 0;
}