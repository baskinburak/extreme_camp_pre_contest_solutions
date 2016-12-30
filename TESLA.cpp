#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class edge {
    public:
        int f, t, w;
        edge(int a, int b, int c): f(a), t(b), w(c) {}
        edge() {}
        bool operator<(const edge& rhs) const { return w < rhs.w; }
};

int FIND(vector<int>& P, int a) {
    if(P[a] < 0) return a;
    return P[a] = FIND(P, P[a]);
}

void UNION(vector<int>& P, int a, int b) {
    int a_p = FIND(P, a);
    int b_p = FIND(P, b);
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
        if(n == 0 && m == 0) break;
        vector<int> set;
        set.resize(n);
        for(int i=0; i<n; i++) {
            set[i] = -1;
        }

        vector<edge> edges;
        edges.resize(m);
        for(int i=0; i<m; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            edges[i] = edge(a,b,c);
        }

        sort(edges.begin(), edges.end());
        int best = 0;
        for(int i=0; i<m; i++) {
            int f = edges[i].f;
            int t = edges[i].t;
            if(FIND(set, f) != FIND(set, t)) {
                UNION(set, f, t);
                best = edges[i].w;
            }
        }

        int r_count = 0;
        for(int i=0; i<n; i++) {
            if(set[i] < 0) r_count++; 
        }
        if(r_count > 1) {
            cout << "IMPOSSIBLE" << endl;
        } else 
            cout << best << endl;
    }
    return 0;
}
