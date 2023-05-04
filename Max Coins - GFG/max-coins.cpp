//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges){
       sort(ranges.begin(), ranges.end());
       vector<int > v(n);
       int maxi=INT_MIN; 
       for(int i=n-1; i>=0 ;i--)
       {
           maxi =max(maxi, ranges[i][2]);
           v[i]=maxi ;
       }
       vector<int> store ;
       for(int i =0;i<n;i++)
       {
            store.push_back(ranges[i][1]);
            // cout<<store[i];
       }
      
       int  res=0;
      for(int i =0; i < n ;i++)
      {
         int low= i+1,high=n-1, mid , ans =ranges[i][2];  
         
         while(low<=high)
         {
             int mid = (low+high)/2;
              if(ranges[mid][0]>=ranges[i][1])
              {
                  high=mid-1;
                  ans =max(ans,ranges[i][2] + v[mid]);
              }
              else
              {
                  low =mid+1 ; 
              }
         }
         res=max(res, ans);
         
      }
      if(res==0)
      {
          for(int i =0;i<n;i++)
          res= max(res, ranges[i][2]);
          
      }
      return res;
      
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends