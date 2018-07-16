#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char const *argv[])
{
    string digits;
    int sum = 0;
    cin >> digits;
    int len = digits.length();
    while(len--) 
        sum += digits[len] - '0';
    string ssum = to_string(sum);
    for(int i = 0; i < ssum.length(); i++) {
        switch(ssum[i]) {
            case '0': printf("zero"); break;
            case '1': printf("one"); break;
            case '2': printf("two"); break;
            case '3': printf("three"); break;
            case '4': printf("four"); break;
            case '5': printf("five"); break;
            case '6': printf("six"); break;
            case '7': printf("seven"); break;
            case '8': printf("eight"); break;
            case '9': printf("nine"); break;
        }
        if(i < ssum.length() - 1)
            printf(" ");
    }
    return 0;
}
