/*
Given two linked lists, your task is to complete the function makeUnion(), that returns the union of two linked lists. This union should include all the distinct elements only.

Example 1:

Input:
L1 = 9->6->4->2->3->8
L2 = 1->2->8->6->2
Output: 1 2 3 4 6 8 9
Your Task:
The task is to complete the function makeUnion() which makes the union of the given two lists and returns the head of the new list.

Note: The new list formed should be in non-decreasing order.

Expected Time Complexity: O(N * Log(N))
Expected Auxiliary Space: O(N)

Constraints:
1
*/

struct Node* makeUnion(struct Node* head1, struct Node* head2)
{
    set<int> s;
    Node* ptr1=head1;
    Node* ptr2=head2;
    
    while(ptr1!=NULL){
    s.insert(ptr1->data);
    ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
    s.insert(ptr2->data);
    ptr2=ptr2->next;
    }
    auto it=s.begin();
    Node* head=new Node(*it);
    Node* temp=head;
    it++;
    for ( ; it!=s.end(); it++){
    temp->next=new Node(*it);
    temp=temp->next;
    }
    return head;
}
