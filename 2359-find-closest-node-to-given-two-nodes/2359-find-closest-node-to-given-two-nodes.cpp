class Solution {
public:

void dfs(int node,vector<int > &distance ,vector<int> &visited, vector<int> adj[] ){
 visited[node]=1;

  for(auto it :adj[node])
  {
      if( it!=-1 && !visited[it])
      {
        
         distance[it]=distance[node]+1;
         dfs(it, distance ,visited, adj); 
   
      }
  }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n= edges.size();
        vector<int> adj[n];
        for(int i = 0;i<n ;i++)
        {
            adj[i].push_back(edges[i]);
        }

           vector<int> shortd1(n,0);
            vector<int> shortd2(n,0);
vector<int> visited(n,0);
vector<int>visited1(n,0);
            dfs(node1,shortd1,visited,adj);
            dfs(node2 ,shortd2 ,visited1 ,adj);
int ans = -1; 
int curdistance= INT_MAX;
            for(int i =0 ; i < n;i++)
            {
                
          if(visited[i]==true && visited1[i]==true && curdistance>max(shortd1[i],shortd2[i])){
    
           
           cout<<shortd1[i]<<" "<<shortd2[i]<<" "<<i<<"    ";
             
                    curdistance=max(shortd1[i],shortd2[i]);;
                    // cout<<curdistance;
                    ans=i;
                
                
                }
          }
            

            return ans;
    }
};