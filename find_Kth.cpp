#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;
// find k-th smaller
void find_Kth_s(vector<int> &v, int K, int left, int right) {
    int pivot = v[left];
    int i = left, j = right;
    while(i < j) {
        while(i < j && v[j] >= pivot) j--;
        if(i < j) v[i++] = v[j];
        while(i < j && v[i] < pivot) i++;
        if(i < j) v[j--] = v[i];
    }
    v[i] = pivot;
    if(K-1 < i) find_Kth_s(v, K, left, i-1);
    if(K-1 > i) find_Kth_s(v, K, i+1, right);
    return;
}

// find k-th bigger
void find_Kth_b(vector<int> &v, int K, int left, int right) {
    int pivot = v[left];
    int i = left, j = right;
    while(i < j) {
        while(i < j && v[j] < pivot) j--;
        if(i < j) v[i++] = v[j];
        while(i < j && v[i] >= pivot) i++;
        if(i < j) v[j--] = v[i];
    }
    v[i] = pivot;
    if(K-1 < i) find_Kth_b(v, K, left, i-1);
    if(K-1 > i) find_Kth_b(v, K, i+1, right);
    return;
}

// find K-th bigger using m space heap
void find_Kth_heap(vector<int> &v, int ) {

}
int main() {
    vector<int> v = {4, 3, 6, 7, 8, 9, 5, 1, 2, 0};
    int K = 7;
    find_Kth_s(v, K, 0, v.size()-1);
    for(auto i : v) cout << i << " ";
    cout << endl;
    cout << v[K-1];
    return 0;
}