//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
// int dp[50001][4];
// long long int  f(int ind , int  prev ,int r[],int g[],int b[],int &N){
 
//  if(ind == 0)
//  {
//      if(prev ==1)
//      {
//          return min(g[0],b[0]);
//      }
//      if(prev==2)
//      return min(r[0],b[0]);
//      if(prev==3)
//      return min(r[0],g[0]);
     
//      return 0; 
     
//  }
//  if(dp[ind][prev]!=-1)
//  return dp[ind][prev];
 
   
//     if(prev==1)
//     {
      
//       return dp[ind][prev]=min(b[ind]+f(ind -1 , 3,r,g,b,N),g[ind]+f(ind -1 ,2,r,g, b,N));
        
//     }
//     if(prev==2)
//     {
       
//       return dp[ind][prev]=min(r[ind]+f(ind-1, 1,r,g,b,N),b[ind]+f(ind-1, 3,r,g,b,N));
//     }
//     if(prev == 3)
//     {
      
//       return dp[ind][prev]=min(r[ind]+f(ind -1 ,1,r,g,b, N),g[ind]+f(ind -1 ,2,r,g,b,N));
//     }


// }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
// memset(dp, -1, sizeof(dp));
    //   return min(f(N-1, 1,r,g,b,N),min(f(N-1, 2,r,g,b,N),f(N-1, 3,r,g,b,N)));
      
    //   dp[0][1]=min(g[0],b[0]);
    //   dp[0][2]=min(r[0],b[0]);
    //   dp[0][3]=min(r[0],g[0]);
      
      vector<long long int> cur(4,0),prev1(4,0);
      prev1[1]=min(g[0],b[0]);
      prev1[2]=min(r[0],b[0]);
      prev1[3]=min(r[0],g[0]);
      for( int ind=1 ; ind<N ;ind++)
      {
          for(int prev=1; prev<=3 ; prev++)
          {
               if(prev==1)
    {
      
     cur[prev]=min(b[ind]+prev1[3],g[ind]+prev1[2]);
        
    }
    if(prev==2)
    {
       
  cur[prev]=min(r[ind]+prev1[1],b[ind]+prev1[3]);
    }
    if(prev == 3)
    {
      
   cur[prev]=min(r[ind]+prev1[1],g[ind]+prev1[2]);
    }

          }
          prev1 =cur;
      }
      
      return min(cur[1],min(cur[2],cur[3]));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends