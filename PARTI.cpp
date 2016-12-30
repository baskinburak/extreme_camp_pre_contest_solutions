#include <iostream>
using namespace std;
int P[50010];

int FIND(int a) {
    if(P[a] < 0) return a;
    return P[a] = FIND(P[a]);
}

void UNION(int a, int b) {
    int a_p = FIND(a);
    int b_p = FIND(b);
    if(a_p == b_p) return;
    if(P[a_p] < P[b_p]) {
        P[a_p] += P[b_p];
        P[b_p] = a_p;
    } else {
        P[b_p] += P[a_p];
        P[a_p] = b_p;
    }
}

int main() {
    while(true) {
        int n,m;
        cin >> n >> m;
        if(n==0&&m==0) break;
        for(int i=0; i<n; i++)
            P[i] = -1;
        int a,b;
        for(int i=0; i<m; i++) {
            cin >> a >> b;
            UNION(a-1,b-1);
        }
        int c = 0;
        for(int i=0; i<n; i++) {
            c += (P[i] < 0);
        }
	cout << c << endl;
    }
    return 0;
}
