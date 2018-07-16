#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    vector<int> seq(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &seq[i]);
    int curr_sum = 0, max_sum = 0;
    int start = 0, end = N - 1, temp_start = 0, temp_end = 0;
    for(int i = 0; i < N; i++) {
        curr_sum += seq[i];
        if(curr_sum < 0) {
            curr_sum = 0;
            temp_start = (i == N-1 ? N-1 : i + 1);
        }
        else if(curr_sum > max_sum || (curr_sum == 0 && end == N - 1)) {
            if(curr_sum == 0 && end == N - 1) cout << "yes";
            max_sum = curr_sum;
            start = temp_start;
            end = i;
        }
    }
    cout << start << " " << end << endl;
    printf("%d %d %d", max_sum, seq[start], seq[end]);
    return 0;
}
