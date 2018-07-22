#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
    int C, cnt = 3;
    string MC = "#";    
    while(cnt--) {
        scanf("%d", &C);
        int x1 = C / 13;
        int x2 = C % 13;
        MC = MC + (x1 == 10 ? "A": (x1 == 11 ? "B": (x1 == 12 ? "C": to_string(x1))));
        MC = MC + (x2 == 10 ? "A": (x2 == 11 ? "B": (x2 == 12 ? "C": to_string(x2))));
    }
    cout << MC;
    return 0;
}