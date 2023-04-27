#include<iostream>
using namespace std;

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

void quickSort(int *arr, int low, int high){
    cout<< "yes";
    if(low<high){
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }
}

int main(){
    int n;
    cout<< "Enter size of Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements : ";
    for(int i=0; i<n; i++){
        cin>> arr[i];
    }
    quickSort(arr, 0, n-1);
    cout<< "Sorted array : ";
    display(arr, n);
    return 0;
}