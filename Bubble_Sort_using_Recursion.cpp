#include<iostream>
using namespace std;

void sort(int arr[], int n){

    //base case
    //already sorted
    if(n == 0 || n == 1)
        return;

    //largest element ko end me dal diya
    //1 case solved baki recursion sambhal lega
    for(int i=0;i<n-1;i++){
        
        if(arr[i] > arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    //recursive call
    sort(arr, n-1);
}

int main(){

    int arr[5] = {4,2,1,3,5};

    sort(arr, 5);

    for(int i=0; i<5; i++){
        cout<<arr[i]<< " ";
    }

    return 0;
}
