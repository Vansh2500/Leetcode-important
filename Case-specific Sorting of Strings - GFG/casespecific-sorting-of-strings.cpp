//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
  
    string caseSort(string str, int n)
    { 
        string s1="";
        string s2="";
     
     for(int i =0 ;i < n;i++)
     {
         if(str[i]>='a' && str[i]<='z')
         s1.push_back(str[i]);
         else
         s2.push_back(str[i]);
     }
   
   
     sort(s1.begin(),s1.end());
     sort(s2.begin(),s2.end());
     int j=0, k=0;
     for(int i =0 ;i < n;i++)
     {
         if(str[i]>='a' && str[i]<='z'){
      str[i]=s1[j];
         j++;
             
         }
         else{
      str[i]=s2[k];
         k++;
             
         }
     }
     return str;
  
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends