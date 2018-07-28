#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>

#define lowbit(i) ((i) & (-i))

using namespace std; 
const int maxn = 100010;
int c[maxn], N;
stack<int> S;

int getsum(int pos) {
    int sum = 0;
    for( ; pos > 0; sum += c[pos], pos -= lowbit(pos));
    return sum;
}

void update(int pos, int val) {
    for( ; pos <= maxn; c[pos] += val, pos += lowbit(pos));
}
void PeekMedian() {
    int left = 1, right = maxn, mid, K = (S.size() + 1) / 2;
    while(left < right) {
        mid = (left + right) / 2;
        if(getsum(mid) >= K)
            right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
    scanf("%d", &N);
    char op[11];
    while(N--) {
        scanf("%s", op);
        switch(op[1]) {
            case 'o':
                if(S.empty()) printf("Invalid\n");
                else {
                    update(S.top(), -1);
                    printf("%d\n", S.top());
                    S.pop();
                }
                break;
            case 'e':
                if(S.empty()) printf("Invalid\n");
                else 
                    PeekMedian();
                break;
            case 'u':
                int x;
                scanf("%d", &x);
                S.push(x);
                update(x, 1);
        }
    }
    return 0;
}