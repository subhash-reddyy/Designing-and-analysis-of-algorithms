#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Binary Search
int binarySearch(vector<int>& arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
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

    // Automatically sort the array
    sort(arr.begin(), arr.end());

    cout << "\nSorted Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    int key;

    cout << "\n\nEnter element to search: ";
    cin >> key;

    // Start time for Binary Search
    auto start = high_resolution_clock::now();

    int index = binarySearch(arr, key);

    // Stop time
    auto stop = high_resolution_clock::now();

    if (index != -1)
    {
        cout << "\nElement found at index: "
             << index << endl;
    }
    else
    {
        cout << "\nElement not found" << endl;
    }

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Binary Search Time: "
         << duration.count()
         << " microseconds" << endl;

    return 0;
}