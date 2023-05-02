//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
    bool check(int mid , vector<int >&sweetness,  int N ,int K){
        
        int sum =0;
         int count =0;
         for(int i =0;i<N;i++)
        {
        //  if(sweetness[i]>mid)
        //  return false;
        //  cout<<sum<<"  ";
             if(sum+sweetness[i]>=mid)
             {
                 
               
                count++;
                sum=0;
                // cout<<sum<<" ";
             }
             else
            sum+=sweetness[i];
            
           
        }
    //   cout<<count<<" ";
        
        if(count<K)
        return false;
        else 
        return true;
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    int sum=0;
 
    if(N<K)
    return -1;
     int low = 0;
    for(int i =0;i<N;i++){
        low =min(sweetness[i], low);
    
    sum+=sweetness[i];
    }    
   
    int high= sum ;
    int ans=-1;
     while(low<=high)
     {
         
         int mid = (low+ high)/2;
        //  cout<<mid;
          if(check(mid ,sweetness, N,K+1))
          {
            //   cout<<mid<<"  ";
            ans=mid;
              low =mid+1; 
            
          }
          else{
            //   cout<<mid<<" ";
         high =mid-1;
          }
     }
     return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends