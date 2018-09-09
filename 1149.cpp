#define _CRT_SECURE_NO_WARNINGS_
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > v(100000, vector<int>());
vector<int> enabled(100000, 1);
int main() {
	//freopen("a.txt", "r", stdin);
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	while(K--) {
		int n;
		bool flag = false;
		scanf("%d", &n);
		fill(enabled.begin(), enabled.end(), 1);
		for (int i = 0; i < n; i++) {
			int id;
			scanf("%d", &id);
			if (flag) continue;
			if (enabled[id] == 1) {
				enabled[id] = 0;
				for (auto cid : v[id])
					enabled[cid] = 0;
			}
			else {
				flag = true;
			}
		}
		cout << (flag ? "No" : "Yes") << endl;
	}
	return 0;
}