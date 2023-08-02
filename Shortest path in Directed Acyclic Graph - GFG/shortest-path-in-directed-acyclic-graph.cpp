//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<pair<int ,int >> adj[N];
         for(int i =0 ; i <M;i++)
         {
             int u =edges[i][0];
             int v= edges[i][1];
             int dis =edges[i][2];
             adj[u].push_back({v,dis});
         }
  
    priority_queue<pair<int ,int >, vector<pair<int,int >> ,greater<pair<int ,int >>>pq;
    pq.push({0,0});
     vector<int >distance(N,INT_MAX);
     distance[0]=0;
     while(!pq.empty())
     {
         int node =pq.top().second; 
         int dis= pq.top().first;
          pq.pop();
          for(auto it :adj[node])
          {
              int adjnode =it.first;
              int adjdis =it.second;
              if(dis+adjdis <distance[adjnode])
              {
                  distance[adjnode]=dis+adjdis;
                  pq.push({adjdis+dis,adjnode});
              }
              
          }
     }
     for(int i= 0; i <N;i++)
     {
         if(distance[i]==INT_MAX)
         distance[i]=-1;
     }
     return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends