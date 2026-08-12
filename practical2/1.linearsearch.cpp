#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Linear Search
int linearSearch(vector<int>& arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            return i;
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

    int key;

    cout << "Enter element to search: ";
    cin >> key;

    // Start time
    auto start = high_resolution_clock::now();

    // Linear Search
    int index = linearSearch(arr, key);

    // Stop time
    auto stop = high_resolution_clock::now();

    // Display result
    if (index != -1)
    {
        cout << "\nElement found at index: " << index << endl;
    }
    else
    {
        cout << "\nElement not found" << endl;
    }

    // Calculate execution time
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time Taken: "
         << duration.count()
         << " microseconds" << endl;

    return 0;
}