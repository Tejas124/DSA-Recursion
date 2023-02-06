#include<iostream>
using namespace std;

void reverse(string& s, int i, int n){

    //base case
    if(i>(n-i-1))
        return;
    
    swap(s[i] , s[n-i-1]);
    i++;
    
    //recursive call
    reverse(s, i, n);
}

int main(){

    string s = "tejas";
    int n = s.length();
    reverse(s, 0, n);

    cout<<s;

    return 0;
}
