#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<long, long> Pair;

int main(int argc, char const *argv[])
{
    long N, M;
    Pair res;
    bool found = false;
    scanf("%ld %ld", &N, &M);     
    vector<long> money(N);
    for(int i = 0; i < N; i++) 
        scanf("%ld", &money[i]);

    sort(money.begin(), money.end());
    for(int i = 0; i < money.size() && money[i] <= M / 2; i++) {
        if(binary_search(money.begin()+i+1, money.end(), M - money[i])) {
            res = Pair(money[i], M - money[i]);
            found = true;
            break;
        }
    }
    if(found) printf("%ld %ld", res.first, res.second);
    else printf("No Solution");
    return 0;
}
