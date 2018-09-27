#include <iostream>
#include <vector>
#include <string>

using namespace std;

void makenxt(string& P, vector<int>& nxt) {
    int len = P.length();
    for(int i = 1, l = 0; i < len; i++) {
        while(l > 0 && P[l] != P[i])
            l = nxt[l-1];
        if(P[l] == P[i]) l++;
        nxt[i] = l;
    }
}

void kmp(string& S, string& P) {
    vector<int> nxt(P.length(), 0);
    makenxt(P, nxt);
    for(auto i : nxt) cout << i << " ";
    cout << endl;
    for(int i = 0, j = 0; i < S.length(); i++) {
        while(j > 0 && P[j] != S[i])
            j = nxt[j-1];
        if(P[j] == S[i])
            j++;
        if(j == P.length()) {
            cout << "Pattern starts with idx: " << i-P.length()+1 << endl;
            return;
        }
    }
    cout << "Not Found" << endl;
}
int main() {
    string S = "BBC ABCDAB ABCDABCDABDE";
    string P = "ABCDABD";
    kmp(S, P);
    return 0;
}