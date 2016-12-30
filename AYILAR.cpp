#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    while(true) {
        int n,m;
        cin >> n >> m;
        if(n==0 && m==0)
            break;
        vector<int> d;
        d.resize(n);
        vector<int> k;
        k.resize(m);
        for(int i=0; i<n; i++) cin >> d[i];
        for(int i=0; i<m; i++) cin >> k[i];
        sort(d.begin(), d.end());
        sort(k.begin(), k.end());
        int gold=0;
        int i,j;
        for(i=0, j=0; i<n && j<m;) {
            while(d[i] > k[j] && j<m) j++;
            if(j == m) break;
            gold += k[j];
            i++;j++;
        }
        if(i == n)
            cout << gold << endl;
        else
            cout << "Bilgeler diyari biraksin." << endl;
    }
    return 0;
}
