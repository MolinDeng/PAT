#define _CRT_SECURE_NO_WARNINGS_
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#define INF INT_MAX

using namespace std;
int N, M;
vector<int> pre, in, level, post;
map<int, bool> seen;
map<int, int> pos;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int x; scanf("%d", &x);
		in.push_back(x);
		pos[x] = i;
		seen[x] = true;
	}
		
	for (int i = 0; i < M; i++) {
		int x; scanf("%d", &x);
		pre.push_back(x);
		seen[x] = true;
	}
	while (N--) {
		int a, b;
		scanf("%d%d", &a, &b);
		bool flag1 = true;
		bool flag2 = true;
		if (a <= 0 || !seen[a]) flag1 = false;
		if (b <= 0 || !seen[b]) flag2 = false;
		if (!flag1 && !flag2)
			printf("ERROR: %d and %d are not found.\n", a, b);
		else if(!flag1)
			printf("ERROR: %d is not found.\n", a);
		else if (!flag2)
			printf("ERROR: %d is not found.\n", b);
		else {
			int posa = pos[a];
			int posb = pos[b];
			for (int i = 0; i < M; i++) {
				int posr = pos[pre[i]];
				if ((posr > posa && posr < posb) || (posr < posa && posr > posb)) {
					printf("LCA of %d and %d is %d.\n", a, b, pre[i]);
					break;
				}
				else if (posr == posa) {
					printf("%d is an ancestor of %d.\n", a, b);
					break;
				}
				else if (posr == posb) {
					printf("%d is an ancestor of %d.\n", b, a);
					break;
				}
			}
		}
	}
	return 0;
}