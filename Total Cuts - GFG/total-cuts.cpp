//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int >  suffix;
        int mini =INT_MAX;
        for(int i = N-1 ;i >=1;i--)
        {
             if(mini>=A[i])
             {
                 mini=A[i];
                 suffix.push_back(mini);
          
             }
             else
             suffix.push_back(mini);
        }
     
        reverse(suffix.begin(), suffix.end());
        //   for(auto it :suffix)
        // cout<<it<<"  "; 
        int maxi=INT_MIN;
        int ans =0 ;
        for(int i=0 ; i < N-1;i++)
            {
           
                 maxi=max(maxi,A[i]);
                  
                 int mini1=suffix[i];
                //  cout<<maxi<<"  "<<mini1<<"e";
                 if(mini1+maxi>=K)
                        ans++;
            } 
     
            return ans ; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends