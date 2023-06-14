//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    void dfs(int node ,vector<int >adj[], vector<int >&vis, stack<int >&st){
        vis[node]=1;
         for(auto it:adj[node])
         {
             if(!vis[it])
             dfs(it, adj ,vis ,st);
         }
         st.push(node);
    }
     void dfs2(int node ,vector<int >adj[], vector<int >&vis){
        vis[node]=1;
         for(auto it:adj[node])
         {
             if(!vis[it])
             dfs2(it, adj ,vis);
         }
         
    }
    int kosaraju(int V, vector<vector<int>>& adjj)
    {
        //time of finish 
        
        // reverse edges 
        // traverse 
        vector<int > adj[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adjj[i].size();j++)
            {
                adj[i].push_back(adjj[i][j]);
            }
        }
        
        stack<int >st ;
        vector<int > vis(V,0);
        for(int i =0;i<V;i++)
        {
            if(!vis[i])
            dfs(i,adj, vis, st);
        }
        vector<int >revadj[V];
         for(int i=0;i<V;i++)
         {
             vis[i]=0;
             for(auto it :adj[i])
             {
                 revadj[it].push_back(i);
             }
         }
         int strongcomponents=0;
         while(!st.empty())
         {
             int top=st.top();
             st.pop();
             
                 if(!vis[top]){
             strongcomponents++;
             dfs2(top, revadj,vis);
             
             }
         }
         return strongcomponents;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends