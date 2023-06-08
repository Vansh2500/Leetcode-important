//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	set<string  > st;
	void f(int ind , string s ,vector<int >v , string S,int  n ){
             if(ind>=n){
                 st.insert(s);
             return ;
             }
             
             
             for(int i =0;i<n;i++)
             {
                if(v[i]==1 )
                continue ; 
                v[i]=1 ;
                
                 f(ind+1 , s+S[i] , v,S,n);
                 v[i]=0;
             }
             
             
             	    
	}
		vector<string>find_permutation(string S)
		{
		    int n=S.size();
		    vector<string > ans ;
		    vector<int >v(S.size(), 0);
		    string s ="";
		     f(0 ,s , v ,S,n);
		     for(auto it :st)
		     ans.push_back(it);
		     return ans; 
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