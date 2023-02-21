//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    
    private:
    
    bool isSafe(vector<vector<int>> &m, vector<vector<int>> visited,int x,int y,int n ){
        
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    
    void solve(vector<vector<int>> &m, vector<vector<int>> visited, vector<string> &ans,
                int x, int y, int n, string path){
                                
        //base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        //We have four conditions -> D U L R
        
        //For D-> Down
        //new x and new y:
        int newx = x+1;
        int newy = y;
        
        if(isSafe(m, visited, newx, newy, n )){
            path.push_back('D');
            solve(m, visited, ans, newx, newy, n, path);
            path.pop_back();
        }
        
        //For L-> Left
        newx = x;
        newy = y-1;
        
        if(isSafe(m, visited, newx, newy, n )){
            path.push_back('L');
            solve(m, visited, ans, newx, newy, n, path);
            path.pop_back();
        }
        
        //For R->Right
        newx = x;
        newy = y+1;
        
        if(isSafe(m, visited, newx, newy, n )){
            path.push_back('R');
            solve(m, visited, ans, newx, newy, n, path);
            path.pop_back();
        }
        
        //For U->Up
        newx = x-1;
        newy = y;
        
        if(isSafe(m, visited, newx, newy, n )){
            path.push_back('U');
            solve(m, visited, ans, newx, newy, n, path);
            path.pop_back();
        }
        
        visited[x][y] = 0;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        
        if(m[0][0] == 0){
            return ans;
        }
        
        
        vector<vector<int>> visited = m;
        string path = "";
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        int srcx = 0;
        int srcy = 0;
        
        solve(m, visited, ans, srcx, srcy, n, path);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
