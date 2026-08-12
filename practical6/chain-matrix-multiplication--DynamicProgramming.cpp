#include <iostream>
#include <vector>
#include <climits>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Matrix Chain Multiplication
int matrixChainMultiplication(vector<int>& p, int n)
{
    // dp[i][j] = minimum multiplication cost
    // for matrices i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Length of matrix chain
    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;

            dp[i][j] = INT_MAX;

            // Try every possible split
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    // n matrices require n+1 dimensions
    vector<int> p(n + 1);

    cout << "Enter dimensions: ";

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    /*
       Example:
       Matrices:
       A1 = 10 x 20
       A2 = 20 x 30
       A3 = 30 x 40

       Enter:
       10 20 30 40
    */

    // Start time
    auto start = high_resolution_clock::now();

    int minCost = matrixChainMultiplication(p, n + 1);

    // Stop time
    auto stop = high_resolution_clock::now();

    cout << "\nMinimum number of scalar multiplications = "
         << minCost << endl;

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time Taken = "
         << duration.count()
         << " microseconds" << endl;

    return 0;
}