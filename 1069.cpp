#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
    string a;
    cin >> a;
    a.insert(0, 4 - a.length(), '0');
    if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) {
        cout << a + " - " + a + " = " + "0000\n";
        return 0;
    } 
    string res = "";
    while(res != "6174") {
        sort(a.begin(), a.end());
        string b(a.rbegin(), a.rend());
        res = to_string(stoi(b) - stoi(a));
        while(res.size() < 4) 
            res = "0" + res;
        cout << b + " - " + a + " = " + res << endl;
        if(res == "0000") break;
        a = res;
    }
    return 0;
}
