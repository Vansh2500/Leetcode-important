//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
    stack<int > st ;
    
     vector<int >  v;
     v.push_back(-1);
    st.push(a[0]);
     for(int i =1;i< n ; i++)
     {
      
      if(!st.empty() )
          {
               while(!st.empty() && st.top()>=a[i])
               {
                   st.pop();
               }
               if(!st.empty())
               v.push_back(st.top());
               else
               v.push_back(-1);
               
          }
      st.push(a[i]);
      
         
     }
     return v ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends