#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef pair<string, string> User;

int main(int argc, char const *argv[])
{
    int N;    
    vector<User> users;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        char acc[10], c;
        string pw;
        bool modified = false;
        scanf("%s", acc);
        pw.clear();
        getchar();
        while((c = getchar()) != '\n') {
            char cc = (c == '1' ? '@': (c == '0' ? '%': (c == 'l' ? 'L': (c == 'O' ? 'o': c))));
            pw.push_back(cc);
            if(cc != c) modified = true;
        }
        if(modified) users.push_back(User(acc, pw));
    }
    if(users.empty() && N == 1)
        printf("There is 1 account and no account is modified");
    else if(users.empty()) 
        printf("There are %d accounts and no account is modified", N);
    else {
        printf("%d\n", users.size());
        for(auto u : users) printf("%s %s\n", u.first.c_str(), u.second.c_str());
    }
    return 0;
}
