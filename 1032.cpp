#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

typedef pair<int, bool> Node;
Node node[100000];

int main() {
    int head1, head2, N;
    scanf("%d %d %d", &head1, &head2, &N);
    while(N--) {
        int a, b; 
        char c;
        scanf("%d %c %d", &a, &c, &b);
        node[a].first = b;
    }
    for(int i = head1; i != -1; i = node[i].first) 
        node[i].second = true;
    for(int i = head2; i != -1; i = node[i].first) {
        if(node[i].second) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}