// Sorting an array using recursion
// Returns true if array is sorted

#include<iostream>
using namespace std;

bool isSorting(int arr[], int n){

    //Base case
    if(n == 0 || n == 1){
        return true;
    }

    //processing
    if(arr[0] > arr[1])
        return false;

    else{
        //recursion
        int ans = isSorting(arr+1, n-1);
        return ans;
    }
}

int main(){
    int arr[9] = {1,2,3,4,10,6,7,8,9};
    int n = 9;

    bool ans = isSorting(arr,n);

    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
    return 0;
}
