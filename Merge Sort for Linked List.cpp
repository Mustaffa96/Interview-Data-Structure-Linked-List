/*
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Example 1:

Input:
N = 5
value[]  = {3,5,2,4,1}
Output: 1 2 3 4 5
Explanation: After sorting the given
linked list, the resultant matrix
will be 1->2->3->4->5.
Example 2:

Input:
N = 3
value[]  = {9,15,0}
Output: 0 9 15
Explanation: After sorting the given
linked list , resultant will be
0->9->15.
Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Expected Time Complexity: O(N*Log(N))
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 100
1 <= N <= 105
*/

class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    
     Node *merge(Node *l1, Node *l2){
        if(l1==NULL) return l2;
        if(l2==NULL)  return l1;
        
        if(l1->data > l2->data)   swap(l1,l2);
        
        Node *res=l1;
        
        while(l1!=NULL && l2 !=NULL){
            Node *temp=NULL;
            
            while(l1 != NULL && l1->data <= l2->data){
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return res;
    }    
    
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL)  return head;
        
        Node *temp=head;
        Node *slow=head;
        Node *fast=head;
        
        while(fast != NULL && fast->next != NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next = NULL;
        
        Node *left_side = mergeSort(head);
        Node *right_side = mergeSort(slow);
        
        return merge(left_side,right_side);
    }
};
