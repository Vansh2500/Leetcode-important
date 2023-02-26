//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool bfs(int node ,vector<int > &vis ,vector<vector<int > >&adj){
      vis[node]=1 ;
      queue<int > qu;
      qu.push(node);
    
      int nodes =0 ;
      int flag =1;
    int edges=adj[node].size();
       while(!qu.empty())
       {
           int  currnode =qu.front(); 
           qu.pop();
            nodes++;
            if(edges!=adj[currnode].size())
            flag= 0;
            for(auto it :adj[currnode])
            {
            if(vis[it])
            continue; 
            vis[it]=1; 
            qu.push(it);
            }
            
            
           
       }
       return flag && nodes ==edges+1;
      
  }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
       vector<int> vis(V+1,0);
       
      int count = 0; 
       for(int i=1; i <=V;i++)
       {
           if(!vis[i])
           {
               
              if(bfs(i , vis ,adj))
              count++;
           }
       }
       return count ; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends