//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    Node *primeList(Node *head){
        int count =0 ;
        Node *ptr= head; 
        while(ptr!=NULL)
        {
            count++;
            ptr=ptr->next;
        }
       int N= count ;
       vector<bool > primes(1e5+5, true);
        for(long long i =2 ;i*i<=1e5;i++)
        {
            if(primes[i]==true){
            for(long long  j=i*i ;j<=1e5;j+=i)
            {
                 primes[j]=false;
            }
            }
        }
    vector<int > ans;
    for(int i =2; i<=1e5;i++)
    {
        if(primes[i])
        ans.push_back(i);
    }
    // for(int i =0; i < primes.size() ;i++)
    // {
    // cout<<ans[i]<<" ";
    // }
    Node *p=head;
    while(head!=NULL)
    {
     if(head->val==2 )
     {
         head=head->next;
     }
     else if(head->val==1)
     {
         head->val=2;
         head=head->next;
     }
     else if(primes[head->val])
     {
         head=head->next;
     }
     else
     {
         
        //  cout<<head->val<<" ";
         int a =upper_bound(ans.begin(), ans.end(), head->val)-ans.begin();
         int b=lower_bound(ans.begin(),ans.end(),head->val)-ans.begin();
       
      int ca =head->val-ans[b-1];
      int cb=ans[a]-head->val;
    //   cout<<ca<<" "<<cb<<ans[b-1]<<" "<<"     ";
      if(ca<=cb)
      {
          head->val=ans[b-1];
      }
      else
      head->val=ans[a];
         head=head->next;
     }
  
         
    }
       return p;
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends