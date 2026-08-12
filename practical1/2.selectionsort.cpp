#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Selection Sort
void selectionSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap minimum element with first unsorted element
        swap(arr[i], arr[minIndex]);
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

    // Selection Sort
    selectionSort(arr);

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