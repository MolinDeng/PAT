#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

void adjust(vector<int> &v, int i, int len) {
    for(int k = 2*i + 1; k < len; k = 2*k+1) {
        if(k+1 < len && v[k] < v[k+1])
            k++;
        if(v[i] < v[k]) {
            swap(v[i], v[k]);
            i = k;
        }
    }
}

void heap_sort(vector<int> &v) {
    for(int i = (v.size() / 2) - 1; i>=0; i--)
        adjust(v, i, v.size());
    for(int i = v.size() - 1; i > 0; i--) {
        swap(v[0],v[i]);
        adjust(v, 0, i);
    }
}
int main() {
    vector<int> v = {4, 3, 6, 7, 8, 9, 5, 1, 2, 0};
    heap_sort(v);
    for(auto i : v) 
        cout << i << " ";
    return 0;
}