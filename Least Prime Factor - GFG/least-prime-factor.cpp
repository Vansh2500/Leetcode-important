//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // we have to see the prime should divide the given number 
        // seie binary search 
        vector<pair<int ,int >> seive(n+1,{0, true} );
       
        
        vector<int > v; 
         for(int i=2 ;i*i<=n+1;i++)
         {
             
             if(seive[i].second==true){
             for(int j=i*i;j<=n+1;j+=i)
             {
                 if(seive[j].second==false)
                 continue ;
                 seive[j].second=false;
                 seive[j].first=i;
             }
             }
         }
         
         v.push_back(0);
         v.push_back(1);
         for(int i=2; i <=n ;i++)
        {
          if(seive[i].second==true)
          v.push_back(i);
          else
          v.push_back(seive[i].first);
         }
         return v; 
         
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends