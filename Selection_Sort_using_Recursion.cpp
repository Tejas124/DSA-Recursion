#include<iostream>
using namespace std;

void SelectionSort(int arr[], int beginIndex, int n){
   
    //base case
    if(beginIndex >= n-1)
        return;

    int minIndex = beginIndex;
    for(int i = beginIndex; i<n;i++){
        
        if(arr[i] < arr[minIndex]){
            minIndex = i;
        }
        swap(arr[minIndex], arr[beginIndex]);
    }

    SelectionSort(arr, beginIndex+1, n);

}

int main(){

    int arr[5] = {5,4,3,2,1};

    sort(arr,0, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<< " ";
    }

    return 0;
}
