#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
struct Node {
    string o;
    int left, right;
    Node() { left = right = -1;}
};
vector<Node> Tree(100);
string res;
void inorder(int root) {
    if(Tree[root].left == -1 && Tree[root].right == -1) res = res + Tree[root].o;
    else {
        res = res + "(";
        if(Tree[root].left != -1) 
            inorder(Tree[root].left);
        res = res + Tree[root].o;
        if(Tree[root].right != -1) 
            inorder(Tree[root].right);
        res = res + ")";
    }
}
int main() {
    int N, root;
    scanf("%d", &N);
    vector<bool> seen(N+1, false);
    for(int i = 1; i <= N; i++) {
        cin >> Tree[i].o >> Tree[i].left >> Tree[i].right;
        if(Tree[i].left != -1) seen[Tree[i].left] = true;
        if(Tree[i].right != -1) seen[Tree[i].right] = true;
    }
    for(int i = 1; i <= N; i++) {
        if(!seen[i]) {
            root = i;
            break;
        }
    }
    inorder(root);
    if(res.length() == 1) cout << res;
    else cout << string(res.begin()+1, res.end()-1);
    return 0;
}