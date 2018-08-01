#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <utility>

using namespace std;

int main() {
    string str, num, sub;
    cin >> str;
    if(str == "0") {cout << "ling"; return 0;}
    vector<string> res;
    reverse(str.begin(), str.end());
    bool pre_is0 = false;
    for(int i = 0; i < str.length(); i++) {
        bool skip_flag = false;
        sub.clear();
        num.clear();
        switch(i) {
            case 0: sub = ""; break;
            case 1: sub = " Shi"; break;
            case 2: sub = " Bai"; break;
            case 3: sub = " Qian"; break;
            case 4:
                res.insert(res.begin(), "Wan"); 
                sub = ""; 
                break;
            case 5: sub = " Shi"; break;
            case 6: sub = " Bai"; break;
            case 7: sub = " Qian"; break;
            case 8: sub = " Yi"; break;
            default: break;    
        }
        switch(str[i]) {
            case '-': num = "Fu"; sub = ""; pre_is0 = false; break;
            case '9': num = "jiu"; pre_is0 = false; break;
            case '8': num = "ba"; pre_is0 = false; break;
            case '7': num = "qi"; pre_is0 = false; break;
            case '6': num = "liu"; pre_is0 = false; break;
            case '5': num = "wu"; pre_is0 = false; break;
            case '4': num = "si"; pre_is0 = false; break;
            case '3': num = "san"; pre_is0 = false; break;
            case '2': num = "er"; pre_is0 = false; break;
            case '1': num = "yi"; pre_is0 = false; break;
            case '0': 
                if(i == 0 || i == 4) {
                    skip_flag = true;
                }
                else if(!pre_is0) {
                    num = "ling";
                    sub = "";
                } else {
                    skip_flag = true;
                }
                pre_is0 = true;
                break;
        }
        if(!skip_flag) res.insert(res.begin(), num + sub);
    }
    for(int i = 0; i < res.size(); i++) {
        if(i != 0) cout << " ";
        cout << res[i];
    }
    return 0;
}