//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{

    public:
       bool possible(int n , vector<int>a , int k ,int w , int mid){
        
        for(int i =0;i <n ;i++)
        {
            if(a[i]<mid)
            {
                int daysleft=mid-a[i];
                if(daysleft>k)
                return false;
                 a[i]=mid;
                 k-=daysleft;
                
                 for(int  j=i+1;j<n && j<i+w;j++)
                 {
                     a[j]+=daysleft;
                 }
                
                
            }
        }
        return true;
    }
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
    
           int mini=INT_MAX;
           int maxi =INT_MIN;
            for(int i=0; i <n ;i++)
            {
                mini=min(mini, a[i]);
            }
     long long int  ans =0;
            int low = mini;
             int high= mini+k;
             while(low<=high){
                long long  int mid =low+(high-low)/2;
                  
                  if(possible(n , a , k , w , mid ))
                  {
                       ans =mid ;
                  low=mid+1;
                      
                  }
                  else
                  high=mid-1;
             }
    
       return ans ;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends