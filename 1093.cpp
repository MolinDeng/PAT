#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdlib>

#define MAX 1000000007

using namespace std;

int main() {
    long long Pcnt = 0, PAcnt = 0, PATcnt = 0;
    char c;
    while((c = getchar()) != '\n') {
        if(c == 'P') Pcnt++;
        else if(c == 'A') PAcnt += Pcnt;
        else if(c == 'T') PATcnt += PAcnt;
    }
    cout << PATcnt % MAX;
    return 0;
}