//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   bool ispalindrome(string s ){
        int start =0 ;
        int end= s.size()-1;
         while(start <end)
         {
             if(s[start++]!=s[end--])
             return false;
         }
         return true;
   }
    bool makePalindrome(int n,vector<string> &arr){
    
      unordered_map<string ,int >  mp;
      for(int i =0; i < n ;i++)
      {
         string s=arr[i];
         reverse(s.begin() ,s.end());
         if(mp.find(s)!=mp.end())
         {
           
             mp.erase(s);
         }
         else
         {
             mp[arr[i]]++;
        
         }
      }
      
    //   for(auto it:mp)
    //   {
    //       cout<<it.first <<" ";
    //   }
           if(n%2==0)
           {
               if(mp.size()==0)
               return true;
               else
               return false;
           }
           else
           {
               if(mp.size()==1)
               {
                   string s="";
                   for(auto it:mp)
                   {
                        s=it.first;
                        
                   }
                  
                   if(ispalindrome(s))
                   return true;
                   else
                   return false;
               }
               else
               return false;
           }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends