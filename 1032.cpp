#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;

map<string, string> pre;
set<string> S;
int main() {
    string head1, head2;
    int N;
    cin >> head1 >> head2 >> N;
    while(N--) {
        char s1[5], s2[5], c;
        scanf("%s %c %s", s1, &c, s2);
        if(S.find(s2) != S.end()) {
            printf("%s", s2);
            break;
        }
        S.insert(s2);
    }
    return 0;
}