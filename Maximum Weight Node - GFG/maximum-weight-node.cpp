//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
   unordered_map<int ,int > mp;
     for(int i=0 ; i<N; i++)
     {
         if(Edge[i]!=-1)
         mp[Edge[i]]+=i;
     }
     int maxi =0;
     int ind=-1 ;
     for(auto it :mp)
     {
    if(maxi<=it.second)
    {
        maxi =it.second;
        ind=it.first;
    }
   
       
     }
     if(ind ==-1)
     return 0;
     return ind ;
     }
  
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends