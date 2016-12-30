#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
using namespace std;
void gen(map<long long int, bool>& duplicates, vector<long long int>& vals,long long int val) {
    duplicates[val] = true;
    vals.push_back(val);
    if(2*val <= 2147483648L && duplicates[2*val] == false) {
        gen(duplicates, vals, 2*val);
    }
    if(3*val <= 2147483648L && duplicates[3*val] == false) {
        gen(duplicates, vals, 3*val);
    }
}
int main() {
    vector<long long int> vals;
    map<long long int, bool> duplicates;
    gen(duplicates, vals, 1);
    sort(vals.begin(), vals.end());
    while(true) {
        int M;
        cin >> M;
        if(M==0)
            break;
        if(binary_search(vals.begin(), vals.end(), M))
            cout << M << endl;
        else {
            auto it = upper_bound(vals.begin(), vals.end(), M);
            cout << *it << endl;
        }
    }
    return 0;
}
