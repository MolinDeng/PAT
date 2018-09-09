#define _CRT_SECURE_NO_WARNINGS_
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	//freopen("a.txt","r",stdin);
	int N;
	scanf("%d", &N);
	vector<int> said(N + 1), res;
	vector<int> person(N + 1, 1); // 1 human, 0 w
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		said[i] = x;
	}
	bool found = false;
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			fill(person.begin(), person.end(), 1);
			person[i] = person[j] = 0;
			int wliecnt = 0;
			int hliecnt = 0;
			for (int k = 1; k <= N; k++) {
				int who = said[k];
				if (person[k] == 0) {
					if (wliecnt == 2) {
						break;
					}
					if ((who < 0 && person[abs(who)] == 0) || (who > 0 && person[abs(who)] == 1)) {
						continue;
					}
					else if ((who < 0 && person[abs(who)] == 1) || (who > 0 && person[abs(who)] == 0)) {
						wliecnt++;
					}
				}
				if (person[k] == 1) {
					if (hliecnt > 1) {
						break;
					}
					if ((who < 0 && person[abs(who)] == 0) || (who > 0 && person[abs(who)] == 1)) {
						continue;
					}
					else if ((who < 0 && person[abs(who)] == 1) || (who > 0 && person[abs(who)] == 0)) {
						hliecnt++;
					}
				}
			}
			if (wliecnt == 1 && hliecnt == 1) {
				res.push_back(i);
				res.push_back(j);
				found = true;
				break;
			}
		}
		if (found) break;
	}
	if (found) cout << res[0] << " " << res[1];
	else cout << "No Solution";
	return 0;
}