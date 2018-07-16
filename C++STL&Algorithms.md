# C++ STL&Algorithms

## 优先队列

* empty(), pop(), push(), size(), top()
* 默认优先队列中，优先级最高的先出队
* list container 不能实现queue，可用vector、deque
* http://www.cplusplus.com/reference/queue/priority_queue/priority_queue/

```c++
#include <queue>
#include <functional>//for greater
priority_queue<int> q;//从大到小出队
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