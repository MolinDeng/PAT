# PAT Advanced Level

* TODO:
  * 1026 re-define data structure
  * 1034 ...
  * LC subString & LC subSequence 总结
  * 1039 学姐的做法
  * 1047 problem???
* Goal: ALL AC

## 1001(字符串处理)

* string operation using insert

* insert function cannot accept *reverse_iterator*

  * reverse the whole string, then do it as normal 

  * convert *reverse_it* to *it* (***not try, maybe not work***)

    ```c++
    str.insert(r_iter.base(), 1, ',');
    ```

* for each iteration, we should update iterator

  ```c++
  iter = str.insert(iter, ',');
  ```

* http://www.cplusplus.com/reference/string/string/insert/

## 1002(两路merge)

* two-way merge

## 1003(Dijkstra算法 点带权)

* my code using priority queue 22/25

* using Dij Algorithm to find shortest path

* using priority queue to find vertex to visit

  * before push into queue, we need to find if the id in queue

  * self-defined cmp function for determining priority

    ```c++
    struct mycmp {
        bool operator()(int i, int j) {
            return s_dist[i] > s_dist[j];
        }
    };
    ```

* code from https://www.liuchuo.net/archives/2359 AC

* using vector<vector<int\>>  store path

  ```c++
  if(s_dist[curr] + dist[curr][i] < s_dist[i]) {
      s_dist[i] = s_dist[curr] + dist[curr][i];
      team_cnt[i] = team_cnt[curr] + teams[i];
      path_cnt[i] = path_cnt[curr];
      path[i].clear();
      path[i].push_back(curr);
  }
  else if(s_dist[curr] + dist[curr][i] == s_dist[i]) {
      if(team_cnt[i] < teams[i] + team_cnt[curr])
        	team_cnt[i] = teams[i] + team_cnt[curr];
      path_cnt[i] += path_cnt[curr];
      path[i].push_back(curr);
  }
  ```

  

## 1004(DFS, BFS, 层序遍历)

* simple DFS

* using map to represent tree

* Idea from https://blog.csdn.net/iaccepted/article/details/21289205

* can be done by BFS

  * need to record level info. when input

    ```c++
    level[sid] = level[id] + 1;
    ```


## 1005(字符串处理)

* string operation

## 1006(模拟，优先队列应用)

* using map&priority_queue

## 1007(DP，最大连续子序列之和)

* online algorithm O(N)

```c++
else if(curr_sum > max_sum || (curr_sum == 0 && end == N - 1)) {
    ...
}
```

* **curr_sum == 0 && end == N - 1** is very important, for input as below:

  ```shell
  >6
  >0 0 0 0 -1 0
  ```

  If this condition is omitted, the *end* is 5(that is N -1), which is incorrect.

## 1008(数学问题)

* simple

## 1009(模拟，map应用)

* using map

## 1010(二分法)

* simple ***for*** iteration cannot pass test point 7(large sum and out of time)

* binary search must consider N2_d < 0

  This situation happens when N1_d is very large, when computing N2_d, N2_d may exceeding the upper bound and become negative.(e.g. ***right*** is super large , so ***mid*** is also super large, calculate ***pow()*** can be super super large)

```c++
if(N2_d > N1_d || N2_d < 0) break;
...
else if(N2_d > N1_d || N2_d < 0) right = mid - 1;
...
```

* idea from https://www.cnblogs.com/weedboy/p/7244819.html

## 1011(查找元素，优先队列应用)

* priority queue

## 1012(排序)

* sort grades rather than sort ID
* 88 87 87 55，the rank is 1,2,2,4

## 1013(图的遍历，统计连通分量的个数，DFS，Disjoint Set)

* Find the # of sub-connected component连通分量的个数
* DFS or BFS

## 1014(queue应用，模拟)

* defining a good data structure is vital important.

## 1015(素数，计算reverse number)

* is_prime
* calculate reverse number

## 1016(排序)

* a good data structure
* understanding ***no two records for the same customer have the same time***, 所以按时间排序后，offline时间和它正前方的online时间一定是一对

## 1017(queue的应用，模拟)

* the same as 1014

## 1018(Dijstra 算法，DFS，点带权，判定方法不同，多路径储存)

* test 7 not pass
* 思路和1003类似，但是更正确的做法是储存路径，最后模拟找到最优路径，因为该问题不满足最优子结构
* 但是我的方法只有test 7没过呀
* AC code https://www.liuchuo.net/archives/2373

## 1019(回文数，字符串处理)

* simple

## 1020(树的遍历，之间的转换)

* the relationship between three traversal order

## 1021(图的遍历，DFS，计算连通分量的个数，Disjoint set)

* 通过DFS和Disjoint set都可判断连通分量的个数

* 而找到最深根有非常tricky的做法, 不用对每个节点DFS计算深度

  > **先从一个结点dfs后保留最高高度拥有的结点们，然后从这些结点中的其中任意一个开始dfs得到最高高度的结点们，这两个结点集合的并集就是所求** 

* Idea from https://www.liuchuo.net/archives/2348

## 1022(map应用)

* map的简单应用
* 对于连续getline()操作
  * 连续getline()操作之前一定要getchar()吃掉回车
  * 连续getline()操作之间没有其他输入输出则不用getchar()
  * 连续getline()操作之间有cout/printf输出'\n'，则不用getchar()

## 1023(大整数运算，字符串操作)

* 大整数运算，通过string以及字符操作来实现

* 判断方法tricky

  ```c++
  sort(origin.begin(), origin.end());
  sort(res_copy.begin(), res_copy.end());
  if(res_copy == origin) //Yes
  ```

## 1024(大整数运算，字符串实现)

* 大整数运算，通过string以及字符操作来实现

## 1025(排序)

* Test 3 timeout可能原因是使用map映射id和各种信息，红黑树查找需要时间，不如vector直接快

## 1026(模拟，queue应用，数据结构设计)

* TODO: re-define data structure, and simulate the queueing

## 1027(进制转换)

* easy

## 1028(排序)

* scanf&printf is faster

## 1029(排序，边读边排)

* 第一个队列存好后，把第二个队列边读，边和第一个队列比较，选择出队。这样可以不用一次存完第二个队列，解决超内存的问题.
* Idea from https://www.liuchuo.net/archives/2248

## 1030(Dijkstra算法 + DFS，最短路径，边带权)

* vector\<int> path储存前驱

## 1031(字符串操作，数学问题)

* $2x+y-2=N\to x = \frac{N+2-y}{2}$, 目的是为了$y-x$大于0且最小，$y-x=\frac{3y-N-2}{2}$只能等于$i,i\in\{0,1,2,..\}$，遍历i，解得y即可

## 1032(数组形式链表)

## 1033(贪心)

## 1034

## 1035(字符串操作)

* while((c = getchar()) != '\n')

## 1036(排序、查找)

* online 边读边比较

## 1037(排序，求和)

* 忽略0

## 1038(贪心？字符串比较)

* cmp: return a + b < b + a
* 满足最优子结构

## 1039(映射，大数据查找)

* 简单map会超时，改用vector执行映射，首先要建立ID与下标的关系——getid()
* getid()中pow函数会降低效率...

## 1040(DP最长公共子串LC-Substring)

* TODO：LC substring & LC subsequence

* 转移方程

  $C[i][j] = C[i == 0?0:i-1][j ==0?0:j-1] + 1\quad when\quad s1[i]==ss2[j]$

  $C[i][j] = 0\quad when \quad s1[i]\neq s2[j]$

## 1041(queue应用，Hash散列)

* 第一次见到的入队，出现过两次以上的标记为seen，再从队列顶部查看，如果seen，则出队，找到第一个非seen标记即为所求
* TODO：理解此方法https://www.liuchuo.net/archives/2139

## 1042(排序)

* 计算最终的位置即可

## 1043(树遍历以及之间的关系)

* 通过前序构建后序，并通过结构判断是否是BST

## 1044(二分法，查找)

* 遍历起始下标i，找到最小的j，使得i-j的总价钱是正好>=M
* 通过二分加速
* 储存diamond方式与1046类似，降低空间复杂度

## 1045(LC-Subsequence)

![1532590220540](assets/1532590220540.png)

* 此题是LCS的变体，在保持顺序的前提下，允许重复

  $C[i][j] = max(C[i][j-1], C[i-1][j])\quad when\quad s1[i] \neq s2[j]$

  $C[i][j] = max(C[i][j-1], C[i-1][j])+1\quad when\quad s1[i] = s2[j]$

## 1046(模拟，online边读入边计算)

* 只需要储存某一个定点到其他所有点的距离，任意两点的距离都是abs(定点到这两点的距离之差)
  * 注意顺序储存
* 最后比较这个距离和另一条路的距离(环路总距离 - 一条路的距离)

## 1047(1039的逆过程，大数据查找)

* TODO：test3 not AC

## 1058(进制转换)

* long long
* Galleon的base取LLONG_MAX

## 1065(大数相加，判断越界)

* MAX + MAX = -2
* MIN + MIN= 0