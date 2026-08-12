#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Insertion Sort
void insertionSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at correct position
        arr[j + 1] = key;
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

    // Insertion Sort
    insertionSort(arr);

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