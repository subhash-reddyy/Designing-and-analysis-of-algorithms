#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Merge two sorted parts
void merge(vector<int>& arr, int low, int mid, int high)
{
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from left part
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right part
    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back to original array
    for (int k = 0; k < temp.size(); k++)
    {
        arr[low + k] = temp[k];
    }
}

// Merge Sort
void mergeSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        // Sort left half
        mergeSort(arr, low, mid);

        // Sort right half
        mergeSort(arr, mid + 1, high);

        // Merge both halves
        merge(arr, low, mid, high);
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

    // Merge Sort
    mergeSort(arr, 0, n - 1);

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