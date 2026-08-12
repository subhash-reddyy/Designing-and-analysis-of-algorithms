#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Bubble Sort
void bubbleSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Stop if array is already sorted
        if (!swapped)
            break;
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Start time
    auto start = high_resolution_clock::now();

    // Call Bubble Sort
    bubbleSort(arr);

    // Stop time
    auto stop = high_resolution_clock::now();

    // Display sorted array
    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Calculate execution time
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n\nTime Taken: "
         << duration.count()
         << " microseconds" << endl;

    return 0;
}