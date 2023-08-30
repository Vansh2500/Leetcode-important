//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int i =0 ; 
    int j = 0; 
    int n =s.size();
    int count =0 ;
    int ans =-1;
    unordered_map<int ,int >mp;
    while(j<n)
    {
      
        while(j<n && mp.size()<=k)
        {
            
             mp[s[j]]++;
             j++;
        }
        // cout<<i<<" "<< j<<" e";
        if(mp.size()>=k)
        ans =max(ans, j-1-i);
       while(mp.size()>k)
        {
            mp[s[i]]--;
            if(mp[s[i]]==0){
            mp.erase(s[i]);
            // cout<<s[i]<<" "<<i;
                
            }
            i++;
        }
            //  cout<<i<<" "<< j<<" e";
       
    }
    if(mp.size()==k)
    {
        ans =max(ans, j-i);
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends