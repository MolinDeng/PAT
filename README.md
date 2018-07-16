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

