# PAT Advanced Level

* Goal: ALL AC

## 1001

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

## 1002

* two-way merge

## 1003

* 22/25

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

* TODO: find bugs

## 1004

* simple DFS

* using map to represent tree

* Idea from https://blog.csdn.net/iaccepted/article/details/21289205

* can be done by BFS

  * need to record level info. when input

    ```c++
    level[sid] = level[id] + 1;
    ```


## 1005

* string operation

## 1006

* using map&priority_queue

## 1007

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

## 1008

* simple

## 1009