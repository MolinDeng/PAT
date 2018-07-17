#include <cstdio>
#include <iostream>
#include <cmath>
#include <cctype>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define BET 2.0

using namespace std;

typedef pair<char, float> odd;

struct cmp {
    bool operator ()(odd a, odd b) {
        return a.second < b.second;
    }
};

priority_queue<odd, vector<odd>, cmp> game;

int main(int argc, char const *argv[])
{
    float pr = 0.65, W_odd, T_odd, L_odd;
    vector<char> res;
    for(int i = 0; i < 3; i++) {
        cin >> W_odd >> T_odd >> L_odd;
        game.push(odd('W', W_odd));
        game.push(odd('T', T_odd));
        game.push(odd('L', L_odd));
        res.push_back(game.top().first);
        pr *= game.top().second;
        while(!game.empty()) game.pop();
    }
    for(auto c : res) cout << c << " ";
    printf("%0.2f", (pr - 1) * BET);
    return 0;
}
