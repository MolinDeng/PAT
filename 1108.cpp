#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, cnt = 0;
    string in;
    bool invalid = true;
    double sum = 0;
    scanf("%d", &N);
    while(N--) {
        cin >> in;
        int p_cnt = 0, m_cnt = 0;
        bool flag = false;
        for(int i = 0; i < in.length(); i++) {
            if(in[i] == '.') {
                p_cnt++;
                if(in.length() - i > 3 || p_cnt > 1) {
                    flag = true;
                    break;
                }
            }
            else if(in[i] == '-') {
                m_cnt++;
                if(m_cnt > 1) {
                    flag = true;
                    break;
                }
            }
            else if(!isdigit(in[i])) {
                flag = true;
                break;
            }
        }
        if(flag) printf("ERROR: %s is not a legal number\n", in.c_str());
        else if(stod(in) > 1000 || stod(in) < -1000) 
            printf("ERROR: %s is not a legal number\n", in.c_str());
        else {
            sum += stod(in);
            cnt++;
            invalid = false;
        }
    }
    if(invalid) printf("The average of 0 numbers is Undefined");
    else {
        if(cnt == 1) printf("The average of %d number is %.2lf", cnt, sum/cnt);
        else printf("The average of %d numbers is %.2lf", cnt, sum/cnt);
    }
    return 0;
}