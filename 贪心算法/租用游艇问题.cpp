#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // 定义无穷大

int calculateMinCost(int n, const vector< vector<int> >& rent) {
    vector<int> minCost(n + 1, INF);
    minCost[1] = 0;

    for (int j = 2; j <= n; ++j) { 
        for (int i = 1; i < j; ++i) {
            if (rent[i][j] > 0) { 
                minCost[j] = min(minCost[j], minCost[i] + rent[i][j]);
            }
        }
    }
    
    return minCost[n];
}

int main() {
    int n = 5; // 游艇出租站的数量

    vector< vector<int> > rent(n + 1, vector<int>(n + 1, 0));
    rent[1][2] = 1000;
    rent[1][3] = 2000;
    rent[1][4] = 2500;
    rent[2][3] = 1500;
    rent[2][4] = 2200;
    rent[2][5] = 3000;
    rent[3][4] = 800;
    rent[3][5] = 2500;
    rent[4][5] = 1200;

    int minCost = calculateMinCost(n, rent);
    if (minCost == INF) {
        cout << "无法到达站点n" << endl;
    } else {
        cout << "从站点1到站点n的最少租金: " << minCost << "元" << endl;
    }

    return 0;
}
