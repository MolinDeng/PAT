#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    char S1[10001], c;
    vector<bool> alpha(256, true);
    cin.getline(S1, 10001);
    while((c = getchar()) != '\n') 
        alpha[toascii(c)] = false;
    for(int i = 0; i < strlen(S1); i++) {
        c = S1[i];
        if(alpha[c]) putchar(c);
    }
        
    return 0;
}