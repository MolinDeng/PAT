# C++ STL&Algorithms

## 优先队列

* empty(), pop(), push(), size(), top()
* 默认优先队列中，优先级最高的先出队
* list container 不能实现queue，可用vector、deque
* http://www.cplusplus.com/reference/queue/priority_queue/priority_queue/

```c++
#include <queue>
#include <functional>//for greater
priority_queue<int/string> q;//从大到小出队
priority_queue<int, vector<int>, greater<int> > q;//从小到大出队
priority_queue<int, vector<int>, less<int> > q;//大到小
//自定义cmp优先级
struct cmp {
	bool operator () (int x, int y) {
		return x > y;//最小值优先
	}
}
priority_queue<int, vector<int>, cmp> q;
//结构内重载比较运算符，自定优先级
struct node {
	int x;
    bool operator < (const node &a) const {
        return x < a.x//最大值优先
    }
}
priority_queue<node> q;
```

## Map

* map中按照key升序排列，不可以使用sort

```c++
//插入
M.insert(pair<int, string>(12,"asd"));
M.insert(make_pair(12,"asd"));
M.insert(map<int, string>::value_type(12,"asd"));
M[12] = "asd";
```

* 查找find返回iterator,未找到返回.end()
* 遍历操作

```c++
//正反迭代器+数组遍历
for(int i = 1; i <= M.size(); i++)
  cout << M[i] << endl;
```

* 利用数组下标形式新建修改item

```c++
map<int, float> res;
res[1] += 10;// insert <1,10>
res[1] += 10;// alter <1,20>
res[3];// insert <3,0>
cout << res[2] << endl;// res[2] = 0
cout << res.size();// size is three
```

## Set

* set中元素默认升序排列

## Disjoint Set

* 数组或者链表实现

```c++
vector<int> DS(N);// init DS(N, -1)
int cnt;// # of disjoint set
void init() {
  cnt = N;
  fiil(DS.begin(), DS.end(), -1);
}
// 路径压缩
int find(int x) {
  if(DS[x] < 0) return;
  return DS[x] = find(DS[x]);
}
// Union by Height，也可以是其他标准，目的是减少高度，尽量平衡
// 此处的高度为一个上界，是高度的负值再减1，储存在DS[root]中
void union_by_H(int r1, int r2) {
  if(find(r1) == find(r2)) return;
  if(DS[r2] < DS[r1]) //r2 is deeper
    s[r1] = r2;
  else {
    if(DS[r1] == DS[r2]) 
      s[r1]--;
   	s[r2] = r1;
  }
  cnt--;
}
```



## 字符串分词

```c++
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main() {
  	stringstream str("abcd efg kk dd ");
  	string tok;
  	while(getline(str, tok, ' ')) {
    		cout << tok << endl;
  	}
  	return 0;
}
```

* stringstream的拷贝构造可以是string、char*