//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int n ;
      bool isPalindrome(int start ,int end ,string &s){
      
        while(start<=end)
        {
            if(s[start++]!=s[end--])
            return false;
        }
        return true ;
    }
    int f(int ind ,string s,vector<int >&dp){
        if(ind>=n)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int sum =INT_MAX; 
        for(int i= ind; i <n;i++)
        {
           
            if(isPalindrome(ind ,i,s)){
            
                sum=min(sum , 1+f(i+1, s,dp));
            }
        }
        return dp[ind]=sum ;
        
    }
    int palindromicPartition(string str)
    {
       n=str.size();
       vector<int> dp(n+1,-1);
       return f(0, str,dp)-1;
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends