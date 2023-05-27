//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DSU{
    public:
        vector<int >parent,size;
        DSU(int n ){
             parent.resize(n);
             size.resize(n);
             for(int i =0;i<n;i++)
             {
                 parent[i]=i;
                 size[i]=0;
             }
        }
        
        int findparent(int node )
        {
            if(parent[node]==node)
            {
                return parent[node];
                
            }
            
            return parent[node]=findparent(parent[node]);
        }
        
        void UnionBySize(int u , int v ){
             
             int ult_u= findparent(u);
             int ult_v=findparent(v);
             
             if(size[ult_u]>size[ult_v])
             {
                 parent[ult_v]=ult_u;
                 size[ult_u]+=size[ult_v];
             }
             else
             {
                 parent[ult_u]=ult_v;
                 size[ult_v]+=size[ult_u];
             }
             
             
             
        }
    };
class Solution
{
    
    
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    DSU ds(V) ;
	    vector<int > vis(V,0);
	     
	     for(int i =0;i<V;i++)
	     {
	         vis[i]=1 ;
	         
	         for(auto it:adj[i])
	         {
	             if(vis[it]==1)
	             continue; 
	            
	               if(ds.findparent(it)!=ds.findparent(i)){
	                   
	               ds.UnionBySize(it, i);
	               }
	               else
	               return true; 
	         }
	     }
	     return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends