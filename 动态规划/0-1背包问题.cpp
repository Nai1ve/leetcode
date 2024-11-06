#include <iostream>
#include <vector>

using namespace std;
// 计算0 - 1背包能获得的最大价值
int knapSack(int capacity, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = values.size();
    // 创建动态规划数组
    vector< vector<int> > dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                // 选择放入或不放入当前物品中的较大价值
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}


int main() {
    vector<int> values ;
    values.push_back(3);
    values.push_back(6);
    values.push_back(9);
    values.push_back(7);

    vector<int> weights;
    weights.push_back(2);
    weights.push_back(3);
    weights.push_back(4);
    weights.push_back(2);

    int capacity = 5;
    int maxValue = knapSack(capacity, weights, values);
    cout << "背包能装的最大价值为: " << maxValue << endl;
    return 0;
}
