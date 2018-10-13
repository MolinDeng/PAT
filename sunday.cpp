#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> shift;

void get_shift(string& P) {
    int pLen = P.length();
    shift.resize(256, pLen+1);
    for(int i = 0; i < pLen; ++i) { 
        shift[P[i]] = pLen - i; 
        cout << P[i] << ": " << shift[P[i]] << endl;
    }
}

void Sunday(string& S, string& P) {
    get_shift(P);
    int sLen = S.length(), pLen = P.length();
    for(int i = 0, j = 0; i + pLen < sLen; i += shift[S[i + pLen]], j = 0) {
        while(j < pLen && S[i+j] == P[j]) j++;
        if(j == pLen) {
            cout << "Pattern starts with idx: " << i << endl;
            return;
        }
    }
    cout << "Not Found" << endl;
}
int main(int argc, char const *argv[])
{
    string S = "search substring";
    string P = "substr";
    Sunday(S, P);
    return 0;
}
