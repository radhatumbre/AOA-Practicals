#include <iostream>
using namespace std;

void subsetsum_Backtracking(int set[], int sum,int tmpsum, int pos, int size, bool &found){
    if (tmpsum == sum )
        found = true;
    
    for(int i=pos; i<size; i++){
        if(tmpsum + set[i] <= sum){
            tmpsum += set[i];
            subsetsum_Backtracking(set, sum, tmpsum, i+1, size, found);
            tmpsum -= set[i];
        }
    }
}

int main()
{
    int n,sum;
    cout<< "Enter size of array : ";
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout<< "Enter the sum : ";
    cin >> sum;

    bool found = false;
    subsetsum_Backtracking(arr, sum, 0, 0, n, found);
    if(found)
        cout << "Subset with the sum found" << endl;
    else    
        cout<< "Subset with the sum Not Found" << endl;

    return 0;
}