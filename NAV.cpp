#include <iostream>
using namespace std;

char grid[12][12];
int cnt[12][12];
int R,C;

pair<int, int> solve(int r, int c, int count) {
    cnt[r][c] = count;
    if(grid[r][c] == 'W') {
        c--;
        if(c==-1) {
            return pair<int,int>(count+1, -1);
        } else if(cnt[r][c] != -1) {
            return pair<int, int>(count+1, cnt[r][c]);
        } else
            return solve(r,c,count+1);
    } else if(grid[r][c] == 'E') {
        c++;
        if(c==C) {
            return pair<int,int>(count+1, -1);
        } else if(cnt[r][c] != -1) {
            return pair<int, int>(count+1, cnt[r][c]);
        } else
            return solve(r,c,count+1);
    } else if(grid[r][c] == 'N') {
        r--;
        if(r==-1) {
            return pair<int,int>(count+1, -1);
        } else if(cnt[r][c] != -1) {
            return pair<int, int>(count+1, cnt[r][c]);
        } else
            return solve(r,c,count+1);
    } else if(grid[r][c] == 'S') {
        r++;
        if(r==R) {
            return pair<int,int>(count+1, -1);
        } else if(cnt[r][c] != -1) {
            return pair<int, int>(count+1, cnt[r][c]);
        } else
            return solve(r,c,count+1);
    }
}

int main() {
    while(true) {
        int enter;
        cin >> R >> C >> enter;        
        enter--;
        if(R==0 && C==0 && enter == -1) break;
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++) {
                cin >> grid[i][j];
                cnt[i][j] = -1;
            }

        pair<int,int> res = solve(0, enter, 0);
        if(res.second == -1)
            cout << "Robot "<<res.first<<" hamlede tabloyu terk eder." << endl;
        else
            cout << "Robot " << res.second << " hamle yaptiktan sonra " << res.first-res.second << " hamlelik bir donguye girer." << endl;
    }
    return 0;
}
