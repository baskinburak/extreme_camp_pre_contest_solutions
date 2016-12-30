#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
    while(true) {
        int A,B;
        cin >> A >> B;
        if(A == 0 && B == 0)
            break;
        map<int, bool> Amap;
        map<int, bool> Bmap;
        int d;
        for(int i=0; i<A; i++) {
            cin >> d;
            Amap[d] = true;
        }
        for(int i=0; i<B; i++) {
            cin >> d;
            Bmap[d] = true;
        }
        int ACount = 0, BCount = 0;
        for(map<int,bool>::iterator it = Amap.begin(); it != Amap.end(); it++) {
            if(it->second && !Bmap[it->first])
                ACount++;
        }
        for(map<int,bool>::iterator it = Bmap.begin(); it != Bmap.end(); it++) {
            if(it->second && !Amap[it->first])
                BCount++;
        }
        cout << min(ACount, BCount) << endl;
        
    }
    return 0;
}
