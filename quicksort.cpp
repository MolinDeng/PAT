#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v = {4, 9, 3, 5, 6, 7, 1};
void qs(int left, int right) {
    if(left >= right) return;
    int i = left, j = right, pivot = v[left];
    while(i < j) {
        while(i < j && v[j] >= pivot) j--;// 从右到左找到第一个小于pivot的位置
        if(i < j) v[i++] = v[j];
        while(i < j && v[i] < pivot) i++;// 从左到右找到第一个大于等于pivot的位置
        if(i < j) v[j--] = v[i];
    }
    v[i] = pivot;
    qs(left, i-1);
    qs(i+1, right);
} 

int main() {
    //freopen("a.txt", "r", stdin);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    qs(0, v.size()-1);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}