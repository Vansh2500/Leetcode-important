//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
      
      sort(arr,arr+n);
         pair<int , int > ans;
   int low = 0 ;
    
    int high =n-1 ;
    int lower=0 ;
     while(low <=high)
     {
        int mid =low+(high-low)/2; 
        if(arr[mid]<=x)
        {
                     lower=mid ;
                     low =mid +1;
        }
        else
        {
            high= mid -1;
        }
     }
   if(lower==0 && arr[lower]>x) 
   {
        ans.first =-1;
   }
   else
       ans.first =arr[lower];
     
     low = 0 ; 
     high = n-1; 
     int upper= 0;
     while(low<=high)
     {
         int mid = low+(high-low)/2;
          if(arr[mid]<x)
          {
             low = mid +1; 
          }
          else
          {
               upper =mid ;
               high =mid-1;
          }
     }
      

      
      
if(upper ==0  && arr[upper]<x)
{
    ans.second=-1;
}
else
 ans.second = arr[upper];
    


       return ans ;
      

     
     
}