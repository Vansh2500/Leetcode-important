class Solution {
public:
// int dp[1050][1050];
bool f(int i , int j,string &s , string &p,vector<vector<int>> &dp){
 if(i==0 && j==0)
 return true;
 if(j==0)
 return false; 
 if(i==0)
 {
    
     for(int ind =0; ind <=j-1;ind++)
     {
         if(p[ind]!='*')
         return false;
     }
     return true;
 }
 int &r=dp[i][j];
 if(r!=-1)
 return r;

bool ans= false;
    if(s[i-1]==p[j-1] || p[j-1]=='?')
    {
        ans=f(i-1 ,j-1,s, p,dp);
    }
    else if(p[j-1]=='*'){
      ans= ans|| f(i-1,j,s,p,dp);
      ans=ans|| f(i,j-1, s,p,dp);
          }

          return r=ans ;

}
    bool isMatch(string s, string p) {
        // memset(dp,-1, sizeof(dp));
        int n  =s.size();
        int m =p.size();
        vector<vector<int>> dp(n+2, vector<int>(m+2, -1));
      return   f(s.size(), p.size(), s, p,dp);

//    dp[0][0]=1; 
// //    for(int j = 1 ; j <= m;j ++){
// //    int  flag =1;
  
// //      for(int ind =0; ind <=j-1;ind++)
// //      {
// //          if(p[ind]!='*')
// //        flag=0;
// //       break;
// //      }
// //      dp[0][j] =flag;
// //    }
//   for (int j = 0; j <m && p[j] == '*'; j++) {
//             dp[0][j + 1] = true;
//         }

//    for(int i =1 ; i <= n ;i++)
//    {
// for(int j =1 ;j<=m ;j++)
// {
//     // bool ans= false;
//     // if(s[i-1]==p[j-1] || p[j-1]=='?')
//     // {
//     //     ans=dp[i-1][j-1];
//     // }
//     // else if(p[j-1]=='*'){
//     //   ans= ans|| dp[i-1][j];
//     //   ans=ans|| dp[i][j-1];
//     //       }

//     //     dp[i][j]=ans ;
//      if (p[j - 1] == '*') {
//                     dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
//                 } else if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
//                     dp[i][j] = dp[i - 1][j - 1];
//                 }
// }
//    }

//    return dp[n][m];
    }
};