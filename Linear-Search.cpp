// Linear Search using Recursion

#include<iostream>
using namespace std;

bool Search(int arr[], int key, int n){

    //base case 
    if(n == 0)
        return 0;

    //recursive case

    if(arr[0] == key)
        return true;

    else{
        bool ans = Search(arr+1, key, n-1);
        return ans;
    }
}

int main(){

    int arr[5] = {3,5,1,2,6};
    int key = 7;
    int n = 5;

    int ans = Search(arr, key, 5);

    if(ans == true){
        cout << "Element found";
    }
    else{
        cout << "Element not found";
    }

    return 0;
}
