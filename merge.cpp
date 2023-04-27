#include <iostream>
using namespace std;

void merge(int arr[], int low, int high, int mid)
{
    int i, j, k, c[high+low+1];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if(arr[i] < arr[j]){
            c[k] = arr[i];
            k++;
            i++;
        }
        else{
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        c[k] = arr[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = c[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int n;
    cout << "Radha " << endl;
    cout << "Enter size of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements - ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << "Sorted array : ";
    display(arr, n);
    return 0;
}