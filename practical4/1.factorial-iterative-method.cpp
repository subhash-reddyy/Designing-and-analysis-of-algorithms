#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    int n;
    long long fact = 1;

    cout << "Enter a number: ";
    cin >> n;

    // Start time
    auto start = high_resolution_clock::now();

    // Iterative method
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    // Stop time
    auto stop = high_resolution_clock::now();

    cout << "\nFactorial of " << n << " = " << fact << endl;

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time Taken: "
         << duration.count()
         << " nanoseconds" << endl;

    return 0;
}