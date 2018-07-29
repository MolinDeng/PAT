#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;
int  N;
void convert(string& A) {
    int first_pos = 0, point_pos = 0, i, c;
    bool found_first = false;
    bool found_point = false;
    for(i = 0; (c = getchar()) != '\n' && c != ' ';) {
        if(!found_first && c != '.' && c != '0') {
            found_first = true;
            first_pos = i;
        }
        if(found_first && c != '.' && A.length() < N) 
            A.push_back(c);
        if(!found_point) point_pos++;
        if(c == '.') {
            point_pos = i;
            found_point = true;
            continue;// 这里i不用++了，因为找第一个非0数字时，'.'不算数字，不需要计数
        }
        i++;
    }
    int rest = N - A.length();
    for(i = 0; i < rest; i++) A = A + "0";
    if(atoi(A.c_str()) == 0) A = "0." + A + "*10^" + "0";// 0 = 0.00..0*10^0
    else A = "0." + A + "*10^" + to_string(point_pos-first_pos);
}
int main() {
    scanf("%d ", &N);
    string A, B;
    convert(A);
    convert(B);
    cout << (A==B ? "YES " + A : "NO " + A + " " + B);
    return 0;
}