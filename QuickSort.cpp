#include<iostream>
using namespace std;

int partition(int arr[], int s, int e){

    int pivot = arr[s];

    int cnt = 0;

    //count the elements less than pivot
    for(int i=s+1; i<=e;i++){
        if(arr[i] < pivot)
            cnt++;
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    //left and right wala part sambhal lete hai
    int i = s;
    int j = e;

    while(i < pivotIndex && j> pivotIndex){

        while(arr[i] < pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i < pivotIndex && j> pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e){

    //base case 
    if(s>=e)
        return;
    
    //partition karenge
    int p = partition(arr, s, e);

    //left part sort karenge
    quickSort(arr, s, p-1);

    //right part sort karenge
    quickSort(arr, p+1, e);
}

int main(){

    int arr[9] = {12, 34,12,56,23,78,34,56,1};
    int n = 9;

    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
