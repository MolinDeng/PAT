#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define NA "N/A"

using namespace std;

typedef pair<string, int> grade; 
map<string, int> A_grades;
map<string, int> C_grades;
map<string, int> M_grades;
map<string, int> E_grades;

vector<string> stu_ID;
bool cmp(int a, int b) { return a > b;}
int main(int argc, char const *argv[])
{
    vector<int> A_ranks;
    vector<int> C_ranks;
    vector<int> M_ranks;
    vector<int> E_ranks;
    int N, M;
    cin >> N >> M;
    while(N--) {
        string ID;
        int Ag, Cg, Mg, Eg;
        cin >> ID >> Cg >> Mg >> Eg;
        Ag = (Cg + Mg + Eg) / 3;
        stu_ID.push_back(ID);
        A_grades[ID] = Ag; C_grades[ID] = Cg; M_grades[ID] = Mg; E_grades[ID] = Eg;
        A_ranks.push_back(Ag); 
        C_ranks.push_back(Cg);
        M_ranks.push_back(Mg);
        E_ranks.push_back(Eg);
    }
    sort(A_ranks.begin(), A_ranks.end(), cmp);
    sort(C_ranks.begin(), C_ranks.end(), cmp);
    sort(M_ranks.begin(), M_ranks.end(), cmp);
    sort(E_ranks.begin(), E_ranks.end(), cmp);
    
    while(M--) {
        string ID;
        cin >> ID;
        if(find(stu_ID.begin(), stu_ID.end(), ID) == stu_ID.end()) {
            cout << NA << endl;
            continue;
        }
        else {
            int A_rank = find(A_ranks.begin(), A_ranks.end(), A_grades[ID]) - A_ranks.begin() + 1;
            int C_rank = find(C_ranks.begin(), C_ranks.end(), C_grades[ID]) - C_ranks.begin() + 1;
            int M_rank = find(M_ranks.begin(), M_ranks.end(), M_grades[ID]) - M_ranks.begin() + 1;
            int E_rank = find(E_ranks.begin(), E_ranks.end(), E_grades[ID]) - E_ranks.begin() + 1;
            vector<int> rank = {A_rank, C_rank, M_rank, E_rank};
            int best_rank = *min_element(rank.begin(), rank.end());
            if(best_rank == A_rank) cout << best_rank << " " << 'A' << endl;
            else if(best_rank == C_rank) cout << best_rank << " " << 'C' << endl;
            else if(best_rank == M_rank) cout << best_rank << " " << 'M' << endl;
            else if(best_rank == E_rank) cout << best_rank << " " << 'E' << endl;
        }
    }
    return 0;
}
