//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
bool f(int node , int &count ,vector<int >adj[] ,vector<int> &vis){
  vis[node]=1;
  bool count1 =false  ; 
     for(auto it :adj[node])
     {

         
        if(!vis[it])
        {
            
      bool javak=  f(it,count,adj, vis);
        if(javak==false)
        count1=true;
        }
     }
     if(count1)
     count++;
     return count1;
      
  }
    int countVertex(int N, vector<vector<int>>edges){
    vector<int> adj[N+1];
    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
    }
    
    int count =0 ;
    vector<int> vis(N+1,0);
    f(1,count,adj ,vis);

    return count ;
    
    }
    
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends