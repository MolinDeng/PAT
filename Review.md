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

##### 点带权

	增加相应判断即可，PAT1003

### 二分法

* PAT 1010
* 

## Others

1. 循环中不能以变化的长度作为判断跳出条件
2. 当一个数很大的时候，要增加<0的判断，因为可能会溢出，如PAT1010