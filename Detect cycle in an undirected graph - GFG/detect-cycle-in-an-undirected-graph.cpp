//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
 bool f(int start , vector<int> adj[] , vector<int> &vis){
      vis[start]=1; 
      queue<pair<int, int >> qu;
       qu.push({start  ,-1 });
       while(!qu.empty())
       {
           int node =qu.front().first;
            int parent  = qu.front().second ;
             qu.pop();
            
              for(auto it : adj[node])
              {
                  if(!vis[it])
                  {
                      vis[it]=1 ;
                      qu.push({it, node} );
                  }
                  else if(parent!= it){
                      return true;
                  }
            
              }
       }
       return false;
 }
 
    bool isCycle(int V, vector<int> adj[]) {
     
vector<int> vis(V,0);

for(int i =0 ; i<V;i++)
{
    if(!vis[i])
{
    if(f(i, adj ,vis))
    return true;
}
}
return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends