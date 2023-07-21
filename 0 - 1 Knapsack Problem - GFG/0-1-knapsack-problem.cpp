//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
     
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int ind ,int wt[], int val[],int n ,int weight,int W,vector<vector<int >>&v){
        
        if(ind==n)
        return 0 ; 
    int nottake=    f(ind+1 ,wt, val, n,weight,W,v);
        int take= 0;
        if(v[ind][weight]!=-1)
        return v[ind][weight];
        if(wt[ind]+weight<=W)
         take =val[ind]+f(ind+1, wt ,val , n,weight+wt[ind],W,v );
         
         return v[ind][weight]=max(take, nottake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int >>v(n+1, vector<int >(1000,0));
    //   return f(0, wt, val, n, 0,W,v);
    for(int ind= n-1 ;ind>=0;ind--)
    {
        for(int weight =W; weight>=0;weight--)
        {
               int nottake=   v[ind+1][weight];
        int take= 0;
     
        if(wt[ind]+weight<=W)
         take =val[ind]+v[ind+1][weight+wt[ind]];
         
        v[ind][weight]=max(take, nottake);
        }
    }
    return v[0][0];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends