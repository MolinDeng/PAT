#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string A1, A2, B1, B2;
    cin >> A1 >> A2 >> B1 >> B2;
    string DAY;
    int HH, MM, cnt = 0;
    for(int i = 0; i < min(A1.length(), A2.length()); i++) {
        if(cnt == 1 && A1[i] == A2[i] && (isdigit(A1[i]) || (A1[i] >= 'A' && A1[i] <= 'N'))) {
            HH = (isdigit(A1[i])? A1[i] - '0' : A1[i] - 'A' + 10);
            break;
        }
        if(cnt == 0 && A1[i] == A2[i] && A1[i] >= 'A' && A1[i] <= 'G') {
            switch(A1[i]) {
                case 'A': DAY = "MON"; break;
                case 'B': DAY = "TUE"; break;
                case 'C': DAY = "WED"; break;
                case 'D': DAY = "THU"; break;
                case 'E': DAY = "FRI"; break;
                case 'F': DAY = "SAT"; break;
                case 'G': DAY = "SUN"; break;
            }
            cnt = 1;
        }   
    }
    for(int i = 0; i < min(B1.length(), B2.length()); i++) {
        if(B1[i] == B2[i] && isalpha(B1[i])) {
            MM = i;
            break;
        }
    }
    printf("%s %02d:%02d", DAY.c_str(), HH,  MM);
    return 0;
}