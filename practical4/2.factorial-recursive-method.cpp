#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Recursive factorial function
long long factorial(int n)
{
    // Base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    // Recursive call
    return n * factorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    // Start time
    auto start = high_resolution_clock::now();

    // Recursive method
    long long fact = factorial(n);

    // Stop time
    auto stop = high_resolution_clock::now();

    cout << "\nFactorial of " << n << " = " << fact << endl;

    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Time Taken: "
         << duration.count()
         << " nanoseconds" << endl;

    return 0;
}