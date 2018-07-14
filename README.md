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

