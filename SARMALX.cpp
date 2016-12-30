#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
using namespace std;
struct mcmp {
    bool operator()(const std::string& a, const std::string& b) const {
        if(a.size() == b.size()) {
            return a<b;
        }
        return a.size() < b.size();
    }
};
void recurse(vector<vector<char> >& grid, int x, int y, int N, map<string,bool, mcmp>& strings, vector<vector<bool> >& avail, string& cur) {
    cur.push_back(grid[x][y]);
    if(cur.size() >= 3)
        strings[cur] = true;
    if(x > 0) {
        if(grid[x-1][y] > grid[x][y] && avail[x-1][y]) {
            avail[x-1][y] = false;
            recurse(grid, x-1, y, N, strings, avail, cur);
            avail[x-1][y] = true;
        }
        if(y>0) {
            if(grid[x-1][y-1] > grid[x][y] && avail[x-1][y-1]) {
                avail[x-1][y-1] = false;
                recurse(grid, x-1, y-1, N, strings, avail, cur);
                avail[x-1][y-1] = true;
            }
        }
        if(y<N-1) {
            if(grid[x-1][y+1] > grid[x][y] && avail[x-1][y+1]) {
                avail[x-1][y+1] = false;
                recurse(grid, x-1, y+1, N, strings, avail, cur);
                avail[x-1][y+1] = true;
            }
        }
    }
    if(y>0) {
         if(grid[x][y-1] > grid[x][y] && avail[x][y-1]) {
            avail[x][y-1] = false;
            recurse(grid, x, y-1, N, strings, avail, cur);
            avail[x][y-1] = true;
        }
    }
    if(y<N-1) {
        if(grid[x][y+1] > grid[x][y] && avail[x][y+1]) {
            avail[x][y+1] = false;
            recurse(grid, x, y+1, N, strings, avail, cur);
            avail[x][y+1] = true;
        }
    }

    if(x<N-1) {
        if(grid[x+1][y] > grid[x][y] && avail[x+1][y]) {
            avail[x+1][y] = false;
            recurse(grid, x+1, y, N, strings, avail, cur);
            avail[x+1][y] = true;
        }
        if(y>0) {
            if(grid[x+1][y-1] > grid[x][y] && avail[x+1][y-1]) {
                avail[x+1][y-1] = false;
                recurse(grid, x+1, y-1, N, strings, avail, cur);
                avail[x+1][y-1] = true;
            }
        }
        if(y<N-1) {
            if(grid[x+1][y+1] > grid[x][y] && avail[x+1][y+1]) {
                avail[x+1][y+1] = false;
                recurse(grid, x+1, y+1, N, strings, avail, cur);
                avail[x+1][y+1] = true;
            }
        }
    }
    cur.pop_back();
}

void solve(vector<vector<char> >& grid, int x, int y, int N, map<string,bool, mcmp>& strings) {
    vector<vector<bool> > avail;
    avail.resize(N);
    for(int i=0; i<N; i++) {
        avail[i].resize(N);
        for(int j=0; j<N; j++)
            avail[i][j] = true;
    }
    avail[x][y] = false;
    string str;
    recurse(grid, x, y, N, strings, avail, str);
}

int main() {
    int T;
    cin >> T;
    for(int t=0; t<T; t++) {
        int N;
        cin >> N;
        vector<vector<char> > grid;
        grid.resize(N);
        for(int i=0; i<N; i++) {
            grid[i].resize(N);
            for(int j=0; j<N; j++) {
                cin >> grid[i][j];
            }
        }
        map<string, bool, mcmp> strings;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                solve(grid, i, j, N, strings);
            }
        }
        for(map<string,bool>::iterator it = strings.begin(); it!=strings.end(); it++) {
            cout << it->first << endl;
        }
        if(t!=T-1)
        cout << endl;
    }
    return 0;
}
