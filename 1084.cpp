#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

vector<bool> broken(256, false);

int main() {
    string in;
    char c;
    cin >> in;
    getchar();
    while((c = getchar()) != '\n') {
        in.erase(find(in.begin(), in.end(), c));
    }
    for(auto c : in) {
        c = toupper(c);
        if(!broken[toascii(c)]) {
            printf("%c", c);
            broken[toascii(c)] = true;
        }
    }
    return 0;
}