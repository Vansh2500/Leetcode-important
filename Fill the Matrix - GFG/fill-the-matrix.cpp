//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
       queue<pair<int ,int > > qu ;
        qu.push({x-1,y-1});
        vector<vector<int>> v(N ,vector<int> (M,0));
        v[x-1][y-1]=1; 
        vector<int >  delrow ={-1,0,1,0};
        vector<int>delcol ={0,1,0,-1};
        int count= 0; 
        while(!qu.empty())
        {
            
            int size =qu.size() ; 
            while(size--){
            int row = qu.front().first ;
             
             int  col =qu.front().second ;
               qu.pop();
               
                for(int i=0; i< 4;i++)
                {
                    int nrow = row+delrow[i];
                    int ncol =col+delcol[i];
                    
                    if(nrow >=0  && nrow< N && ncol >=0 && ncol <M && v[nrow][ncol]==0 )
                    {
                       
                     
                        v[nrow][ncol]=1; 
                        qu.push({nrow ,ncol});
                    }
                        // count++;
                }
            }
            count++;
             
            
               
        }
        
        return count-1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends