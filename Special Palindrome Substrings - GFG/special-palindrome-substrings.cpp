//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    
    int palindrome(int start ,int end ,string s1,string s2){
        
        int i =0 ;
        int j =s1.size()-1;
         int i2 =0 ;
          int j2=s2.size()-1;
         int operations=0;
        while(i<j)
        {
            if((i< start  && j>end) || i> end || j<start )
            {
                if(s1[i]!=s1[j])
                operations++;
              
            }
            else if( j>end){
                if(s1[j]!=s2[i2])
                operations++;
                i2++;
     
            }
            else if(  i <start){
                 if(s1[i]!=s2[j2])
                 {
                     operations++;
                 }
                 j2--;
                
            }
            else 
            {
                if(s2[i2]!=s2[j2])
              return INT_MAX;
                i2++;
                j2--;
               
            }
             i++;
                j--;
            
        }
        return operations;
    }
    

    int specialPalindrome(string s1, string s2){
        
     if(s2.size()>s1.size())
     return -1;
 int ans =INT_MAX;
 for(int i = 0; i<= s1.size()-s2.size();i++)
 {
     int start = i ;
      int end= i+s2.size()-1 ;
      
int k=0;

int operations=0;
      for(int j = start ;j<=end ;j++)
      {
if(s1[j]!=s2[k])
{
operations++;
}
k++;
      }

      int t=palindrome(start ,end ,s1, s2);
      if(t==INT_MAX)
    operations=INT_MAX;
      else
      operations+=t;
      ans=min(operations, ans );
      
     
 }
 if(ans==INT_MAX)
 return -1;
 return ans ;
     
     
    }
//   int specialPalindrome(string s1, string s2){
//         //Code Here
//         int ans = INT_MAX;
//         for(int i=0;i<=s1.length()-s2.length();i++){
//             int start = i;
//             int end = i+s2.length()-1;
//             int temp = 0;
//             int k = 0;
//             for(int j=start;j<=end;j++){
//                 if(s1[j]!=s2[k])temp++;
//                 k++;
//             }
//             int t = palindrome(start ,end ,s1, s2);
//             if(t==INT_MAX)temp=INT_MAX;
//             else temp+=t;
//             ans = min(ans,temp);
//         }
//         if(ans==INT_MAX)return -1;
//         return ans;
//     }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends