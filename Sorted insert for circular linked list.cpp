/*
Given a sorted circular linked list, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

Example 1:

Input:
LinkedList = 1->2->4
(the first and last node is connected,
i.e. 4 --> 1)
data = 2
Output: 1 2 2 4
Example 2:

Input:
LinkedList = 1->4->7->9
(the first and last node is connected,
i.e. 9 --> 1)
data = 5
Output: 1 4 5 7 9
Your Task:
The task is to complete the function sortedInsert() which should insert the new node into the given circular linked list and return the head of the linkedlist.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
0 <= N <= 105
*/

class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
 
      Node* tail=head;
      Node* temp=head;
      Node* newnode=new Node(data);
      while(tail->next!=head){
          tail=tail->next;
          
      }
      
      if(newnode->data<=head->data){
          tail->next=newnode;
          newnode->next=head;
          return newnode;
      }
     while(temp->data<newnode->data && temp->next->data<newnode->data){
         if(temp==tail)
         break;
     
     temp=temp->next;    
         
         
     
     } 
     if(temp!=tail){
         newnode->next=temp->next;
         temp->next=newnode;
         return head;
     }
      if(temp==tail){
          temp->next=newnode;
          newnode->next=head;
          return head;
      }
    }
