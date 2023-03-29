//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
      int count = 0 ;
     
     int n=S.size();
     for(int i =0; i < n ;  i++)
     {
          int upper = 0 ;
      int lower= 0 ;
         for(int j= i; j  <n;j++)
         {
             if(S[j]>='A' && S[j]<='Z')
             {
                 upper++;
             }
             else
             {
                 lower++;
             }
             if(upper==lower)
             count++;
         }
         
     }
       return count; 
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends