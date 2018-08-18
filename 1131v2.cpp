#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> v(10000);
int visit[10000], minCnt, minTransfer, start, end1;
unordered_map<int, int> line;
vector<int> path, tempPath, tempLine, resLine;

void dfs(int node, int cnt, int lineno) {
    if (node == end1) {
        tempPath.push_back(node);
        if(cnt < minCnt || (cnt == minCnt && tempPath.size() < minTransfer)) {
            minCnt = cnt;
            minTransfer = tempPath.size();
            path = tempPath;
            resLine = tempLine;
        }
        tempPath.pop_back();
        return;
    }
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            int currline = line[node*10000 + v[node][i]];
            visit[v[node][i]] = 1;
            if(lineno != currline) {
                tempPath.push_back(node);
                tempLine.push_back(currline);
            }
            dfs(v[node][i], cnt + 1, currline);
            visit[v[node][i]] = 0;
            if(lineno != currline) {
                tempPath.pop_back();
                tempLine.pop_back();
            }
        }
    }
}
int main() {
    int n, m, k, pre, temp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre*10000+temp] = line[temp*10000+pre] = i;
            pre = temp;
        }
    }
    scanf("%d", &k);
    while(k--) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        dfs(start, 0, 0);
        printf("%d\n", minCnt);
        for(int i = 1; i < path.size(); i++) 
            printf("Take Line#%d from %04d to %04d.\n", resLine[i-1], path[i-1], path[i]);
    }
    return 0;
}