//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod =1e9+7;
    //Function to count the number of ways in which frog can reach the top.
    long long  f(int n,vector<long long >&v){
        if(n==0)
        return 1;
        if(n<0)
        return 0;
        if(v[n]!=-1)
        return v[n];
        long long  take1=f(n-1,v);
       long long take2=f(n-2,v);
        long long take3=f(n-3,v);
        return v[n]=(take1%mod+take2%mod+take3%mod)%mod;
        
    }
    long long countWays(int n)
    {
        vector<long long >v(n+1,-1);
        return f(n,v)%mod;
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends