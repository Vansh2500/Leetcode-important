//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
    // if(s.size() <= 3)
    //         return s.size();
            
    //     int ans = INT_MAX;
    //     string str = "";
        
    //     for(int i=0; i<s.size(); i++){
            
    //         str = str + s[i];
    //         string temp = s.substr(i+1, str.size());
            
    //         if(temp == str){
    //             int ctr = str.size() + 1 + (s.size() - str.size()*2);
    //             ans = min(ans, ctr);
    //         }
    //     }
        

    //     return ans;
      string t;
        int ans=s.size();
        int n =s.size();
        for(int i=n/2-1;i>=0;i--){
            string t1=s.substr(0,i+1);
            string t2=s.substr(i+1,t1.size());
           
            if(t1==t2){
             
                ans=min(ans,(int)(1+n-t1.size()));
               
                break;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends