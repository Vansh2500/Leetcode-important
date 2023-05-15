//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
   int count =1;
   long long n=N; 
    long long ans= 0;
    while(n!=0)
    {
        long long  temp  =  (N+1)/(count*2);
        
        ans+=temp*count;
       temp=(N+1)/count;
       if(temp%2==1)
       ans+=(N+1)%count;
       
         count*=2;
         n>>=1 ;
    }
    return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends