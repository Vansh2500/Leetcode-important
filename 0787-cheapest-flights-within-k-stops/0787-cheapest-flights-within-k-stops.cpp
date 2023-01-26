class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int >> adj[n];
        for(auto it :flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        // priority_queue<pair<int, pair<int,int>>,vector<int ,pair<int,int>> ,greater<pair<int,pair<int,int>>> pq;;
queue<pair<int , pair<int ,int >>> qu;
    qu.push({0,{src,0}});
    vector<int> dis(n,INT_MAX);
    dis[src]=0;
    while(!qu.empty())
    {
        int stops =qu.front().first;
        int node= qu.front().second.first;
         int wt=qu.front().second.second;
          qu.pop();
          if(stops>k)
          continue;
          for(auto it :adj[node])
          {
              int adjnode =it.first;
              int adjwt=it.second;
              if(wt+adjwt<dis[adjnode] && stops<=k)
              {
                  dis[adjnode]=wt+adjwt;
                  qu.push({stops+1,{adjnode,wt+adjwt}});
              }

               
          }
    }

    if(dis[dst]==INT_MAX)
    return -1 ;
    return dis[dst];
    }
};