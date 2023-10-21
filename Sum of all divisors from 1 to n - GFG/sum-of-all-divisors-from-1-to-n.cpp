//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        // login for any number if we want to calculate the divisiors  we need to see that if a number is 87 and we want to see the number of divisors then 
        // lets take a number 23 and if we do 23  , 23 * 2 , 23*3 which is less than 87 means we are calculating the multiples of a number then number/i will
        // give the number of multiples
        long long sum =0 ;
       for(int i=1; i<=N;i++)
       {
           sum+=i*(N/i);
       }
       return sum ;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends