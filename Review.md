## Algorithms

### 最短路径算法Dijkstra总结

##### 最短路径数

```C++
// 最短路径条数
vector<int> pathCnt(N);
pathCnt[S] = 1;
// in loop
if(d[u] + e[u][v] < d[v]) {
    pathCnt[v] = pathCnt[u];
}
else if(d[u] + e[u][v] == d[v]) {
    pathCnt[v] += pathCnt[u];
}
```

##### 保存所有最短路径

```c++
// 记录的是前驱
vector<vector<int> > path(N);
// in loop
if(d[u] + e[u][v] < d[v]) {
    path[v].clear();
    path.push_back(u);
}
else if(d[u] + e[u][v] == d[v]) {
    path.push_back(u);
}
```



##### 点带权

* 增加相应判断即可，PAT1003
* PAT1018也是点带权，但是判断方式不满足最优子结构，需要得到所有路径后，遍历选出最优

##### 边带权

* 增加相应判断即可，PAT1030

### 二分法

* PAT 1010
* PAT 1044
* PAT 1048，题中要求exact，所以可以调用binary_search
* `< ` 和 `<=`的区别就是lower_bound和upper_bound的区别

```c++
int left = 0, right = N, l, r;
while(left < right) {
  int mid = (left + right) / 2;
  if(v[mid] < val)
    left = mid + 1;
  else right = mid;
  l = left;// find the first >= val
}
left = 0; right = v1.size();
while(left < right) {
  int mid = (left + right) / 2;
  if(v[mid] <= val) 
    left = mid + 1;
  else right = mid;
  r = left;// left is the pos of the first key > val
}
```

* 二分法有两种写法

```c++
// 下标从0到N-1
int left = 0, right = N;
while(left < right) {
  int mid = (left + right) / 2;
  if(v[mid] < val)
    left = mid + 1;
  else right = mid;
  target = left;// find the first >= val
}

int left = 0, right = N-1;
while(left <= right) {
    int mid = (left + right) / 2;
    if(v[mid] < val)
        left = mid + 1;
    else right = mid - 1;
    target = left;// find the first >= val
}
```

### LCS

* sub-string必须是连续的PAT 1040

  $C[i][j] = C[i == 0?0:i-1][j ==0?0:j-1] + 1\quad when\quad s1[i]==s2[j]$

  $C[i][j] = 0\quad when \quad s1[i]\neq s2[j]$

* sub-sequence符合顺序即可

  ![1532590220540](assets/1532590220540.png)

* sub-sequence循序重复PAT 1045

  $C[i][j] = max(C[i][j-1], C[i-1][j])\quad when\quad s1[i] \neq s2[j]$

  $C[i][j] = max(C[i][j-1], C[i-1][j])+1\quad when\quad s1[i] = s2[j]$

### Tree Traversals

* PAT 1020
* PAT 1043
* PAT 1064  CBST
* PAT 1086
* PAT 1110 CBT，通过层序遍历判断是否是CBT
* PAT 1119 **<u>前序后序转中序</u>**
* PAT 1127
* PAT 1147

```c++
vector<int> in;
vector<int> pre;
vector<int> post;
vector<int> level;
```

* post + in TO level

```c++
// to_level(0, N-1, 0, N-1) to invoke
void to_level(int idx, int root, int left, int right) {
    if(left > right) return;
    level[idx] = post[root];
    int i;
    for(i = left; i < right; i++) {
        if(in[i] == post[root]) break;
    }
    to_level(2*idx+1, root - (right - i + 1), left, i - 1);// left
    to_level(2*idx+2, root - 1, i + 1, right);// right
}
```

* post + in TO pre

```c++
// to_pre(N-1, 0, N-1)
void to_pre(int root, int left, int right) {
    if(left > right) return;
    pre.push_back(post[root]);
    int i;
    for(i = left; i < right; i++) 
        if(in[i] == post[root]) break;
    to_pre(root - (right - i + 1), left, i - 1);
    to_pre(root - 1, i + 1, right);
}
```

