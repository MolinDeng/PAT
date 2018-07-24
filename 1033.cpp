#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

bool cmp(const pair<float, float> &a, const pair<float, float> &b) {
    return a.second < b.second;
}
int main() {
    float Cmax, D, Davg, N;
    scanf("%f %f %f %f", &Cmax, &D, &Davg, &N);
    vector<pair<float, float> > stations;// first price, second distance
    while(N--) {
        float price, dis;
        scanf("%f %f", &price, &dis);
        stations.push_back(make_pair(price, dis));
    } 
    stations.push_back(make_pair(0, D));
    sort(stations.begin(), stations.end(), cmp);
    if(stations[0].second != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    float max_dis = Cmax * Davg, index = 0, cost = 0, oil_left = 0;
    while(index != stations.size() - 1) {
        int min_index = -1;
        float min_price = INT_MAX;
        for(int i = index + 1; i < stations.size() && stations[i].second <= stations[index].second + max_dis; i++) {
            if(stations[i].first < min_price) {
                min_price = stations[i].first;
                min_index = i;
            }
            if(stations[i].first < stations[index].first) {
                min_index = i;
                break;
            }
        }
        if(min_index == stations.size() - 1) {
            float oil_can_go = oil_left * Davg;
            float dis = stations[min_index].second - stations[index].second;
            if(oil_can_go > dis) break;
            else {
                cost += (dis - oil_can_go) / Davg * stations[index].first;
                break;
            }
        }
        if(min_index == -1) {
            printf("The maximum travel distance = %.2f", stations[index].second + max_dis);
            return 0;
        }
        else if(stations[index].first < stations[min_index].first) {// 说明当前位置是最小的价钱，无论如何加满
            cost += (Cmax - oil_left) * stations[index].first;
            oil_left = Cmax - (stations[min_index].second - stations[index].second) / Davg;
            index = min_index;
        } else {
            float oil_can_go = oil_left * Davg;
            float dis = stations[min_index].second - stations[index].second;
            if(oil_can_go >= dis) {
                oil_left -= dis / Davg;
                index = min_index;
            } else {
                cost += (dis - oil_can_go) / Davg * stations[index].first;
                oil_left = 0;
                index = min_index;
            }
        }
        //cout << "cost " << cost << " index " << index  << " oil_left " << oil_left << endl;
    }
    printf("%0.2f", cost);
    return 0;
}