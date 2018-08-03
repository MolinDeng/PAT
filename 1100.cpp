#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <map>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    while(N--) {
        string num;
        getline(cin, num);
        if(isdigit(num[0])) {
            int n = stoi(num);
            vector<string> res;
            if(n == 0) {
                cout << "tret" << endl;
                continue;
            }
            int q = n / 13;
            switch(q) {
                case 0: break;
                case 1: res.push_back("tam");break;
                case 2: res.push_back("hel");break;
                case 3: res.push_back("maa");break;
                case 4: res.push_back("huh");break;
                case 5: res.push_back("tou");break;
                case 6: res.push_back("kes");break;
                case 7: res.push_back("hei");break;
                case 8: res.push_back("elo");break;
                case 9: res.push_back("syy");break;
                case 10: res.push_back("lok");break;
                case 11: res.push_back("mer");break;
                case 12: res.push_back("jou");break;
            }
            n %= 13;
            switch(n) {
                case 0: break;
                case 1: res.push_back("jan");break;
                case 2: res.push_back("feb");break;
                case 3: res.push_back("mar");break;
                case 4: res.push_back("apr");break;
                case 5: res.push_back("may");break;
                case 6: res.push_back("jun");break;
                case 7: res.push_back("jly");break;
                case 8: res.push_back("aug");break;
                case 9: res.push_back("sep");break;
                case 10: res.push_back("oct");break;
                case 11: res.push_back("nov");break;
                case 12: res.push_back("dec");break;
            }
            for(int i = 0; i < res.size(); i++) {
                if(i != 0) printf(" ");
                printf("%s", res[i].c_str());
            }
            cout << endl;
        }
        else {
            stringstream ss(num);
            string tok;
            int res = 0;
            while(getline(ss, tok, ' ')) {
                if(tok == "tret") res = 0;
                else if(tok == "jan") res += 1;
                else if(tok == "feb") res += 2;
                else if(tok == "mar") res += 3;
                else if(tok == "apr") res += 4;
                else if(tok == "may") res += 5;
                else if(tok == "jun") res += 6;
                else if(tok == "jly") res += 7;
                else if(tok == "aug") res += 8;
                else if(tok == "sep") res += 9;
                else if(tok == "oct") res += 10;
                else if(tok == "nov") res += 11;
                else if(tok == "dec") res += 12;
                else if(tok == "tam") res += 1*13;
                else if(tok == "hel") res += 2*13;
                else if(tok == "maa") res += 3*13;
                else if(tok == "huh") res += 4*13;
                else if(tok == "tou") res += 5*13;
                else if(tok == "kes") res += 6*13;
                else if(tok == "hei") res += 7*13;
                else if(tok == "elo") res += 8*13;
                else if(tok == "syy") res += 9*13;
                else if(tok == "lok") res += 10*13;
                else if(tok == "mer") res += 11*13;
                else if(tok == "jou") res += 12*13;
            }
            cout << res << endl;
        }
    }
    return 0;
}