#include <iostream>
using namespace std;
int M,C;
int P[22][22];
int DP[202][22];

int solve(int ML, int G) {
    if(ML<0)
        return -11238712;
    if(G == C)
        return M-ML;
    if(DP[ML][G] != -1) return DP[ML][G];
    int res = -1;
    for(int i=1; i<=P[G][0]; i++) {
        res = max(res, solve(ML - P[G][i], G+1));
    }
    return DP[ML][G] = res;
}

int main() {
    int N;
    cin >> N;
    for(int n=0; n<N; n++) {
        cin >> M >> C;
        for(int c=0; c<C; c++) {
            cin >> P[c][0];
            for(int k=1; k<=P[c][0]; k++) {
                cin >> P[c][k];
            }
        }
        for(int i=0; i<=M; i++) {
            for(int j=0; j<=C; j++)
                DP[i][j] = -1;
        }
        int res = solve(M,0);
        if(res < 0)
            cout << "no solution" << endl;
        else
            cout << res << endl;
    }
    return 0;
}
