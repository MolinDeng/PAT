#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string S;
    cin >> S;
    int sign = S[0] == '+'? true : false;
    auto pos = find(S.begin(), S.end(), 'E');
    string num(S.begin()+1, pos);
    num.erase(find(num.begin(), num.end(), '.'));
    int expo = stoi(string(pos+1, S.end()));    
    if(expo == 0) num = string(sign ? S.begin()+1 : S.begin(), pos);
    else if(expo < 0) {
        for(int i = 0; i < abs(expo) - 1; i++) {
            num = "0" + num;
        }
        num = (sign ? string("") : string("-")) + string("0.") + num;
    }
    else if(expo > 0) {
        if(expo > num.length() - 1) {
            int n = expo - num.length() + 1;
            for(int i = 0; i < n; i++) {
                num = num + "0";
            }      
            num = (sign ? "" : "-") + num;
        }
        else if(expo == num.length() - 1) {
            num = (sign ? "" : "-") + num;
        }
        else {
            num.insert(num.begin()+expo+1, '.');
            num = (sign ? "" : "-") + num;
        }
    }
    cout << num;
    return 0;
}