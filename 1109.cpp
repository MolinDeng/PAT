#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<string, int> Person;

bool cmp(const Person &a, const Person &b) {
    if(a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}
int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);    
    vector<Person> people;
    for(int i = 0; i < N; i++) {
        char name[10];
        int h;
        scanf("%s %d", name, &h);
        people.push_back(Person(name, h));
    }
    sort(people.begin(), people.end(), cmp);
    int rowN = round(float(N) / K);
    int last_rowN = N - rowN * (K - 1), idx = 0;
    vector<vector<string> > res;
   
    for(int i = 0; i < K; i++) {
        int size = i == 0 ? last_rowN : rowN;
        vector<string> tmp(size);
        int mid = size / 2;
        tmp[mid] = people[idx++].first;
        int l = mid - 1, r = mid + 1;
        while(l >= 0 && r < size) {
            tmp[l--] = people[idx++].first;
            tmp[r++] = people[idx++].first;
        }
        if(l == 0) tmp[l] = people[idx++].first;
        //res.push_back(tmp);
        for(int i = 0; i < tmp.size(); i++) {
            if(i != 0) printf(" ");
            printf("%s", tmp[i].c_str());
        }
        printf("\n");
        tmp.clear();
    }
    // for(auto row : res) {
    //     for(int i = 0; i < row.size(); i++) {
    //         if(i != 0) printf(" ");
    //         printf("%s", row[i].c_str());
    //     }
    //     printf("\n");
    // }
    return 0;
}
