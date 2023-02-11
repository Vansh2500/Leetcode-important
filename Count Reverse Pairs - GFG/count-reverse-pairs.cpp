//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
 int  merge(int low ,int mid ,int high,vector<int> &arr){
      
      int j=mid+1 ;
      int count=0;
       for(int i =low ;i<=mid ;i++)
       {
        
           while( j<=high && arr[i]>2LL*arr[j])
           {
               j++;
           }
           count+=(j-(mid+1));
       }
       vector<int > v ;
        int left= low ,right =mid+1;
         while(left<=mid && right<=high)
         {
             if(arr[left]<=arr[right])
             {
                 v.push_back(arr[left]);
                 left++;
             }
             else
             {
                 v.push_back(arr[right]);
                 right++;
             }
         }
         
         while(left<=mid)
         {
             v.push_back(arr[left]);
             left++;
         }
         while(right<=high)
         {
             v.push_back(arr[right]);
             right++;
         }
         for(int i =low; i<=high;i++)
         {
             arr[i]=v[i-low];
         }
      
      return count ;
  }
 int  merge_sort(int low ,int high,vector<int > &arr){
      
      if( low >=high)
      return 0;
      int mid=(low + high)/2 ;
      int ans=merge_sort(low,mid ,arr);
     ans+= merge_sort(mid+1 ,high,arr);
      ans+=merge(low ,mid ,high ,arr);
      return ans ;
  }
    int countRevPairs(int n, vector<int> arr) {
      
     return merge_sort(0,n-1, arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends