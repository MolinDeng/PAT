#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d %d", &a, &b);
    int output = a + b;
    if (output <= 999 && output >= -999)
        printf("%d", output);
    else {
        bool flag = false;
        if (output < 0) flag = true; 
        string str = to_string(abs(output));
        reverse(str.begin(),str.end());
        int len = str.length();
        for (auto iter = str.begin()+3; iter < str.end(); iter += 4)
            iter = str.insert(iter, ',');
        reverse(str.begin(),str.end());
        if(flag) str.insert(str.begin(), 1, '-');
        printf("%s",str.c_str());
    }

    return 0;
}
