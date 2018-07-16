#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<string, pair<string, string> > records;

struct si_cmp {
    bool operator ()(string ID1, string ID2) {
        return records[ID1].first > records[ID2].first;
    }
};

struct so_cmp {
    bool operator ()(string ID1, string ID2) {
        return records[ID1].second < records[ID2].second;
    }
};

priority_queue<string, vector<string>, si_cmp> sign_in;
priority_queue<string, vector<string>, so_cmp> sign_out;

int main(int argc, char const *argv[])
{
    int M;
    scanf("%d", &M);
    while(M--) {
        string ID, SI, SO;
        cin >> ID >> SI >> SO;
        records[ID] = pair<string, string>(SI,SO);
        sign_in.push(ID);
        sign_out.push(ID);
    }
    cout << sign_in.top() << " " << sign_out.top();
    return 0;
}
