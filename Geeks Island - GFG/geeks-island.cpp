//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

void dfs(int row ,int col,vector<vector<int>> &arr ,vector<int> &delrow ,vector<int> &delcol,vector<vector<int>> &mat,int &n , int &m){
    if(arr[row][col])
    return ;
    arr[row][col]=1;
    for(int i =0; i<4;i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
    if(nrow>=0 && ncol >=0 && nrow<n && ncol<m && mat[nrow][ncol]>=mat[row][col]  )
   dfs(nrow, ncol ,arr,delrow, delcol,mat,n,m);
    }

}
    int water_flow(vector<vector<int>> &mat,int N,int M){
   vector<vector<int >> Indian(N,vector<int>(M,0));
   vector<vector<int>> Arabian(N,vector<int>(M,0));
  int n =N; 
  int m= M;
   vector<int > delrow={-1,0,1,0};
   vector<int> delcol={0,1,0,-1};
       for(int i =0;i < M;i++)
   {
       dfs(0,i,Indian,delrow,delcol,mat,n,m);
       dfs(N-1,i ,Arabian, delrow, delcol,mat,n,m);
       
   }
   for(int i =0;i<N;i++)
   {
       dfs(i,0,Indian ,delrow, delcol , mat,n,m);
       dfs(i,M-1, Arabian,delrow, delcol , mat,n,m);
   }
    int count =0;
    for(int i =0; i < n ; i++)
    {
        for(int j=0; j<m ;j++)
        {
            if(Indian[i][j]==1 && Arabian[i][j]==1)
            count++;
        }
    }
    return count ;
    
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends