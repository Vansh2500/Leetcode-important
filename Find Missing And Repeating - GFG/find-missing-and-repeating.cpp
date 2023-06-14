//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {

    int missing =0;
    int repeating =0;
    for(int i =0; i<n;i++)
    {
        while(arr[i]-1!=i)
        {
            swap(arr[arr[i]-1],arr[i]);
                        if (arr[arr[i] - 1] == arr[i]) {
                        
                          break;
                        }
                }
    }
    for(int i=0;i<n;i++)
    {
        // cout<<arr[i]<<" ";
        if(arr[i]-1!=i)
        {
            repeating =arr[i];
            missing =i+1;
            break;
        }
    }
    return {repeating ,missing };
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends