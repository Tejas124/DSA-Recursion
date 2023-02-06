#include<iostream>
using namespace std;

bool pailndrome(string& s, int i, int n){

    //base case 
    if(i>(n-i-1))
        return 1;

    if(s[i] != s[n-i-1])
        return false;

    //recursive case
    pailndrome(s, i+1, n);
}

int main(){

    string s = "abbaccabba";

    bool ans = pailndrome(s, 0, s.length());

    if(ans)
        cout<<"String is Palindrome";
    else
        cout<<"String is not palindrome";

    return 0;
}
