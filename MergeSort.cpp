#include<iostream>
using namespace std;

void merge(int arr[], int s, int e){

    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    //create two arrays
    int* first = new int[len1];
    int* second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0;i<len1;i++){
       first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0;i<len2;i++){
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }
    
    while(index1<len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2<len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
    
}

void mergeSort(int arr[], int s, int e){

    //base case 
    if(s>=e)
        return;
    
    int mid = (s+e)/2;
    
    //first half sort kr lo
    mergeSort(arr, s, mid);

    //second half sort kr lo
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);
}

int main(){

    int arr[9] = {12, 34,12,56,23,78,34,56,1};
    int n = 9;

    mergeSort(arr, 0, n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
