//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    bool static cmp(struct val &a ,struct val &b){
     
      return a.first < b.first;
    
    }
    int maxChainLen(struct val p[],int n){
     
     sort(p,p+n, cmp);
     
 int count =1; 
     int mini= p[n-1].first; 
      for(int i = n-2; i >=0 ;i--)
      {
            if(mini> p[i].second)
            {
                mini=p[i].first;
                count++;
            }
      }
     
     return count ; 
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends