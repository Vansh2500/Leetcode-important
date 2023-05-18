//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    bool static cmp(vector<int >&a, vector<int >&b)
    {
        return a[0]<b[0];
    }
    
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
      sort(range.begin(), range.end(), cmp);
  
      
      int prev= 0; 
      for(int i =1 ;i<n;i++)
      {
          if(range[i][0]<=range[prev][1])
          {
            range[prev][1]=max(range[prev][1], range[i][1]);
          }
          else
          {
              prev++;
            range[prev]=range[i];
          }
      }
      range.resize(prev+1);
    //   for(auto it:range)
    //   cout<<it[0]<<it[1]<<" ";
      vector<int > v; 
      int j =0;
      while(q--)
      {
          int k=queries[j];
          
          for(int i =0;i<prev+1;i++)
          {
              if(range[i][1]-range[i][0]+1 >=k)
              {
                //   cout<<range[i][1]-range[i][0]<<" ";

               v.push_back(range[i][0]+k-1);
                  k=0;
                  break;
              }
              else
              {
                  k=k-(range[i][1]-range[i][0]+1);
              }
            //   cout<<k<<"  ";
          }
          if(k!=0)
          v.push_back(-1);
          j++;
      }
      return v;
       
    } 
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends