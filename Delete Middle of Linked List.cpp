/*
Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list is NULL or has 1 node, then it should return NULL

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 1 2 4 5
Example 2:

Input:
LinkedList: 2->4->6->7->5->1
Output: 2 4 6 5 1
Your Task:
The task is to complete the function deleteMid() which should delete the middle element from the linked list and return the head of the modified linked list. If the linked list is empty then it should return NULL.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 1000
1 <= value <= 1000
*/

Node* deleteMid(Node* head)
{
    if(head==NULL || head->next==NULL){return NULL;}  //when 0 or 1 elemrnts in linked list
    if(head->next->next==NULL){            //when 2 elements in linked list
        Node *temp=head->next;
        head->next=NULL;
        delete temp;
        return head;
    }
    Node *slow=head;
    Node *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node *temp=slow->next;
    slow->data=temp->data;
    slow->next=temp->next;
    delete temp;
    return head;
}
