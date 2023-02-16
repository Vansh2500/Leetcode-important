//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
int dfs(int ind , vector<int >&arr,vector<int >&v){
    
    if(ind>=arr.size() || ind<0)
    return 1 ;
    if(v[ind]!=-1)
    return v[ind];
    v[ind]=0;
    v[ind]=dfs(ind+arr[ind],arr,v);
    
    return v[ind];
}

    int goodStones(int n,vector<int> &arr){
vector<int >vis(n ,-1); 

int count =0; 

for(int i =0; i < n ; i++)
{
    if(vis[i]==-1)
    dfs(i,arr,vis);
}
for(int i =0; i < n;i++)
{
    if(vis[i]==1)
    count++;
}
return count ;
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
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends