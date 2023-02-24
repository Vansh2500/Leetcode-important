class Solution {
public:
int count=0;
int ans =0;
int dfs(int row, int col,vector<vector<int>> &grid,int crossed ,int &n ,int &m){


if(row<0 || col< 0 || row>=n  || col>=m || grid[row][col]==3 || grid[row][col]==-1 )
return 0;
if(grid[row][col]==2)
{
    
 if(crossed-1==count){
 
 ans++;
    return true;

 }
return false;
}
grid[row][col]=3;
int  left =0, right=0 , up=0,down=0;
crossed++;
 left =dfs(row-1 ,col, grid,crossed,n,m);
  up =dfs(row , col+1,grid,crossed,n,m);
down =dfs(row +1 , col,grid,crossed,n,m);
 right= dfs(row  ,col-1 ,grid,crossed ,n,m);
 grid[row][col]=0;
 return left || right|| up ||down ;





}
    int uniquePathsIII(vector<vector<int>>& grid) {
        
int n = grid.size();
 int  m =grid[0].size();

      
  
        int row= 0 ;
        int col =0;
                 for(int i= 0; i<n ;i++)
                 {
                     for(int j =0; j < m ;j++)
                     {
                         if(grid[i][j]==0)
                         {
                             count++;
                         }
                         if(grid[i][j]==1)
                         {
                            row =i; 
                            col =j;
                         }
                     }
                 }
          
 int crossed =0;
        // dfs(row-1,col ,grid, crossed,n,m);
        //  dfs(row,col+1 ,grid, crossed,n,m);
        //   dfs(row+1,col ,grid, crossed,n,m);
        //    dfs(row,col-1,grid, crossed,n,m);
   dfs(row ,col ,grid ,crossed , n ,m);
        return ans ;
    }
};