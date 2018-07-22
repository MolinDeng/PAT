#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <set>

using namespace std;

struct Book_info {
    char ID[8];
    char title[81];
    char author[81];
    vector<string> keywords;
    char publisher[81];
    int year;
};

map<string, set<string> > kw2ID;
map<string, set<string> > title2ID;
map<string, set<string> > autor2ID;
map<string, set<string> > pub2ID;
map<int, set<string> > year2ID;

int main() {
    int N, M;
    scanf("%d", &N);
    Book_info bi;
    while(N--) {
        getchar();//吃掉cin >> bi.year时回车
        string tok;
        char kws[60];
        cin.getline(bi.ID, 8);
        cin.getline(bi.title, 81);
        cin.getline(bi.author, 81);
        cin.getline(kws, 60);
        stringstream str(kws);
        bi.keywords.clear();
        while(getline(str, tok, ' ')) 
            bi.keywords.push_back(tok);
        cin.getline(bi.publisher, 81);
        cin >> bi.year;
        for(auto kw : bi.keywords) kw2ID[kw].insert(bi.ID);
        title2ID[bi.title].insert(bi.ID);
        autor2ID[bi.author].insert(bi.ID);
        pub2ID[bi.publisher].insert(bi.ID);
        year2ID[bi.year].insert(bi.ID);
    }
    scanf("%d", &M);
    getchar();//eat enter
    while(M--) {
        char query[100];
        cin.getline(query, 100);
        int qID = query[0] - '0';
        char *qKey = query + 3;
        printf("%d: %s\n", qID, qKey);
        switch(qID) {
            case 1:
                if(!title2ID[qKey].empty())
                    for(auto id : title2ID[qKey])
                        printf("%s\n", id.c_str());
                else printf("Not Found\n");
                break;
            case 2:
                if(!autor2ID[qKey].empty())
                    for(auto id : autor2ID[qKey])
                        printf("%s\n", id.c_str());
                else printf("Not Found\n");
                break;
            case 3:
                if(!kw2ID[qKey].empty())
                    for(auto id : kw2ID[qKey])
                        printf("%s\n", id.c_str());
                else printf("Not Found\n");
                break;
            case 4:
                if(!pub2ID[qKey].empty())
                    for(auto id : pub2ID[qKey])
                        printf("%s\n", id.c_str());
                else printf("Not Found\n");
                break;
            case 5:
                int y = atoi(qKey);
                if(!year2ID[y].empty())
                    for(auto id : year2ID[y])
                        printf("%s\n", id.c_str());
                else printf("Not Found\n");
                break;
        }
    }
    return 0;
}