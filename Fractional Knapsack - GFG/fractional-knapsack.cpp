//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    bool static cmp(pair<double ,double> &a ,pair<double ,double>&b){
        
        return a.first/a.second >b.first/b.second;
        
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double ,double> >v(n); 
        for(int i=0;i<n;i++)
        {
            v[i]={(double)arr[i].value, (double)arr[i].weight};
         
        }
        sort(v.begin(),v.end(), cmp);
           double ans =0 ;       
        for(int i=0;i<n;i++)
        {
           
             if(v[i].second <=W)
             {
                
                 ans+=v[i].first;
          
            W-=v[i].second;
             }
             else
             {
                 
                  ans+=(v[i].first/v[i].second )*(W);
             
                 break;
             }
                        
             
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends