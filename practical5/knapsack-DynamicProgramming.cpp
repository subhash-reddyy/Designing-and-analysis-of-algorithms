#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

int knapsack(int capacity, vector<int>& weight, vector<int>& value, int n)
{
    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            // If item weight is less than or equal to capacity
            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Start time
    auto start = high_resolution_clock::now();

    int maxValue = knapsack(capacity, weight, value, n);

    // Stop time
    auto stop = high_resolution_clock::now();

    cout << "\nMaximum Value = " << maxValue << endl;

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time Taken = "
         << duration.count()
         << " microseconds" << endl;

    return 0;
}