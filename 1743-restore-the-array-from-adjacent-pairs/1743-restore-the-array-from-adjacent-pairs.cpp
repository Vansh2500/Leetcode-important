class Solution {
public:

void dfs(int node , int prev , vector<int> &v ,unordered_map<int,vector<int>> &mp){

v.push_back(node);
for(auto it:mp[node])
{
    if(it!=prev )
    dfs(it, node ,v ,mp);
}

}
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int> > mp;
       for(auto it :adjacentPairs)
       {
           mp[it[0]].push_back(it[1]);
           mp[it[1]].push_back(it[0]);
       }
       int start=0;
for(auto it :mp)
{
    if(it.second.size()==1 ){
    start = it.first;

    break;
    }
}
vector<int> v ;
       dfs(start ,-1,v, mp);
       return v ;
    }
};