* pre + in TO level

```c++
// to_level(0, N-1, 0, N-1) to invoke
void to_level(int idx, int root, int left, int right) {
    if(left > right) return;
    level[idx] = pre[root];
    int i;
    for(i = left; i < right; i++) 
        if(in[i] == pre[root]) break;
    to_level(2*idx + 1, root + 1, left, i - 1);
    to_level(2*idx + 2, root + (i - left + 1), i + 1, right);
}
```

* pre + in TO post

```c++
// to_post(0, 0, N-1);
void to_post(int root, int left, int right) {
    if(left > right) return;
    post.insert(post.begin(), pre[root]);
    int i;
    for(i = left; i < right; i++) 
        if(in[i] == pre[root]) break;
    to_post(root + (i - left + 1), i + 1, right);
    to_post(root + 1, left, i - 1);
}
```

* 也有两种写法，最右边的范围不同

```c++
// to_post(0, 0, N-1);
void to_post(int root, int left, int right) {
    if(left > right) return;
    post.insert(post.begin(), pre[root]);
    int i;
    for(i = left; i < right; i++) 
        if(in[i] == pre[root]) break;
    to_post(root + (i - left + 1), i + 1, right);
    to_post(root + 1, left, i - 1);
}
// to_post(0, 0, N);
void to_post(int root, int left, int right) {
    if(left >= right) return;
    post.insert(post.begin(), pre[root]);
    int i;
    for(i = left; i < right; i++) 
        if(in[i] == pre[root]) break;
    to_post(root + (i - left + 1), i + 1, right);
    to_post(root + 1, left, i);
}
```

* to_post也可以这样写

```c++
// to_post(0, 0, N);
void to_post(int root, int left, int right) {
    if(left >= right) return;
    int i;
    for(i = left; i < right; i++) 
        if(in[i] == pre[root]) break;
    to_post(root + 1, left, i);
    to_post(root + (i - left + 1), i + 1, right);
    post.push_back(pre[root]);
}
```

* 另一种改变元素顺序的写法，传递参数更少，不用计算根在哪

```c++
void convert(int left, int right) {
    if(left >= right) return;
    if(right - left == 1) {
        post.insert(post.begin(), in[left]);
        return;
    } else {
        int root = pre[left], i;
        for(i = left; i < right; i++) {
            if(in[i] == root) break;
        }
        pre.erase(pre.begin()+left);
        pre.insert(pre.begin() + i, root);//将root放在i位置
        post.insert(post.begin(), root);
        convert(i+1, right);
        convert(left, i);
    }
}
```

* 层序遍历简单写法

```c++
int j = 0;
while(level.size() != N) {
    Node *front = level[j++];
    if(front->left != NULL) res.push_back(front->left);
    if(front->right != NULL) res.push_back(front->right);
}
```

* 判断CBT

```c++
int i = 0;
for( ; res[i] != -1; i++) {
    res.push_back(Tree[res[i]].left);
    res.push_back(Tree[res[i]].right);
}
i == N ? Yes : No
```



### GCD

```c++
int gcd(int a, int b) // a > b, a != 0, b != 0
{
    if(a % b == 0) return b;
    gcd(b, a % b);
}
```

## Others

1. 循环中不能以变化的长度作为判断跳出条件
2. 当一个数很大的时候，要增加<0的判断，因为可能会溢出，如PAT1010
3. 有向图遍历每条边PAT1034
4. ```#define _CRT_SECURE_NO_WARNINGS```
5. PAT1068背包问题
6. PAT1071 Speech Patterns中通过读字符提取token，当遇到结束符的时候，token不为空，还需要在跳出循环后考虑token
7. DFS+回溯搜索最优路径模板

```c++
void DFS(int u) {
    tmp.push_back(u);
    if(达到计算条件) {
		...
    }
    for(auto v : path[u]) DFS(v);
    tmp.pop_back();
}
```

