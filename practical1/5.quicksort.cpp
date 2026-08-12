#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Partition function
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        // Sort left part
        quickSort(arr, low, pivotIndex - 1);

        // Sort right part
        quickSort(arr, pivotIndex + 1, high);
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

    // Quick Sort
    quickSort(arr, 0, n - 1);

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