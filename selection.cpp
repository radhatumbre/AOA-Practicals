#include<iostream>
using namespace std;


void display(int *arr, int size){
    cout << "Sorted Array : ";
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
}

void swapping(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int imin = i;
        int pos = 0;
        for(int j=i; j<n; j++){
            if( arr[imin] > arr[j])
                imin = j;
        
        }
        swapping(arr[i], arr[imin]);
        
    }
    display(arr, n);
}

int main(){
    int n;
    cout << "Radha" << endl;
    cout << "Enter Number of elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : " << endl;
    for(int i=0; i<n; i++){
        cin >> arr[i] ;
    }
    selectionSort(arr, n);
    return 0;
}