#define _CRT_SECURE_NO_WARNINGS_

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <climits>
#define INF INT_MAX
using namespace std;

vector<vector<int> > e(210, vector<int>(210, INF));
int main() {
	//freopen("a.txt", "r", stdin);
	int N, M, K;
	scanf("%d%d", &N, &M);
	while (M--) {
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		e[a][b] = e[b][a] = d;
	}
	scanf("%d", &K);
	int residx, minD = INF;
	for (int i = 1; i <= K; i++) {
		int tot = 0, n;
		bool Connected = true;
		scanf("%d", &n);
		vector<int> path(n);
		vector<int> visited(N + 1, 0);
		for (int j = 0; j < n; j++) {
			scanf("%d", &path[j]);
			visited[path[j]] = 1;
			if (!Connected) continue;
			if (j != 0) {
				if (e[path[j-1]][path[j]] < INF) {
					tot += e[path[j - 1]][path[j]];
				}
				else {
					Connected = false;
				}
			}
		}
		if (!Connected) {
			printf("Path %d: NA (Not a TS cycle)\n", i);
		}
		else {
			bool all = find(visited.begin() + 1, visited.end(), 0) == visited.end();
			if (path.front() != path.back() || !all) {
				printf("Path %d: %d (Not a TS cycle)\n", i, tot);
			}
			else if (n != N + 1) {
				printf("Path %d: %d (TS cycle)\n", i, tot);
				if (tot < minD) {
					residx = i;
					minD = tot;
				}
			}
			else {
				printf("Path %d: %d (TS simple cycle)\n", i, tot);
				if (tot < minD) {
					residx = i;
					minD = tot;
				}
			}
		}
	}
	printf("Shortest Dist(%d) = %d", residx, minD);
	return 0;
}