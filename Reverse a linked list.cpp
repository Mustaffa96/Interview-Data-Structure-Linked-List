/*
Given a linked list of N nodes. The task is to reverse this list.

Example 1:

Input:
LinkedList: 1->2->3->4->5->6
Output: 6 5 4 3 2 1
Explanation: After reversing the list, 
elements are 6->5->4->3->2->1.
Example 2:

Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.
Your Task:
The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 104
*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        Node *Prev,*Curr,*Next;
  		Prev=Next=NULL;
  		Curr=head;
  		if(head==NULL||head->next==NULL)
  		{
      		return head;
  		}
  		else
  		{
    		while(Curr->next!=NULL)
    		{
        		Next=Curr->next;
        		Curr->next=Prev;
        		Prev=Curr;
        		Curr=Next;
    		}
    		Curr->next=Prev;
    		head=Curr;
    		return head;
  		}
    }
