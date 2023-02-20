//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

// int f(int n ,char  ch){
    
//     if(n==0 && ch!='O' )
//     return 0;
//      if(n==0 && ch=='O')
//      return 1; 
//     int ans =0 ; 
//      if(ch =='O')
//     {
//         ans=(ans+f(n-1 , 'A'));
//         ans=(ans+f(n-1, 'B'));
//          ans =(ans+f(n-1,'C'));
    
    
//     }
//         if(ch=='A')
//         {
//             ans=(ans+f(n-1,'O'));
//             ans=(ans+f(n-1, 'B'));
//             ans=(ans+f(n-1,'C'));
//         }
//         if(ch=='B')
//         {
//             ans=(ans+f(n-1, 'O'));
//             ans=(ans+f(n-1 ,'A'));
//             ans=(ans+f(n-1, 'C'));
//         }
        
//         if(ch=='C')
//         {
//             ans=(ans+f(n-1 , 'O'));
//             ans =(ans + f(n-1 ,'A'));
//             ans =(ans + f(n-1 ,'B'));
//         }
//         return ans ;;  
    
// }

    int countPaths(int N){
// return        f( N,'O');
int mod =1e9+7;

// vector<vector<long long > > dp(N+1,vector<long long  > (5,0));

// dp[0][0]=1;
vector<int > cur( 4, 0),prev(4,0);
prev[0]=1 ;
for(long long  n=1; n<=N;n++)
{
    for(int   ch =3 ;ch>=0 ;ch--)
    {
       long long  ans =0 ; 
     if(ch ==0)
    {
       ans= (ans%mod+prev[1]%mod +prev[2]%mod +prev[3]%mod)%mod;
    
    
    }
        if(ch==1)
        {
           ans =(ans%mod+prev[0]%mod+prev[2]%mod+prev[3]%mod)%mod;
        }
        if(ch==2)
        {
            ans =(ans%mod+prev[0]%mod+prev[1]%mod+prev[3]%mod)%mod;
        }
        
        if(ch==3)
        {
            ans =(ans%mod+prev[0]%mod+prev[1]%mod+prev[2]%mod)%mod;
        }
     cur[ch]=ans%mod;;  
    }
    prev= cur;
    
}




return cur[0]%mod;


    }
    
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends