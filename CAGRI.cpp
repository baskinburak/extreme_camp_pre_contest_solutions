#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include <queue>
#include <cmath>
using namespace std;

double adjlist[250][250];
int SIZE;
double dist[250];

double cal_dist(pair<double,double>& a, pair<double,double>& b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

class compare {
    public:
        bool operator() (pair<int, double>& a, pair<int,double>& b) {
            return a.second < b.second;
        }
};

void solve() {
    priority_queue<pair<int, double>, vector<pair<int,double> >, compare > pq;
    pq.push(pair<int, double>(0, 0));
    while(!pq.empty()) {
        pair<int,double> fr = pq.top(); pq.pop();
        int idx = fr.first;
        double dst = fr.second;
        if(dst > dist[idx]) continue;
        for(int i=0; i<SIZE; i++) {
            double val = adjlist[idx][i];
            if(val == numeric_limits<double>::infinity()) continue;
            if(dist[idx] + val < dist[i]) {
                dist[i] = dist[idx] + val;
                pq.push(pair<int, double>(i, dist[i]));
            }
        }
    }
}

int main() {
    int T;
    string line;
    getline(cin ,line);
    stringstream st(line);
    st >> T;
    getline(cin, line);
    for(int t=0; t<T; t++) {
        for(int i=0; i < 250;i++) {
            dist[i] = numeric_limits<double>::infinity();
            for(int j=0; j < 250; j++) {
                adjlist[i][j] = numeric_limits<double>::infinity();
            }
        }
        double x,y;
        getline(cin, line);
        stringstream ss(line);
        vector<pair<double, double> > coor;
        ss >> x >> y;
        coor.push_back(pair<double, double>(x,y));
        ss >> x >> y;
        coor.push_back(pair<double, double>(x,y));
        double distance = cal_dist(coor[0], coor[1]);
        adjlist[0][1] = distance*4;
        adjlist[1][0] = distance*4;
        while(true) {
            getline(cin, line);
            if(line == std::string("")) break;

            stringstream sz(line);
            vector<pair<double, double> > cur;
            while(true) {           
                sz >> x >> y;
                if(x == -1 && y == -1) break;
                cur.push_back(pair<double,double>(x,y));
            }
            int coor_size = coor.size();
            for(int i=0; i<coor_size; i++) {
                for(int j=0; j<cur.size(); j++) {
                    double distance = cal_dist(coor[i], cur[j]);
                    if(distance * 4 < adjlist[i][coor_size+j])
                        adjlist[i][coor_size+j] = distance*4;
                    if(distance * 4 < adjlist[coor_size+j][i])
                        adjlist[coor_size+j][i] = distance*4;
                }
            }
            for(int i=0; i<cur.size()-1; i++) {
                int j = i+1;
                double distance = cal_dist(cur[i], cur[j]);
                if(distance < adjlist[coor_size+i][coor_size+j])
                    adjlist[coor_size+i][coor_size+j] = distance;
                if(distance < adjlist[coor_size+j][coor_size+i])
                    adjlist[coor_size+j][coor_size+i] = distance;
            }
			for(int i=0; i< cur.size(); i++) {
				for(int j=i+1; j<cur.size(); j++) {
					double distance = cal_dist(cur[i], cur[j])*4;
					if(distance < adjlist[coor_size+i][coor_size+j]) adjlist[coor_size+i][coor_size+j] = distance;
					if(distance < adjlist[coor_size+j][coor_size+i]) adjlist[coor_size+j][coor_size+i] = distance;
				}
			}
            for(int i=0; i<cur.size(); i++)
                coor.push_back(cur[i]);
        }
        SIZE = coor.size();
        dist[0] = 0;
        solve();
        cout << (int)(dist[1]*6/4000 + 0.5) << endl;
    }
}
