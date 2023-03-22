//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

void f(Node* root , int target,int sum , int csum ,int &maxi ,bool flag){
// {
    
    if(root==NULL)
    {
        return ;
    }
     if(flag ==true)
    {
      
        csum+=root->data;
 
        
    }
          if(flag==false)
    sum+=root->data;
    if(root->data==target){
        // cout<<"e";
        flag=true;
        sum -=target;
        // cout<<sum;
        
    }
    if(root->left ==NULL && root->right==NULL)
    {
      
         if(flag==true)
         {
            //  cout<<sum<<" "<<csum;
             maxi=max(maxi, sum -csum);
            //  cout<<maxi<<"m";
         }
         return ;
    }
   

    
    
   
  f(root->left, target ,sum ,csum ,maxi ,flag);
  f(root->right,target ,sum ,csum ,maxi, flag);

}
        
    
//         if(root==NULL)
//         {
//             return ; 
//         }
//         if(root->data==target)
//         {
//             flag=true; 
        
//         }
        
//         if(flag)
//         {
//             csum+=root->data;
//              f(root->left, target ,sum ,csum ,maxi ,flag);
//   f(root->right,target ,sum ,csum ,maxi, flag);
//      if(root->left ==NULL && root->right==NULL)
//     {
//       csum-=target;
         
           
//              maxi=max(maxi, sum -csum);
         
         
//          return ;
//     }
//         }
//         else
//         {
//             sum+=root->data;
//               f(root->left, target ,sum ,csum ,maxi ,flag);
//   f(root->right,target ,sum ,csum ,maxi, flag);
//         }
        
    // } 
    int maxDifferenceBST(Node *root,int target){
       bool flag =false; 
      int maxi=INT_MIN;
      int sum =0;
      int csum =0;
  f(root,target,sum ,csum,maxi,flag);
       
         if(maxi==INT_MIN)
         return -1;
         else
        return maxi;
    
//     if(target<root->data)
//     {
//           f(root->left,target,sum ,csum,maxi,flag);
//     }
//     else if(target>root->data)
//     {
       
//           f(root->right,target,sum ,csum,maxi,flag);
//     }
//     else
//     {
//         if(root->data==target){
        
        
//       flag =true;
//   sum=0;
//           f(root->left,target,sum ,csum,maxi,flag);
//     sum=0;
//             f(root->right,target,sum ,csum,maxi,flag);
          
//              if(flag==true)
//     {
//          if(maxi==INT_MIN)
//          return 0 ;
//          else
//         return maxi;
//     }
//         }
//         else
//          return -1;
//     }

//     if(flag==true)
//     {
//          if(maxi==INT_MIN)
//          return 0 ;
//          else
//         return maxi;
//     }
//     else
//     return -1; 
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends