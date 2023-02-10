//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
       
      unordered_map<char,int  > mp;
      for(auto it :s )
      mp[it]++;
    int mini =INT_MAX;
     int mini1=INT_MAX;
    for(auto it : mp)
    {
     mini=min(mini,min(mp['l'],mp['o']));
    mini1=min(mini1,min(mp['b'],min(mp['a'],mp['n'])));
    
    }
    
    // cout<<mini<<mini1;

     if(mini%2!=0)
     {
         mini=mini-1;
      
     }
    mini1=mini1*2;
    if(mini1==mini)
    {
        return mini1/2;
    }
    if(mini1>mini)
    {
        return mini/2;
    }
    else
    {
        return mini1/2;
    }
    
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends