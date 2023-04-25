//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
    
    int n = arr.size();
      vector<pair<int ,int >> v; 
      stack<pair<int ,int >> st;
   
        for(int i =0; i <  n;i++)
        {
            
                 while(!st.empty() && st.top().first >=arr[i] )
                 {
                     st.pop();
                 }
                 if(!st.empty() )
                 v.push_back({st.top().first, st.top().second});
                 else
                 v.push_back({-1,i});
             
             st.push({arr[i],i});
        }
       
            vector<pair<int ,int >> v1; 
      stack<pair<int ,int > >st1;
    //   v1.push_back({-1, n-1});
      for(int i=n-1 ; i >=0 ;i--)
      {
          
                while(!st1.empty() && st1.top().first >=arr[i])
                {
                    st1.pop();
                }
                if(!st1.empty())
                v1.push_back({st1.top().first , st1.top().second});
                else
                v1.push_back({-1, i});
          st1.push({arr[i],i});
          }
      reverse(v1.begin(), v1.end());
      
      vector<int> ans; 
      for(int i =0;i <n ;i++)
     {
        //  cout<<v[i].first <<"first"<<v[i].second<<endl;
        //  cout<<v1[i].first<<"second"<<v1[i].second<<endl;
      if(v[i].first==-1 && v1[i].first==-1)
      {
          ans.push_back(-1);
          continue;
      }
      else if(v[i].first==-1)
      {
          ans.push_back(v1[i].second);
          continue;
      }
      else if(v1[i].first==-1){
          ans.push_back(v[i].second);
          continue;
      }
      else  if(i-v[i].second==v1[i].second-i)
         {
             if(v[i].first<=v1[i].first)
             {
                 ans.push_back(v[i].second);
             } 
             else
              ans.push_back(v1[i].second);
         }
         else if(i-v[i].second<v1[i].second-i){
             ans.push_back(v[i].second);
             
         }
         else
         ans.push_back(v1[i].second);
     }
      
      return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends