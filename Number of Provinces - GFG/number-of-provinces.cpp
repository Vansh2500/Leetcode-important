//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DSU{
    // vector<int >rank ,parent; 
    public :
    vector<int > size,parent;
    
     DSU(int n )
     {
     // rank.resize(n+1, 0);
        size.resize(n,1);

     parent.resize(n);
        for(int i =0 ; i<n;i++)
        {
            parent[i]=i;
        }

     }
    int findparent(int node )
          {
            if(node==parent[node])
                return node;
             return parent[node]=findparent(parent[node]);
          }

          void UnionBySize(int u ,int v ){

             int ulp_u=findparent(u);
             int ulp_v=findparent(v);
       
             if(ulp_v==ulp_u)
             {
                      return ; 
             }
         if(size[ulp_u ] < size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
             }
             else
             {
             parent[ulp_v]=ulp_u;
 size[ulp_u]+=size[ulp_v];
             }
          }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int  n =adj.size();
        int m = adj[0].size();
        
       DSU ds(V);
      
       for(int i =0;i<n;i++)
       {
           for(int j=0;j<m;j++) 
       {
           if(adj[i][j]==0 )
           continue;
           
            if(ds.findparent(i)!=ds.findparent(j))
            {
                ds.UnionBySize(i,j);
            }
       }
       }
       int count =0;
  for(int i =0;i<V;i++)
  {
      
      if(ds.parent[i]==i)
      count++;
  }
    
    return count ;
     
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends