class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
         int m =grid[0].size();
          
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i =0;i < n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                continue;
                dp[i][j]=1e5;
                if(i-1>=0)
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                if(j-1>=0)
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }

        }
int ans= -1;
        for(int i=n-1; i>=0;i--)
        {
            for(int j =m-1 ;j>=0 ;j--)
            {
                 if(grid[i][j]==1)
                continue;
                if(i+1<n)
                dp[i][j]=min(dp[i][j],dp[i+1][j]+1);
                if(j+1<m)
                dp[i][j]=min(dp[i][j],dp[i][j+1]+1);
  ans=max(ans,dp[i][j]);
            }
        }
        if(ans==1e5)
        return -1;
        else 
        return ans;
    }

};