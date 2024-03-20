#include <bits/stdc++.h>
using namespace std;

class Node
{
public: 
    int val;
    Node * next;
    
    Node()
    {
        this->val = 0;
        this->next = NULL;
    }
    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

Node * makeLinkedList(int n)
{
    Node * head = new Node();
    
    Node * tmp = head;
    
    int input;
    
    for(int i = 0 ; i < n ; ++i)
    {
        cin>>input;
        
        tmp->val = input;
        
        if(i!=n-1)
            tmp->next = new Node();
        tmp = tmp->next;
    }
    
    return head;
}

Node* GetMidNode(Node* head)
{
    if(head == NULL || head->next == NULL)
            return head;

    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}
void prl(Node* head)
{
    Node* tmp = head;
    
    while(tmp)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    
    Node* head = makeLinkedList(n);
    
    // Now we have a Linked List off size n Starting pointer at head
    cout<<"Input : "<<n<<endl;
    prl(head);
    
    Node * mid = GetMidNode(head);
    
    cout<<"Output : "<<mid->val;
    
}
