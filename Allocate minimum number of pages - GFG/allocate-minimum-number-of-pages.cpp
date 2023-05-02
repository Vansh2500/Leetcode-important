//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool check(int mid , int A[],int n,int M){
        
         int sum =0;
         int count =1;
            // cout<<mid<<" ";
        for(int i =0;i<n;i++)
        {
         if(A[i]>mid)
         return false;
        //  cout<<sum<<"  ";
             if(sum+A[i]>mid)
             {
                 
               
                count++;
                sum=A[i];
                // cout<<sum<<" ";
             }
             else
            sum+=A[i];
            
           
        }
        
        if(count<=M)
        return true;
        else 
        return false;
        
    }
    int findPages(int A[], int N, int M) 
    {
        if(N<M)
        return -1;
        int sum =0;
         for(int i =0;i<N;i++)
         sum+=A[i];
        int low =A[0];
         int high =sum;
         
         int ans=INT_MAX;
         while(low<=high)
         {
             int mid =(low+high)/2;
             
             if(check(mid ,A, N,M))
                {
                    // cout<<mid<<" ";
                    high=mid-1;
                    // cout<<low<<"  ";
                    ans=min(ans,mid );
                }
                else
                {
                     low=mid+1;
                }
         }
         return ans; 
         
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends