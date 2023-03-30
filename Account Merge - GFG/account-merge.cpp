//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{

	public :
		vector<int> rank,parent;
	DisjointSet(int n )
	{
		rank.resize(n+1,0);
		parent.resize(n+1,0);
		for(int i=0; i<=n;i++)
		{
			parent[i]=i;
		}
	}
       int findparent(int node){
       	if(node==parent[node])
       		return node;
       	 return parent[node]=findparent(parent[node]);
       }

       void unionByRank(int u, int v){
       	int ult_u=findparent(u);
       	int ult_v=findparent(v);

         if(ult_v==ult_u)
         	return ;

         if(rank[ult_u]<rank[ult_v]){
             parent[ult_u]=ult_v;
         }
         else if(rank[ult_v]>rank[ult_u]){
parent[ult_v]=ult_u;
         }
         else
         {
         	parent[ult_v]=ult_u;
         	rank[ult_u]++;
         }

       }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
      int n =accounts.size();
      DisjointSet ds(n) ;
      unordered_map<string ,int >mp;
       for(int i =0;  i < n;i++)
       {
           for(int j =1 ;j<accounts[i].size();j++)
           {
               if(mp.find(accounts[i][j])==mp.end())
               {
                   mp[accounts[i][j]]=i;
               }
               else
               {
                   ds.unionByRank(i, mp[accounts[i][j]]);
               }
           }
       }
     vector<string > v[n]; 
     for(auto it : mp )
     {
        int node=  ds.findparent(it.second);
        v[node].push_back(it.first);
         
        
     }
     
     vector<vector<string> > ans; 
     for(int i= 0 ; i <n; i++)
     {
         if(v[i].size()==0)
         continue;
          sort(v[i].begin(),v[i].end());
         vector<string > temp;
         temp.push_back(accounts[i][0]);
         for(auto it :v[i])
         {
             temp.push_back(it);
         }
         ans.push_back(temp);
     }
     return ans;
       
       
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends