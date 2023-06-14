//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
set<string >st;
  void	f(int ind , string S , string str, vector<int >&vis){
	    if(ind>=S.size())
	    {
	       st.insert(str);
	        return ; 
	    }
	    
	    for(int i=0; i <S.size();i++)
	    {
	       
	        if(vis[i]==1)
	        continue;
	        vis[i]=1;
	        f(ind+1, S, str+S[i],vis);
	        vis[i]=0;
	    }
	}
		vector<string>find_permutation(string S)
		{
		   vector<string >v ;
		   vector<int >vis(S.size(),0);
		   string str="";
		   f(0,S ,str,vis);
		   for(auto it:st)
		   v.push_back(it);
		   return v ;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends