//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

bool f(int applicant ,vector<vector<int>> &G,vector<int> &vis, vector<int> &jobs,int N ){
    
    for(int i=0;i<N;i++)
    {
         if(G[applicant][i]==1 && vis[i]!=1)
         {
             vis[i]=1;
              if(jobs[i]==-1)
              {
                  jobs[i]=applicant;
                  return true;
              }
              else if(f(jobs[i],G,vis,jobs, N))
              {
                   jobs[i]=applicant;
                    return true;
              }
         }
    }
    return false ;
    
}
	int maximumMatch(vector<vector<int>>&G){
	    // Code here
	    int M = G.size();
	    int N =G[0].size();
	     int ans= 0; 
	     vector<int>  jobs(N,-1);
	     for(int i =0; i < M ; i++)
	     {
	          vector<int> vis(N,0);
	          if(f(i, G,vis, jobs, N))
	          ans++;
	     }
	     return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>G(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> G[i][j];
		}
		Solution obj;
		int ans = obj.maximumMatch(G);
		cout << ans << "\n";    
	}
	return 0;
}
// } Driver Code Ends