//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod=1e9+7;
 int  dfs(int row ,int col ,vector<vector<int>> &grid , int &n ,int &m,vector<vector<int>> &dp){
      
      if(row ==n-1 && col==m-1)
      {
          return 1 ; 
      }
       if(row >=n || col>=m  || grid[row][col]==0) return 0;
      if(dp[row][col]!=-1)
     return dp[row][col];
      
     int right=0;
      int down =0;
   
      right=dfs(row,col+1 ,grid ,n,m,dp);
  
      down =dfs(row+1 ,col, grid , n , m,dp );
return dp[row][col]=(right+down)%mod;
      
  }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        if(grid[0][0]==0 || grid[n-1][m-1]==0) return 0;
      vector<vector<int >>dp(n, vector<int> (m,-1));
return         dfs( 0, 0,grid ,n ,m,dp )%mod;

    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends