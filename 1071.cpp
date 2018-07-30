#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>
#include <cctype>

using namespace std;

map<string, int> freq;

int main() {
    char c, pre_c = EOF;
    string token, res;
    int max_freq = 0;
    map<string, int> freq;
    while((c = getchar()) != '\n') {
        if(!isalnum(c)) {
            if(isalnum(pre_c)) {
                freq[token]++;
                if(freq[token] > max_freq) {
                    max_freq = freq[token];
                    res = token;
                } else if(freq[token] == max_freq)
                    res = (token < res ? token : res);
                token.clear();
            }
        }
        else {
            c = isalpha(c) ? tolower(c) : c;
            token.push_back(c);
        }
        pre_c = c;
    }
    if(!token.empty()) {
        freq[token]++;
        if(freq[token] > max_freq) {
            max_freq = freq[token];
            res = token;
        } else if(freq[token] == max_freq)
            res = (token < res ? token : res);
    }
    cout << res << " " << freq[res];
    return 0;
}