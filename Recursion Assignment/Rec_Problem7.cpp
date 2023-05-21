#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& profits) {
    int n = weights.size();

   
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (weights[i - 1] <= j) {
                dp[i][j] = max(profits[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
            
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

   
    return dp[n][W];
}

int main() {
    int N;
    cout << "Enter the number of items: ";
    cin >> N;

    vector<int> weights(N);
    vector<int> profits(N);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the profits of the items: ";
    for (int i = 0; i < N; ++i) {
        cin >> profits[i];
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int maxProfit = knapsack(W, weights, profits);

    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}