//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int getMinimumDays(int N,string S, vector<int> &P) {
// unordered_map<int , int > mp;
// for(int i =1;i< N;i++)
// {
//     if(S[i]==S[i-1])
//     mp[S[i]]=mp[S[i]]+2;
// }
// int count =0 ;
// for(int i =0;i <N;i++)
// {
//      int ch =S[P[i]];
//       if(mp[ch]>1)
//       {
//           mp[ch]--;
//           count++;
//       }
// }
    
//     return count ;
    
    
//     }
int count =0; 
for(int i =1; i< N;i++)
{
    if(S[i]==S[i-1])
    count++;
}
if(count==0)
return 0;

 for(int i =0; i <N;i++)
 {
     int ind= P[i];
     if(ind!=0 && S[ind]==S[ind-1])
     count--;
     if(ind!=N+1 && S[ind]==S[ind+1])
     count--;
     if(count==0)
     return i+1;
     
     S[ind]='?';
 }
return -1; 

}
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        string S;cin>>S;
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        int res = obj.getMinimumDays(N,S, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends