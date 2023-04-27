#include <iostream>
using namespace std;

int binarySearch(int *arr, int low, int high, int key)
{
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            high = mid-1;
        else 
            low = mid+1;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter size of Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Element to be search : ";
    cin >> key;
    int pos = binarySearch(arr, 0, n - 1, key);
    if(pos==-1)
        cout<< "Element Not Found";
    else    
        cout<< "Element found at position "<< pos;
    return 0;
}