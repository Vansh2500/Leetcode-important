//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s,int m)
        {
            int ans =0; 
        int n =s.size(); 
        vector<int >pre(n);
        pre[0]=1;
        for(int i=1; i <n;i++)
        {
            pre[i]=((int )pre[i-1]*2)%m;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
              
              ans=(ans+pre[n-i-1])%m;
                
            }
        }
        return ans%m; 
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends