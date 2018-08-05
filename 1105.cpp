#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(const int a, const int b) {
    return a > b;
}
int main() {
    int N, m, n;
    scanf("%d", &N);
    for(m = ceil(sqrt(N)); m <= N; m++) {
        if(N % m == 0) {
            n = N / m;
            break;
        }
    }
    vector<int> v(N);
    for(int i = 0; i < N; i++) 
        scanf("%d", &v[i]);
    sort(v.begin(), v.end(), cmp);    
    vector<vector<int> > res(m, vector<int>(n));
    int i_upper = m, i_low = -1, j_upper = n, j_low = -1;
    for(int idx = 0, i = i_low, j = j_low; idx < N; idx++) {
        if(i == i_low && j == j_low) {
            i = ++i_low; i_upper--;
            j = ++j_low; j_upper--;
        }
        res[i][j] = v[idx];
        if(i == i_low && j < j_upper) j++;
        else if(j == j_upper && i < i_upper) i++;
        else if(i == i_upper && j > j_low) j--;
        else if(j == j_low && i > i_low) i--; 
    }
    for(auto line : res) {
        for(int i = 0; i < line.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", line[i]);
        }
        printf("\n");
    }
    return 0;
}