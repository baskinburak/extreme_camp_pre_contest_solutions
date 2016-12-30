#include <iostream>
using namespace std;
int main() {
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;
        int a = 0;
        int b = 0;
        bool a_turn = true;
        for(int mask=1; mask!=0x80000000; mask = mask << 1) {
            if(n&mask) {
                if(a_turn) a |= mask;
                else b |= mask;
                a_turn = !a_turn;
            }
        }
        cout << a << " " << b << endl;
    }
    return 0;
}
