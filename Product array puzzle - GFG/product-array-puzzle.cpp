//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
       
      vector<long long int > res(n);
    vector<long long int  >prefix(n,0 );
    vector<long long int >suffix(n ,0);
    if(n==1 )
    {
        return {1};
    }
    // if(n==2)
    // {
        
    // }
    long long int  mul=1, mul2 =1 ;
    for(int i=0;i <n;i++)
    {
        mul*=arr[i];
        mul2*=arr[n-1-i];
        prefix[i]=mul;
        suffix[n-1-i]=mul2;
    }
    for(int i=0; i< n ;i++)
    {
        if(i==0)
        res[i]=suffix[i+1];
        else if(i==n-1)
        res[i]=prefix[i-1];
        else
        res[i]=prefix[i-1] *suffix[i+1];
    }   
    return res;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends