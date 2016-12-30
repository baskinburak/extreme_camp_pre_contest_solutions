#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    while(true) {
        int dim;
        cin >> dim;
	    if(dim == 0) break;
        vector<int> w;
        int corner_cnt = 1 << dim;

        w.resize(corner_cnt);
        for(int i=0; i<corner_cnt; i++)
            cin >> w[i];

        vector<int> potencies;
        potencies.resize(corner_cnt);
        for(int i=0; i<corner_cnt;i++) {
            for(int mask=1;mask!=corner_cnt;mask=mask<<1) {
                int neigh = i ^ mask;
                potencies[i] += w[neigh];
            }
        }

        int max_sum = -1;
        for(int i=0; i<corner_cnt; i++) {
            int max_neigh = -1;
            for(int mask=1;mask!=corner_cnt;mask=mask<<1) {
                int neigh = i ^ mask;
                max_neigh = max(max_neigh, potencies[neigh]);
            }
            max_sum = max(max_sum, max_neigh + potencies[i]);
        }
        cout << max_sum << endl;
    }
    return 0;
}


