//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
   bool f(int ind , int target ,int K,vector<int > &coins,vector<vector<vector<int>>>&dp){
       if(K==0 )
       {
           if(target==0)
           return 1;
           else
           return 0 ;
         
       }
       if(ind ==0)
       {
           if((target)%coins[ind]==0)
           {
               if((target/coins[ind])==K)
               return 1 ; 
               
           }
           return 0 ;
      }
      if(dp[ind][K][target]!=-1)
      return dp[ind][K][target];
       int nottake = f(ind -1 , target , K  , coins,dp);
       int take= 0; 
        if(coins[ind]<=target)
        {
             take = f(ind  , target-coins[ind], K-1 ,coins,dp);
        }
        
        return dp[ind][K][target]=take | nottake ;
       
   }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<vector<int >> > dp(N+1, vector<vector<int >> (K+1,vector<int>(target+1 ,-1)));
      return  f(N-1, target , K ,  coins,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends