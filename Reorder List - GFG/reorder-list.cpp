//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

Node *reverse(Node *head){
   
   
   Node *dummy =NULL;
    Node *ptr;
     while(head!=NULL)
     {
         ptr=head->next;
         head->next=dummy;
          dummy=head;
           head=ptr;
     }
     return dummy;
     

}
Node* middle(Node *head)
{
    
    Node *slow =head; 
    Node *fast =head;
     while(fast!=NULL && fast->next!=NULL)
     {
         slow=slow->next;
         fast=fast->next->next;
         
     }
     return slow;
}

class Solution{ 
public:
    void reorderList(Node* head) {
         
        Node *ptr=head;
         Node *mid =middle(head);
         
         Node  *l1=head;
          Node *l2=mid->next ;
          mid->next=NULL;
           l2=reverse(l2);
           Node *ans =new Node(-1);
           Node *cur=ans;
           while(l1 || l2)
           {
               if(l1)
               {
                   
                 cur->next=l1 ;
                 cur=cur->next;
             l1=l1->next ;
                
                 
               }
               if(l2)
               {
                   cur->next=l2;
                    cur=cur->next;
                     l2=l2->next;
               }
           }
           head=ans->next;
         
    }
};

//{ Driver Code Starts.



/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }
        
        Solution ob;
        
        ob.reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}

// } Driver Code Ends