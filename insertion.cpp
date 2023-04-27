#include<iostream>
using namespace std;

void display(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " " ;
    }
}

void insertionSort(int *arr, int n){
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]= arr[j];
            j--;

        }
        arr[j+1] = key;
    }
    display(arr, n);
}


int main(){
    int n;
    cout<< "Enter size of array : ";
    cin >> n;
    cout<< "Enter elements of array : ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    insertionSort(arr, n);
    return 0;
}