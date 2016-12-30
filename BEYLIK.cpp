#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    for(int n=0; n<N; n++) {
        int r,c,t;
        cin >> r >> c >> t;
        vector<vector<char> > grid[2];
        grid[0].resize(r);
        grid[1].resize(r);
        for(int i=0; i<r; i++) {
            grid[0][i].resize(c);
            grid[1][i].resize(c);
            for(int j=0; j<c; j++) {
                cin >> grid[0][i][j];
                grid[1][i][j] = grid[0][i][j];
            }
        }

        int grid_idx = 0;

        for(int T = 0; T < t; T++) {
            int other_grid = (grid_idx + 1)%2;
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    if(grid[grid_idx][i][j] == 'R') {
                        if(i > 0 && grid[grid_idx][i-1][j] == 'P') {
                            grid[other_grid][i][j] = 'P';
                            continue;
                        }
                        if(i < r-1 && grid[grid_idx][i+1][j] == 'P') {
                            grid[other_grid][i][j] = 'P';
                            continue;
                        }
                        if(j > 0 && grid[grid_idx][i][j-1] == 'P') {
                            grid[other_grid][i][j] = 'P';
                            continue;
                        }
                        if(j < c-1 && grid[grid_idx][i][j+1] == 'P') {
                            grid[other_grid][i][j] = 'P';
                            continue;
                        }
                    } else if(grid[grid_idx][i][j] == 'P') {
                        if(i > 0 && grid[grid_idx][i-1][j] == 'S') {
                            grid[other_grid][i][j] = 'S';
                            continue;
                        }
                        if(i < r-1 && grid[grid_idx][i+1][j] == 'S') {
                            grid[other_grid][i][j] = 'S';
                            continue;
                        }
                        if(j > 0 && grid[grid_idx][i][j-1] == 'S') {
                            grid[other_grid][i][j] = 'S';
                            continue;
                        }
                        if(j < c-1 && grid[grid_idx][i][j+1] == 'S') {
                            grid[other_grid][i][j] = 'S';
                            continue;
                        }
                    } else if(grid[grid_idx][i][j] == 'S') {
                        if(i > 0 && grid[grid_idx][i-1][j] == 'R') {
                            grid[other_grid][i][j] = 'R';
                            continue;
                        }
                        if(i < r-1 && grid[grid_idx][i+1][j] == 'R') {
                            grid[other_grid][i][j] = 'R';
                            continue;
                        }
                        if(j > 0 && grid[grid_idx][i][j-1] == 'R') {
                            grid[other_grid][i][j] = 'R';
                            continue;
                        }
                        if(j < c-1 && grid[grid_idx][i][j+1] == 'R') {
                            grid[other_grid][i][j] = 'R';
                            continue;
                        }
                    }
                    grid[other_grid][i][j] = grid[grid_idx][i][j];
                }
            }
            
            grid_idx++;
            grid_idx %= 2;
        }
        for(int i=0; i<r ;i++) {
            for(int j=0; j<c; j++) {
                cout << grid[grid_idx][i][j];
            }
            cout <<endl;
        }
        if(n != N-1)
        cout <<endl;
    }
    return 0;
}
