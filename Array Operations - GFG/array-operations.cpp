//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        if(n==1)
        return arr[0]!=0;
     
     
      int ind =0 ;
      while(ind<n && arr[ind]==0  )
      ind++;
       int ans =0;
     for(int i =ind;i<arr.size();i++)
     {
         if(arr[i]==0)
        {
            while(arr[i]==0)
            i++;

       ans++;
        }
     }
     if(arr[n-1]!=0)
     ans++;
     return ans; 
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends